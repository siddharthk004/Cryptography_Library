#include<iostream>
using namespace std;

class Shift_Cipher
{
    public:

      Shift_Cipher();
      string Encryption(string Ans,int key);
      string Decryption(string Ans,int key);
};