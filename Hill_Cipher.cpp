#include "Hill_Cipher.hpp"
#include <NTL/mat_ZZ.h>
#include <NTL/ZZ.h>
#include <cstdlib>
#include <ctime>

using namespace std;
using namespace NTL;

HillCipher::HillCipher()
{
    vc.resize(3, vector<int>(3));
    vc2.resize(3, vector<int>(3));
    c1.resize(3, vector<int>(1));
    c2.resize(3, vector<int>(1));
    c3.resize(3, vector<int>(1));
}

void HillCipher::adjoint3x3(int adj[3][3], int m[3][3])
{
    adj[0][0] = (m[1][1]*m[2][2] - m[1][2]*m[2][1]);
    adj[0][1] = -(m[0][1]*m[2][2] - m[0][2]*m[2][1]);
    adj[0][2] = (m[0][1]*m[1][2] - m[0][2]*m[1][1]);

    adj[1][0] = -(m[1][0]*m[2][2] - m[1][2]*m[2][0]);
    adj[1][1] = (m[0][0]*m[2][2] - m[0][2]*m[2][0]);
    adj[1][2] = -(m[0][0]*m[1][2] - m[0][2]*m[1][0]);

    adj[2][0] = (m[1][0]*m[2][1] - m[1][1]*m[2][0]);
    adj[2][1] = -(m[0][0]*m[2][1] - m[0][1]*m[2][0]);
    adj[2][2] = (m[0][0]*m[1][1] - m[0][1]*m[1][0]);
}

void HillCipher::GenerateRandomKey()
{
    while (true)
    {
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                vc[i][j] = rand() % 26;

        mat_ZZ M;
        M.SetDims(3, 3);
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                M[i][j] = vc[i][j];

        ZZ detZZ = determinant(M);
        long d = conv<long>(detZZ % 26);
        if (d < 0) d += 26;

        if (GCD(ZZ(d), ZZ(26)) == 1)
        {
            int m[3][3], adj[3][3];
            for (int i = 0; i < 3; i++)
                for (int j = 0; j < 3; j++)
                    m[i][j] = vc[i][j];
            adjoint3x3(adj, m);

            long det_inv = InvMod(d, 26);

            for (int i = 0; i < 3; i++)
                for (int j = 0; j < 3; j++)
                {
                    long val = adj[i][j] % 26;
                    if (val < 0) val += 26;
                    val = (val * det_inv) % 26;
                    vc2[i][j] = (int)val;
                }

            break; 
        }
    }
}

string HillCipher::Encryption(string Ans)
{
    for (auto &ch : Ans)
        ch = toupper(ch);

    while (Ans.length() % 3 != 0)
        Ans += 'X';

    string ans;
    for (size_t i = 0; i < Ans.length(); i += 3)
    {
        for (int row = 0; row < 3; row++)
            c1[row][0] = Ans[i + row] - 'A';

        MatMulE();

        for (int row = 0; row < 3; row++)
            ans += char((c2[row][0] % 26) + 'A');
    }
    return ans;
}

void HillCipher::MatMulE()
{
    for (int i = 0; i < 3; i++)
    {
        int sum = 0;
        for (int j = 0; j < 3; j++)
            sum += vc[i][j] * c1[j][0];
        c2[i][0] = sum % 26;
    }
}

void HillCipher::MatMulD()
{
    for (int i = 0; i < 3; i++)
    {
        int sum = 0;
        for (int j = 0; j < 3; j++)
            sum += vc2[i][j] * c2[j][0];
        c3[i][0] = sum % 26;
    }
}

string HillCipher::Decryption(string Ans)
{
    while (Ans.length() % 3 != 0)
        Ans += 'X';

    string ans;
    for (size_t i = 0; i < Ans.length(); i += 3)
    {
        for (int row = 0; row < 3; row++)
            c2[row][0] = Ans[i + row] - 'A';

        MatMulD();

        for (int row = 0; row < 3; row++)
            ans += tolower(char((c3[row][0] % 26) + 'A'));
    }
    return ans;
}
