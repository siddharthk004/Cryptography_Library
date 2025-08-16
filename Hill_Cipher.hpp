#include<iostream>
#include<vector>
using namespace std;

class HillCipher
{
    public:
      vector<vector<int>> vc;
      vector<vector<int>> vc2;
      vector<vector<int>> c1;
      vector<vector<int>> c2;
      vector<vector<int>> c3;

      HillCipher();
      void KeyForm();
      string Encryption(string Ans);
      void MatMulE();
      void MatMulD();
      string Decryption(string Ans);
};