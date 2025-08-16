#include<vector>
#include "Shift_Cipher.hpp"

Shift_Cipher::Shift_Cipher()
{}

string Shift_Cipher::Encryption(string Ans,int key)
{   
    string newString = "";
    int lengthAns = Ans.length();
    int flag = 0,i = 0;

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

        if(len > 96)
            len = (len + (key)) % 26;
        else
            len = (len + (key)) % 26;
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

string Shift_Cipher::Decryption(string Ans,int key)
{
    string newString = "";
    int lengthAns = Ans.length();
    int flag = 0,i = 0;

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
        if(key > 96)
            len = (len - (key) + 26) % 26;
        else
            len = (len - (key) + 26) % 26;
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
