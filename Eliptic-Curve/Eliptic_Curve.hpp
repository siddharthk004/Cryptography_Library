#ifndef E_C_HPP
#define E_C_HPP

#include <NTL/ZZ_p.h>
#include <string>
#include <vector>
#include <utility>
using namespace NTL;

struct ECPoint {
    ZZ_p x, y;
    bool infinity;

    ECPoint() : infinity(true) {}
    ECPoint(const ZZ_p &xVal, const ZZ_p &yVal) : x(xVal), y(yVal), infinity(false) {}
};

struct CompressedPoint {
    ZZ x;         
    bool y_is_odd; 
    bool infinity;

    CompressedPoint() : y_is_odd(false), infinity(true) {}
    CompressedPoint(const ZZ &xi, bool odd)
        : x(xi), y_is_odd(odd), infinity(false) {}
};

class ELCurve {
private:
    ZZ_p a, b;
    int p, q, d;

public:
    int n, e;
    ELCurve(const ZZ_p &A, const ZZ_p &B) : a(A), b(B) {}

    bool isValidPoint(const ECPoint &P) const;
    ECPoint pointAdd(const ECPoint &P, const ECPoint &Q) const;
    ECPoint pointDouble(const ECPoint &P) const;
    ECPoint scalarMultiply(const ECPoint &P, const ZZ &k) const;

    ECPoint generatePublicKey(const ECPoint &G, const ZZ &priv) const;
    std::pair<ECPoint, ECPoint> encrypt(const ECPoint &M, const ECPoint &G, const ECPoint &pubKey, const ZZ &k) const;
    ECPoint decrypt(const std::pair<ECPoint, ECPoint> &cipher, const ZZ &priv) const;

    std::pair<ZZ, ZZ> sign(const ZZ &msgHash, const ZZ &priv, const ECPoint &G, const ZZ &n) const;
    bool verify(const ZZ &msgHash, const std::pair<ZZ, ZZ> &sig, const ECPoint &G, const ECPoint &pubKey, const ZZ &n) const;

    void KeyGen(int p, int q) const;
    int Encrypt(int m) const;
    bool Decrypt(int c) const;

    CompressedPoint compressPoint(const ECPoint &P) const;
    ECPoint decompressPoint(const CompressedPoint &cp) const;
};

#endif
