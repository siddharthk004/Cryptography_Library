#include "Hill_Cipher.hpp"

HillCipher::HillCipher()
{
    vc.resize(3, vector<int>(3));
    vc2.resize(3, vector<int>(3));
    c1.resize(3, vector<int>(1));
    c2.resize(3, vector<int>(1));
    c3.resize(3, vector<int>(1));
}

void HillCipher::KeyForm()
{
    vc = {
        {6, 24, 1},
        {13, 16, 10},
        {20, 17, 15}};

    vc2 = {
        {8, 5, 10},
        {21, 8, 21},
        {21, 12, 8}};
}

string HillCipher::Encryption(string Ans)
{
    for (auto &ch : Ans)
    {
        ch = toupper(ch);
    }

    while (Ans.length() % 3 != 0)
    {
        Ans += 'X';
    }

    string ans = "";

    for (int i = 0; i < Ans.length(); i += 3)
    {
        for (int row = 0; row < 3; row++)
        {
            c1[row][0] = Ans[i + row] - 'A';
        }

        MatMulE();

        for (int row = 0; row < 3; row++)
        {
            ans += char((c2[row][0] % 26) + 'A');
        }
    }

    return ans;
}

void HillCipher::MatMulE()
{
    for (int i = 0; i < 3; i++)
    {
        int sum = 0;
        for (int j = 0; j < 3; j++)
        {
            sum += vc[i][j] * c1[j][0];
        }
        c2[i][0] = sum % 26;
    }
}

void HillCipher::MatMulD()
{
    for (int i = 0; i < 3; i++)
    {
        int sum = 0;
        for (int j = 0; j < 3; j++)
        {
            sum += vc2[i][j] * c2[j][0];
        }
        c3[i][0] = sum % 26;
    }
}

string HillCipher::Decryption(string Ans)
{
    while (Ans.length() % 3 != 0)
    {
        Ans += 'X';
    }

    string ans = "";

    for (int i = 0; i < Ans.length(); i += 3)
    {
        for (int row = 0; row < 3; row++)
        {

            c2[row][0] = Ans[i + row] - 'A';
        }
        MatMulD();

        for (int row = 0; row < 3; row++)
        {
            ans += tolower(char((c3[row][0] % 26) + 'A'));
        }
    }
    return ans;
}
