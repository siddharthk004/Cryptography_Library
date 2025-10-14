#include "El_Gamal.hpp"
#include <NTL/ZZ.h>
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;
using namespace NTL;

ElGamal::ElGamal(long prime)
{
    p = conv<ZZ>(prime);
    g = ZZ(0);
    x = ZZ(0);
    h = ZZ(0);
    std::srand(static_cast<unsigned>(std::time(nullptr)));
}

ZZ ElGamal::modExp(const ZZ &base, const ZZ &exp, const ZZ &mod)
{
    return PowerMod(base, exp, mod);
}

ZZ ElGamal::modInverse(const ZZ &a, const ZZ &mod)
{
    return InvMod(a, mod);
}

void ElGamal::generateKeys()
{
    g = conv<ZZ>(2 + (std::rand() % (conv<long>(p) - 3)));
    x = conv<ZZ>(1 + (std::rand() % (conv<long>(p) - 1)));
    h = modExp(g, x, p);
}

void ElGamal::displayKeys() const
{
    cout << "\nPublic key: p = " << p << ", g = " << g << ", h = " << h << "\n";
    cout << "Private key x = " << x << "\n";
}

void ElGamal::encrypt(const ZZ &m, ZZ &c1, ZZ &c2)
{
    ZZ y = conv<ZZ>(1 + (std::rand() % (conv<long>(p) - 1)));
    ZZ s = modExp(h, y, p);
    c1 = modExp(g, y, p);
    c2 = (m * s) % p;
    cout << "Random y = " << y << "\n";
    cout << "Shared s = h^y mod p = " << s << "\n";
}

ZZ ElGamal::decrypt(const ZZ &c1, const ZZ &c2)
{
    ZZ s = modExp(c1, x, p);
    ZZ inv = modInverse(s, p);
    ZZ m = (c2 * inv) % p;
    return m;
}

void ElGamal::encryptString(const string &msg,
                            vector<ZZ> &c1s,
                            vector<ZZ> &c2s)
{
    c1s.clear();
    c2s.clear();
    for (char ch : msg)
    {
        ZZ m = conv<ZZ>(static_cast<int>(ch));
        ZZ c1, c2;
        encrypt(m, c1, c2);
        c1s.push_back(c1);
        c2s.push_back(c2);
    }
}

string ElGamal::decryptString(const vector<ZZ> &c1s,const vector<ZZ> &c2s)
{
    string res;
    for (size_t i = 0; i < c1s.size(); ++i)
    {
        ZZ m = decrypt(c1s[i], c2s[i]);
        long val = conv<long>(m) % 256; 
        res.push_back(static_cast<char>(val));
    }
    return res;
}


void ElGamal::signMessage(const ZZ &m, ZZ &r, ZZ &s)
{
    // choose random k coprime with p-1
    ZZ k;
    ZZ p1 = p - 1;
    do
    {
        k = conv<ZZ>(1 + (std::rand() % (conv<long>(p1))));
    } while (GCD(k, p1) != 1);

    r = modExp(g, k, p);
    ZZ kInv = modInverse(k, p1);
    s = (kInv * (m - x * r)) % p1;
    if (s < 0)
        s += p1;
    }

bool ElGamal::verifyMessage(const ZZ &m, const ZZ &r, const ZZ &s)
{
    if (r <= 0 || r >= p)
        return false;
    ZZ left = (modExp(h, r, p) * modExp(r, s, p)) % p;
    ZZ right = modExp(g, m, p);
    return left == right;
}
