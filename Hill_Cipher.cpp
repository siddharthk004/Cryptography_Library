#include "Hill_Cipher.hpp"

HillCipher::HillCipher()
{
    vc.resize(3, vector<int>(3));
    vc2.resize(3, vector<int>(3));
    c1.resize(3, vector<int>(1));
    c2.resize(3, vector<int>(1));
    c3.resize(3, vector<int>(1));
}

void HillCipher::GenerateRandomKey()
{
    // repeatedly generate random matrices until invertible mod 26
    while (true)
    {
        // generate random 3x3 matrix in [0,25]
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                vc[i][j] = rand() % 26;

        // convert to NTL mat_ZZ for determinant and inverse
        mat_ZZ M;
        M.SetDims(3, 3);
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                M[i][j] = vc[i][j];

        ZZ det = determinant(M);

        long d = conv<long>(det % 26); // determinant mod 26
        if (d < 0)
            d += 26;

        // check gcd(det,26)==1 (invertible mod 26)
        if (GCD(ZZ(d), ZZ(26)) == 1)
        {
            // compute inverse matrix modulo 26
            mat_ZZ Adj;
            adjoint(Adj, M); // classical adjoint

            // find modular inverse of det
            long det_inv;
            InvMod(det_inv, d, 26); // NTL modular inverse

            // build inverse matrix vc2 = det_inv * Adj mod 26
            for (int i = 0; i < 3; i++)
                for (int j = 0; j < 3; j++)
                {
                    long val = conv<long>(Adj[i][j] % 26);
                    if (val < 0)
                        val += 26;
                    val = (val * det_inv) % 26;
                    vc2[i][j] = val;
                }

            break; // we have good keys
        }
    }
}

string HillCipher::Encryption(string Ans)
{
    for (auto &ch : Ans)
        ch = toupper(ch);

    while (Ans.length() % 3 != 0)
        Ans += 'X';

    string ans = "";

    for (int i = 0; i < (int)Ans.length(); i += 3)
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

    string ans = "";

    for (int i = 0; i < (int)Ans.length(); i += 3)
    {
        for (int row = 0; row < 3; row++)
            c2[row][0] = Ans[i + row] - 'A';

        MatMulD();

        for (int row = 0; row < 3; row++)
            ans += tolower(char((c3[row][0] % 26) + 'A'));
    }
    return ans;
}
