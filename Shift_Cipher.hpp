#ifndef SHIFT_CIPHER_HPP
#define SHIFT_CIPHER_HPP

#include<iostream>
using namespace std;

class Shift_Cipher
{
    public:

      Shift_Cipher();
      string Encryption(string Ans,string key);
      string Decryption(string Ans,string key);
};

#endif