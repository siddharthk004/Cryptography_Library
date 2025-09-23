#ifndef ELGAMAL_HPP
#define ELGAMAL_HPP

class ElGamal
{
private:
    int p;
    int g;
    int x;
    int h;

    int modExp(int base, int exp, int mod);

    int modInverse(int a, int mod);

public:
    ElGamal(int prime);

    void generateKeys();
    void encrypt(int m, int &c1, int &c2);
    int decrypt(int c1, int c2);
    void displayKeys() const;
};

#endif
