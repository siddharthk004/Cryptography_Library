#ifndef EL_GAMAL_HPP
#define EL_GAMAL_HPP

#include <NTL/ZZ.h>
#include <string>
#include<vector>

class ElGamal
{
private:
    NTL::ZZ p; 
    NTL::ZZ g; 
    NTL::ZZ x; 
    NTL::ZZ h; 

    NTL::ZZ modExp(const NTL::ZZ &base, const NTL::ZZ &exp, const NTL::ZZ &mod);
    NTL::ZZ modInverse(const NTL::ZZ &a, const NTL::ZZ &mod);

public:
    ElGamal(long prime);

    void generateKeys();
    void displayKeys() const;

    // encryption/decryption of one number
    void encrypt(const NTL::ZZ &m, NTL::ZZ &c1, NTL::ZZ &c2);
    NTL::ZZ decrypt(const NTL::ZZ &c1, const NTL::ZZ &c2);

    void encryptString(const std::string &msg,
                       std::vector<NTL::ZZ> &c1s,
                       std::vector<NTL::ZZ> &c2s);
    std::string decryptString(const std::vector<NTL::ZZ> &c1s,
                              const std::vector<NTL::ZZ> &c2s);

    void signMessage(const NTL::ZZ &m, NTL::ZZ &r, NTL::ZZ &s);
    bool verifyMessage(const NTL::ZZ &m, const NTL::ZZ &r, const NTL::ZZ &s);
};

#endif
