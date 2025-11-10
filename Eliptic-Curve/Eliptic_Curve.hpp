#ifndef E_C_HPP
#define E_C_HPP

#include <NTL/ZZ_p.h>
#include <string>
#include <vector>
using namespace NTL;

struct ECPoint
{
    ZZ_p x, y;
    bool infinity;

    ECPoint() : infinity(true) {}
    ECPoint(const ZZ_p &xVal, const ZZ_p &yVal) : x(xVal), y(yVal), infinity(false) {}
};

class ELCurve
{
private:
    ZZ_p a, b; // Curve: y^2 = x^3 + a*x + b
    int p,q,d;


public:
    int n,e;
    ELCurve(const ZZ_p &A, const ZZ_p &B) : a(A), b(B) {}

    bool isValidPoint(const ECPoint &P) const;
    ECPoint pointAdd(const ECPoint &P, const ECPoint &Q) const;
    ECPoint pointDouble(const ECPoint &P) const;
    ECPoint scalarMultiply(const ECPoint &P, const ZZ &k) const;

    // --- ElGamal over EC ---
    ECPoint generatePublicKey(const ECPoint &G, const ZZ &priv) const;
    std::pair<ECPoint, ECPoint> encrypt(const ECPoint &M, const ECPoint &G, const ECPoint &pubKey, const ZZ &k) const;
    ECPoint decrypt(const std::pair<ECPoint, ECPoint> &cipher, const ZZ &priv) const;

    // --- Digital Signature ---
    std::pair<ZZ, ZZ> sign(const ZZ &msgHash, const ZZ &priv, const ECPoint &G, const ZZ &n) const;
    bool verify(const ZZ &msgHash, const std::pair<ZZ, ZZ> &sig, const ECPoint &G, const ECPoint &pubKey, const ZZ &n) const;

    // Eliptic Curve Over Integrated + Point Compression 
    void KeyGen(int p,int q) const;
    int Encrypt(int m) const;
    bool Decrypt(int c) const;
};

#endif
