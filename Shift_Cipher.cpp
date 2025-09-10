#include<vector>
#include "Shift_Cipher.hpp"

Shift_Cipher::Shift_Cipher()
{}

string Shift_Cipher::Encryption(string Ans,string key)
{   
    string newString = "";
    int lengthKey = key.length();
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
        int num = int(key[i%lengthKey]);
        if(num > 96)
            len = (len + (num-97)) % 26;
        else
            len = (len + (num-65)) % 26;
        i++;
        
        len += flag==2 ? 65 : 97;
        
        ch = char(len);
        newString += ch;

    } 
    return newString;
}

string Shift_Cipher::Decryption(string Ans,string key)
{
    string newString = "";
    int lengthKey = key.length();
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
        int num = int(key[i%lengthKey]);
        if(num > 96)
            len = (len - (num-97) + 26) % 26;
        else
            len = (len - (num-65) + 26) % 26;
        i++;

        len += flag==2 ? 65 : 97;
        ch = char(len);
        newString += ch;

    } 
    return newString;

}
