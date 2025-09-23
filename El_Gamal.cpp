#include "El_Gamal.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

ElGamal::ElGamal(int prime) : p(prime), g(0), x(0), h(0)
{
    std::srand(static_cast<unsigned>(std::time(nullptr)));
}

int ElGamal::modExp(int base, int exp, int mod)
{
    int result = 1;
    base %= mod;
    while (exp > 0)
    {
        if (exp & 1)
            result = (result * base) % mod;
        exp >>= 1;
        base = (base * base) % mod;
    }
    return result;
}

int ElGamal::modInverse(int a, int mod)
{
    int m0 = mod, t, q;
    int x0 = 0, x1 = 1;
    if (mod == 1)
        return 0;
    while (a > 1)
    {
        q = a / mod;
        t = mod;
        mod = a % mod;
        a = t;
        t = x0;
        x0 = x1 - q * x0;
        x1 = t;
    }
    if (x1 < 0)
        x1 += m0;
    return x1;
}

void ElGamal::generateKeys()
{
    g = 2 + (std::rand() % (p - 3));
    x = 1 + (std::rand() % (p - 1));
    h = modExp(g, x, p);
}

void ElGamal::encrypt(int m, int &c1, int &c2)
{
    int y = 1 + (std::rand() % (p - 1));
    int s = modExp(h, y, p);
    c1 = modExp(g, y, p);
    c2 = (m * s) % p;
    std::cout << "Random y = " << y << "\n";
    std::cout << "Shared s = h^y mod p = " << s << "\n";
}

int ElGamal::decrypt(int c1, int c2)
{
    int s = modExp(c1, x, p);
    int inv = modInverse(s, p);
    int m = (c2 * inv) % p;
    return m;
}

void ElGamal::displayKeys() const
{
    std::cout << "Public key: p = " << p << ", g = " << g << ", h = " << h << "\n";
    std::cout << "Private key x = " << x << "\n";
}
