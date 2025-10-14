#ifndef ELIPTIC_CURVE_HPP
#define ELIPTIC_CURVE_HPP

#include <NTL/ZZ_p.h>
#include <iostream>
using namespace NTL;
using namespace std;

// ECPoint definition first
struct ECPoint
{
    ZZ_p x;
    ZZ_p y;
    bool infinity;

    ECPoint() : infinity(true) {}
    ECPoint(const ZZ_p &xVal, const ZZ_p &yVal) : x(xVal), y(yVal), infinity(false) {}
};

// Elliptic Curve class
class ELCurve
{
private:
    ZZ_p a;
    ZZ_p b;

public:
    ELCurve(const ZZ &prime, const ZZ &A, const ZZ &B)
    {
        ZZ_p::init(prime);
        a = to_ZZ_p(A);
        b = to_ZZ_p(B);
    }

    bool isValidPoint(const ECPoint &P) const
    {
        if (P.infinity)
            return true;
        return sqr(P.y) == power(P.x, 3) + a * P.x + b;
    }

    ECPoint pointAdd(const ECPoint &P, const ECPoint &Q) const;
    ECPoint pointDouble(const ECPoint &P) const;
    ECPoint scalarMultiply(const ECPoint &P, const ZZ &k) const;
    
};

#endif



















































    // pair<ECPoint, ZZ> EC_ElGamal_KeyGen(const ELCurve &curve, const ECPoint &G);
    // pair<ECPoint, ECPoint> EC_ElGamal_Encrypt(const ELCurve &curve, const ECPoint &G, const ECPoint &Q, const ECPoint &M, const ZZ &k);
    // ECPoint EC_ElGamal_Decrypt(const ELCurve &curve, const ZZ &d, const std::pair<ECPoint, ECPoint> &cipher);
    // std::pair<ZZ, ZZ> EC_ElGamal_Sign(const ELCurve &curve, const ECPoint &G, const ZZ &d, const ZZ &h, const ZZ &k);
    // bool EC_ElGamal_Verify(const ELCurve &curve, const ECPoint &G, const ECPoint &Q, const std::pair<ZZ, ZZ> &sig, const ZZ &h);