#include<iostream>
using namespace std;
#include "Vigenere_Cipher.hpp"
#include "Hill_Cipher.hpp"
#include "Shift_Cipher.hpp"
#include "OneTimePad.hpp"

int main()
{
    cout<<"hello World";
    string ans = "siddharth";
    string ans2 = "hrferdfhgfde";
    string ans3 = "";
    cout<<"\n"<<ans;

    // Shift Cipher
    cout<<"\n\n --- Shift Cipher --- ";
    Shift_Cipher sc;
    char AD = char(69);
    string a = "";
    a += AD;
    cout<<"\nORG - "<<ans;
    ans3 = sc.Encryption(ans,a);
    cout<<"\nENC - "<<ans3;
    ans = sc.Decryption(ans3,a);
    cout<<"\nDEC - "<<ans;

    // Vigenere Cipher
    cout<<"\n\n --- Vigenere Cipher --- ";
    Vigenere_Cipher v;
    cout<<"\nORG - "<<ans;
    ans3 = v.Encryption(ans,ans2);
    cout<<"\nENC - "<<ans3;
    ans3 = v.Decryption(ans3,ans2);    
    cout<<"\nDEC - "<<ans3;

    //Hill Cipher
    cout<<"\n\n --- Hill Cipher ---";
    HillCipher hc;
    hc.GenerateRandomKey();
    cout<<"\nORG - "<<ans;
    ans3 = hc.Encryption(ans);
    cout<<"\nENC - "<<ans3;
    ans3 = hc.Decryption(ans3);
    cout<<"\nDEC - "<<ans3;

    //One Time Pad
    cout<<"\n\n --- One Time Pad ---";
    OneTimePad otp;
    string key = otp.generateKey(ans.size());
    cout<<"\nORG - "<<ans;
    ans3 = otp.encrypt(ans);
    cout<<"\nENC - "<<ans3;
    ans3 = otp.decrypt(ans3);
    cout<<"\nDEC - "<<ans3;

    return 0;
}

// g++ AppliedCrypto.cpp Hill_Cipher.cpp Shift_Cipher.cpp Vigenere_Cipher.cpp OneTimePad.cpp -o Myexe -lntl -lgmp -lm -mconsole
// ./Myexe