#include "Diffe_Hellman.hpp"
#include <NTL/ZZ.h>
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;
using namespace NTL;

DiffieHellman::DiffieHellman(long prime)
{
    p = conv<ZZ>(prime);
    g = ZZ(0);
    a = ZZ(0);
    b = ZZ(0);
    A = ZZ(0);
    B = ZZ(0);
    sharedAlice = ZZ(0);
    sharedBob = ZZ(0);
    std::srand(static_cast<unsigned>(std::time(nullptr)));
}

ZZ DiffieHellman::modExp(const ZZ &base, const ZZ &exp, const ZZ &mod)
{
    return PowerMod(base, exp, mod);
}

void DiffieHellman::generateValues()
{
    g = conv<ZZ>(1 + (std::rand() % (conv<long>(p) - 1)));
    a = conv<ZZ>(1 + (std::rand() % (conv<long>(p) - 1)));
    b = conv<ZZ>(1 + (std::rand() % (conv<long>(p) - 1)));
}

void DiffieHellman::computePublicKeys()
{
    A = modExp(g, a, p);
    B = modExp(g, b, p);
}

void DiffieHellman::computeSharedKeys()
{
    sharedAlice = modExp(B, a, p);
    sharedBob = modExp(A, b, p);
}

void DiffieHellman::display() const
{
    cout << "\np (prime modulus) = " << p << "\n";
    cout << "g (generator)     = " << g << "\n";
    cout << "Alice private a   = " << a << "\n";
    cout << "Bob private b     = " << b << "\n";
    cout << "Alice public A    = g^a mod p = " << A << "\n";
    cout << "Bob public B      = g^b mod p = " << B << "\n";
    cout << "Alice shared key  = B^a mod p = " << sharedAlice << "\n";
    cout << "Bob shared key    = A^b mod p = " << sharedBob << "\n";
    if (sharedAlice == sharedBob)
        cout << "Shared secrets match!\n";
    else
        cout << "Shared secrets differ!\n";
}
