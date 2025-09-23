#include<iostream>
using namespace std;
#include "Vigenere_Cipher.hpp"
#include "Hill_Cipher.hpp"
#include "Shift_Cipher.hpp"
#include "OneTimePad.hpp"
#include "Diffe_Hellman.hpp"
#include "El_Gamal.hpp"

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

    // Diffie Hellman
    DiffieHellman dh(15); // p = 15
    cout<<"\n\n --- Diffie Hellman ---";
    dh.generateValues();
    dh.computePublicKeys();
    dh.computeSharedKeys();
    dh.display();

    // El Gamal
    cout<<"\n\n --- El Gamal ---\n";
    ElGamal eg(29); 
    eg.generateKeys();
    eg.displayKeys();
    int m;
    std::cout << "Enter a message number (1..28): ";
    std::cin >> m;
    int c1, c2;
    eg.encrypt(m, c1, c2);
    std::cout << "Ciphertext: c1 = " << c1 << ", c2 = " << c2 << "\n";
    int decrypted = eg.decrypt(c1, c2);
    std::cout << "Decrypted message = " << decrypted << "\n";

    return 0;
}

// g++ AppliedCrypto.cpp Hill_Cipher.cpp Shift_Cipher.cpp Vigenere_Cipher.cpp OneTimePad.cpp -o Myexe -lntl -lgmp -lm -mconsole
// ./Myexe