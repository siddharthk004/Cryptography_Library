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

    string plaintext = "HELLOHILLCIPHER";
    string cipher = hc.Encryption(plaintext);
    string decrypted = hc.Decryption(cipher);

    cout << "Plaintext : " << plaintext << endl;
    cout << "Ciphertext: " << cipher << endl;
    cout << "Decrypted : " << decrypted << endl;
    
    return 0;
}