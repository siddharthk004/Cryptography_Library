#include "Eliptic_Curve.hpp"
#include <NTL/ZZ_p.h>
#include <NTL/ZZ.h>
#include <iostream>
using namespace std;
using namespace NTL;

bool ELCurve::isValidPoint(const ECPoint &P) const {
    if (P.infinity)
        return true;
    return sqr(P.y) == power(P.x, 3) + a * P.x + b;
}

ECPoint ELCurve::pointAdd(const ECPoint &P, const ECPoint &Q) const {
    if (P.infinity)
        return Q;
    if (Q.infinity)
        return P;
    if (P.x == Q.x && P.y == -Q.y)
        return ECPoint();

    ZZ_p lambda;
    if (P.x != Q.x)
        lambda = (Q.y - P.y) / (Q.x - P.x);
    else
        lambda = (3 * sqr(P.x) + a) / (2 * P.y);

    ZZ_p x3 = sqr(lambda) - P.x - Q.x;
    ZZ_p y3 = lambda * (P.x - x3) - P.y;
    return ECPoint(x3, y3);
}

ECPoint ELCurve::pointDouble(const ECPoint &P) const {
    if (P.infinity)
        return P;

    ZZ_p lambda = (3 * sqr(P.x) + a) / (2 * P.y);
    ZZ_p x3 = sqr(lambda) - 2 * P.x;
    ZZ_p y3 = lambda * (P.x - x3) - P.y;
    return ECPoint(x3, y3);
}

ECPoint ELCurve::scalarMultiply(const ECPoint &P, const ZZ &k) const {
    ECPoint R;
    ECPoint Q = P;
    ZZ n = k;

    while (n > 0) {
        if (bit(n, 0))
            R = pointAdd(R, Q);
        Q = pointDouble(Q);
        n >>= 1;
    }
    return R;
}

ECPoint ELCurve::generatePublicKey(const ECPoint &G, const ZZ &priv) const {
    return scalarMultiply(G, priv);
}

pair<ECPoint, ECPoint> ELCurve::encrypt(const ECPoint &M, const ECPoint &G, const ECPoint &pubKey, const ZZ &k) const {
    ECPoint C1 = scalarMultiply(G, k);
    ECPoint kPB = scalarMultiply(pubKey, k);
    ECPoint C2 = pointAdd(M, kPB);
    return {C1, C2};
}

ECPoint ELCurve::decrypt(const pair<ECPoint, ECPoint> &cipher, const ZZ &priv) const {
    ECPoint C1 = cipher.first;
    ECPoint C2 = cipher.second;
    ECPoint dC1 = scalarMultiply(C1, priv);
    ECPoint neg_dC1(dC1.x, -dC1.y);
    return pointAdd(C2, neg_dC1);
}

pair<ZZ, ZZ> ELCurve::sign(const ZZ &msgHash, const ZZ &priv, const ECPoint &G, const ZZ &n) const {
    ZZ k, r, s;
    do {
        RandomBnd(k, n - 1);
        ECPoint R = scalarMultiply(G, k);
        r = rep(R.x) % n;
    } while (r == 0);

    ZZ kinv = InvMod(k, n);
    s = (kinv * (msgHash + priv * r)) % n;
    return {r, s};
}

bool ELCurve::verify(const ZZ &msgHash, const pair<ZZ, ZZ> &sig, const ECPoint &G, const ECPoint &pubKey, const ZZ &n) const {
    ZZ r = sig.first, s = sig.second;
    if (r <= 0 || r >= n || s <= 0 || s >= n)
        return false;

    ZZ w = InvMod(s, n);
    ZZ u1 = (msgHash * w) % n;
    ZZ u2 = (r * w) % n;

    ECPoint P1 = scalarMultiply(G, u1);
    ECPoint P2 = scalarMultiply(pubKey, u2);
    ECPoint X = pointAdd(P1, P2);

    ZZ v = rep(X.x) % n;
    return v == r;
}

void ELCurve::KeyGen(int p, int q) const {
    ZZ n = conv<ZZ>(p) * conv<ZZ>(q);
    ZZ phi = conv<ZZ>((p - 1) * (q - 1));
    ZZ e = conv<ZZ>(5);
    ZZ d = InvMod(e, phi);
}


int ELCurve::Encrypt(int m) const {
    cout << "(RSA-like Encrypt not implemented yet)\n";
    return m;
}

bool ELCurve::Decrypt(int c) const {
    cout << "(RSA-like Decrypt not implemented yet)\n";
    return true;
}

static bool mod_sqrt(ZZ &root, const ZZ &a, const ZZ &p) {
    if (IsZero(a)) { root = ZZ(0); return true; }
    if (Jacobi(a, p) != 1) return false;
    if (p % 4 == 3) {
        root = PowerMod(a, (p + 1) / 4, p);
        return true;
    }
    try {
        root = SqrRootMod(a, p);
        return true;
    } catch (...) {
        return false;
    }
}

CompressedPoint ELCurve::compressPoint(const ECPoint &P) const {
    if (P.infinity) return CompressedPoint();
    ZZ xZZ = rep(P.x);
    ZZ yZZ = rep(P.y);
    bool odd = IsOdd(yZZ);
    return CompressedPoint(xZZ, odd);
}

ECPoint ELCurve::decompressPoint(const CompressedPoint &cp) const {
    if (cp.infinity) return ECPoint();
    ZZ p = ZZ_p::modulus();
    ZZ xZZ = cp.x % p; if (xZZ < 0) xZZ += p;
    ZZ_p x = to_ZZ_p(xZZ);

    ZZ_p rhs = power(x, 3) + a * x + b;
    ZZ rhsZZ = rep(rhs) % p; if (rhsZZ < 0) rhsZZ += p;

    ZZ yZZ;
    if (!mod_sqrt(yZZ, rhsZZ, p)) return ECPoint();

    if (IsOdd(yZZ) != cp.y_is_odd)
        yZZ = (p - yZZ) % p;

    ZZ_p y = to_ZZ_p(yZZ);
    return ECPoint(x, y);
}
