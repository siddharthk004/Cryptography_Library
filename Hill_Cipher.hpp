#ifndef HILL_CIPHER_HPP
#define HILL_CIPHER_HPP

#include <bits/stdc++.h>
#include <NTL/mat_ZZ.h>
#include <NTL/ZZ.h>
using namespace std;
using namespace NTL;

class HillCipher
{
private:
    vector<vector<int>> vc;   // encryption key
    vector<vector<int>> vc2;  // decryption key (inverse)
    vector<vector<int>> c1;
    vector<vector<int>> c2;
    vector<vector<int>> c3;

public:
    HillCipher();

    void GenerateRandomKey();        // random 3x3 key
    string Encryption(string Ans);   // encrypt
    string Decryption(string Ans);   // decrypt

private:
    void MatMulE();
    void MatMulD();
};

#endif
