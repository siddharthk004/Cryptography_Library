#include "Eliptic_Curve.hpp"

ECPoint ELCurve::pointAdd(const ECPoint &P, const ECPoint &Q) const
{
    if (P.infinity)
        return Q;
    if (Q.infinity)
        return P;

    if (P.x == Q.x && P.y == -Q.y)
        return ECPoint();

    ZZ_p lambda;
    if (P.x != Q.x)
    {
        lambda = (Q.y - P.y) / (Q.x - P.x);
    }
    else
    {
        ZZ_p lambda = (3 * sqr(P.x) + a) / (2 * P.y);
    }

    ZZ_p x3 = sqr(lambda) - P.x - Q.x;
    ZZ_p y3 = lambda * (P.x - x3) - P.y;

    return ECPoint(x3, y3);
}

ECPoint ELCurve::pointDouble(const ECPoint &P) const
{
    if (P.infinity)
        return P;

    ZZ_p lambda = (3 * sqr(P.x) + a) / (2 * P.y);
    ZZ_p x3 = sqr(lambda) - 2 * P.x;
    ZZ_p y3 = lambda * (P.x - x3) - P.y;

    return ECPoint(x3, y3);
}

ECPoint ELCurve::scalarMultiply(const ECPoint &P, const ZZ &k) const
{
    ECPoint R;
    ECPoint Q = P;
    ZZ n = k;

    while (n > 0)
    {
        if (bit(n, 0))
        {
            R = pointAdd(R, Q);
        }
        Q = pointDouble(Q);
        n >>= 1;
    }

    return R;
}