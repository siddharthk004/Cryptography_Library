#include "Diffe_Hellman.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

DiffieHellman::DiffieHellman(int prime)
{
    p = prime;
    g = 0;
    a = 0;
    b = 0;
    A = 0;
    B = 0;
    sharedAlice = 0;
    sharedBob = 0;
    std::srand(static_cast<unsigned>(std::time(nullptr)));
}

int DiffieHellman::modExp(int base, int exp, int mod)
{
    int result = 1;
    base = base % mod;
    while (exp > 0)
    {
        if (exp & 1)
            result = (result * base) % mod;
        exp >>= 1;
        base = (base * base) % mod;
    }
    return result;
}

void DiffieHellman::generateValues()
{
    g = 1 + (std::rand() % (p - 1));
    a = 1 + (std::rand() % (p - 1));
    b = 1 + (std::rand() % (p - 1));
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

void DiffieHellman::display() 
{
    std::cout << "p (prime modulus) = " << p << "\n";
    std::cout << "g (generator)     = " << g << "\n";
    std::cout << "Alice private a   = " << a << "\n";
    std::cout << "Bob private b     = " << b << "\n";
    std::cout << "Alice public A    = g^a mod p = " << A << "\n";
    std::cout << "Bob public B      = g^b mod p = " << B << "\n";
    std::cout << "Alice shared key  = B^a mod p = " << sharedAlice << "\n";
    std::cout << "Bob shared key    = A^b mod p = " << sharedBob << "\n";
    if (sharedAlice == sharedBob)
        std::cout << "Shared secrets match!\n";
    else
        std::cout << "Shared secrets differ!\n";
}
