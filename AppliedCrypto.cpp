#include<iostream>
using namespace std;
#include "Vigenere_Cipher.hpp"
#include "Hill_Cipher.hpp"
#include "Shift_Cipher.hpp"

int main()
{
    cout<<"hello World";
    string ans = "siddharth";
    string ans2 = "hrferdfhgfde";
    string ans3 = "";
    cout<<"\n"<<ans;

    // Vigenere Cipher
    Vigenere_Cipher v;
    ans3 = v.Encryption(ans,ans2);
    cout<<"\n"<<ans3;
    ans3 = v.Decryption(ans3,ans2);
    cout<<"\n"<<ans3;

    //Hill Cipher
    HillCipher hc;
    hc.KeyForm();
    ans3 = hc.Encryption(ans);
    cout<<"\n"<<ans3;
    ans = hc.Decryption(ans3);
    cout<<"\n"<<ans;

    // Shift Cipher
    cout<<"\n"<<ans;
    Shift_Cipher sc;
    ans3 = sc.Encryption(ans,5);
    cout<<"\n"<<ans3;
    ans = sc.Decryption(ans3,5);
    cout<<"\n"<<ans;

    
    return 0;
}