#include <iostream>
#include "Vigenere-Cipher/Vigenere_Cipher.hpp"
#include "Hill-Cipher/Hill_Cipher.hpp"
#include "Shift/Shift_Cipher.hpp"
#include "OTP/OneTimePad.hpp"
#include "Diffie-Hellman/Diffe_Hellman.hpp"
#include <NTL/ZZ.h>
#include <NTL/ZZ_p.h>
#include "El-Gamal/El_Gamal.hpp"
#include "Eliptic-Curve/Eliptic_Curve.hpp"

using namespace std;
using namespace NTL;
int main()
{

    cout << "hello World";
    string ans = "siddharth";
    string ans2 = "hrferdfhgfde";
    string ans3 = "";
    cout << "\n"
         << ans;

    cout << "\n\n------------------------- Shift Cipher --------------------------------\n";
    // Shift Cipher
    Shift_Cipher sc;
    char AD = char(69);
    string a = "";
    a += AD;
    cout << "\nORG - " << ans;
    ans3 = sc.Encryption(ans, a);
    cout << "\nENC - " << ans3;
    ans = sc.Decryption(ans3, a);
    cout << "\nDEC - " << ans;

    cout << "\n\n------------------------- Vigenere Cipher --------------------------------\n";
    // Vigenere Cipher
    Vigenere_Cipher v;
    cout << "\nORG - " << ans;
    ans3 = v.Encryption(ans, ans2);
    cout << "\nENC - " << ans3;
    ans3 = v.Decryption(ans3, ans2);
    cout << "\nDEC - " << ans3;

    cout << "\n\n------------------------- Hill Cipher --------------------------------\n";
    // Hill Cipher
    HillCipher hc;
    hc.GenerateRandomKey();
    cout << "\nORG - " << ans;
    ans3 = hc.Encryption(ans);
    cout << "\nENC - " << ans3;
    ans3 = hc.Decryption(ans3);
    cout << "\nDEC - " << ans3;

    cout << "\n\n------------------------- One Time Pad --------------------------------\n";
    // One Time Pad
    OneTimePad otp;
    string key = otp.generateKey(ans.size());
    cout << "\nORG - " << ans;
    ans3 = otp.encrypt(ans);
    cout << "\nENC - " << ans3;
    ans3 = otp.decrypt(ans3);
    cout << "\nDEC - " << ans3;

    cout << "\n\n------------------------- Diffie Hellman --------------------------------\n";
    // Diffie Hellman
    DiffieHellman dh(13);
    dh.generateValues();
    dh.computePublicKeys();
    dh.computeSharedKeys();
    dh.display();

    cout << "\n\n------------------------- EL Gamal --------------------------------\n";
    // El Gamal
    ElGamal elg(257);
    elg.generateKeys();
    elg.displayKeys();
    ZZ m = conv<ZZ>(15);
    ZZ c1, c2;
    elg.encrypt(m, c1, c2);
    ZZ dec = elg.decrypt(c1, c2);
    cout << "Original m = " << m << ", decrypted = " << dec << "\n\n";

    vector<ZZ> c1s, c2s;
    string msg = "Hi";
    elg.encryptString(msg, c1s, c2s);
    string decMsg = elg.decryptString(c1s, c2s);
    cout << "Original msg = " << msg << ", decrypted msg = " << decMsg << "\n\n";

    ZZ r, s;
    ZZ mHash = conv<ZZ>(42);
    elg.signMessage(mHash, r, s);
    cout << "Signature: r = " << r << ", s = " << s << "\n";
    bool ok = elg.verifyMessage(mHash, r, s);
    cout << "Verify: " << (ok ? "valid" : "invalid") << "\n";

    cout << "\n\n------------------------- Elliptic Curve -------------------------\n";

    ZZ p = conv<ZZ>(97); // prime modulus
    ZZ aEC = conv<ZZ>(2);
    ZZ bEC = conv<ZZ>(3);

    // Create elliptic curve and initialize ZZ_p field
    ELCurve curve(p, aEC, bEC);

    // Define points using ZZ_p type
    ZZ_p Px = to_ZZ_p(3);
    ZZ_p Py = to_ZZ_p(6);
    ZZ_p Qx = to_ZZ_p(80);
    ZZ_p Qy = to_ZZ_p(10);

    ECPoint P(Px, Py);
    ECPoint Q(Qx, Qy);

    // Point At Curve or Not [ Validation ]
    cout << "\nChecking points validity:\n";
    cout << "P is " << (curve.isValidPoint(P) ? "valid" : "invalid") << endl;
    cout << "Q is " << (curve.isValidPoint(Q) ? "valid" : "invalid") << endl;

    // P + Q  Point Addition
    ECPoint R = curve.pointAdd(P, Q);
    cout << "\nR = P + Q" << endl;
    if (R.infinity)
        cout << "R is point at infinity\n";
    else
        cout << "R = (" << rep(R.x) << ", " << rep(R.y) << ")\n";

    // 2P Point Doubling
    ECPoint D = curve.pointDouble(P);
    cout << "\nD = 2P" << endl;
    if (D.infinity)
        cout << "D is point at infinity\n";
    else
        cout << "D = (" << rep(D.x) << ", " << rep(D.y) << ")\n";

    // scalar multiplication
    ECPoint SR = curve.scalarMultiply(P, bEC);
    cout << "\nSR.x = " << SR.x << ", SR.y = " << SR.y << endl;

    // El gamal over Eliptic Curve
    // Key Gen
    // Encryption
    // Digital Signature Create
    // Decryption
    // Digital Signature Verified

    // Eliptic Curve over integrated + point Compression

    return 0;
}
