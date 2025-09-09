#include<vector>
#include "Vigenere_Cipher.hpp"

Vigenere_Cipher::Vigenere_Cipher()
{}

string Vigenere_Cipher::Encryption(string Ans,string key)
{   
    string newString = "";
    int lengthKey = key.length();
    int lengthAns = Ans.length();
    int flag = 0,i = 0;

    vector<int> vc;
    while(i < lengthAns)
    {
        char c = key[i%lengthKey];
        vc.push_back(int(c));
        i++;
    }
    i = 0;
    flag = 0;
    for(char ch : Ans)
    {
        int len = int(ch);
        if(len > 96)
        {
            len -= 97;
            flag = 1;
        }
        else 
        {
            len -= 65;
            flag = 2;
        }
        if(vc[i] > 96)
            len = (len + (vc[i]-97)) % 26;
        else
            len = (len + (vc[i]-65)) % 26;
        i++;


        if(flag == 2)
            len += 65;
        else
            len += 97;

        
        ch = char(len);
        newString += ch;

    } 
    return newString;
}

string Vigenere_Cipher::Decryption(string Ans,string key)
{
    string newString = "";
    int lengthKey = key.length();
    int lengthAns = Ans.length();
    int flag = 0,i = 0;

    vector<int> vc;
    while(i < lengthAns)
    {
        char c = key[i%lengthKey];
        vc.push_back(int(c));
        i++;
    }
    i = 0;
    flag = 0;
    for(char ch : Ans)
    {
        int len = int(ch);
        if(len > 96)
        {
            len -= 97;
            flag = 1;
        }
        else
        {
            len -= 65;
            flag = 2;
        }
        if(vc[i] > 96)
            len = (len - (vc[i]-97) + 26) % 26;
        else
            len = (len - (vc[i]-65) + 26) % 26;
        i++;


        if(flag == 2)
            len += 65;
        else
            len += 97;

        
        ch = char(len);
        newString += ch;

    } 
    return newString;

}
