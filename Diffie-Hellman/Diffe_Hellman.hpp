#ifndef DIFFE_HELLMAN_HPP
#define DIFFE_HELLMAN_HPP

#include <NTL/ZZ.h>

class DiffieHellman
{
private:
    NTL::ZZ p;
    NTL::ZZ g;
    NTL::ZZ a, b;
    NTL::ZZ A, B;
    NTL::ZZ sharedAlice, sharedBob;

    NTL::ZZ modExp(const NTL::ZZ &base, const NTL::ZZ &exp, const NTL::ZZ &mod);

public:
    DiffieHellman(long prime);

    void generateValues();
    void computePublicKeys();
    void computeSharedKeys();
    void display() const;
};

#endif
