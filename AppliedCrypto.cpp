

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
#include "Int_Fact/RSA.hpp"
// #include "Int_Fact/Factor.hpp"

using namespace std;
using namespace NTL;

int main()
{
    cout << "hello World";
    // string ans = "siddharth";
    // string ans2 = "hrferdfhgfde";
    // string ans3 = "";
    // cout << "\n"
    //      << ans;

    // cout << "\n\n------------------------- Shift Cipher --------------------------------\n";
    // // Shift Cipher
    // Shift_Cipher sc;
    // char AD = char(69);
    // string a = "";
    // a += AD;
    // cout << "\nORG - " << ans;
    // ans3 = sc.Encryption(ans, a);
    // cout << "\nENC - " << ans3;
    // ans = sc.Decryption(ans3, a);
    // cout << "\nDEC - " << ans;

    // cout << "\n\n------------------------- Vigenere Cipher --------------------------------\n";
    // // Vigenere Cipher
    // Vigenere_Cipher v;
    // cout << "\nORG - " << ans;
    // ans3 = v.Encryption(ans, ans2);
    // cout << "\nENC - " << ans3;
    // ans3 = v.Decryption(ans3, ans2);
    // cout << "\nDEC - " << ans3;

    // cout << "\n\n------------------------- Hill Cipher --------------------------------\n";
    // // Hill Cipher
    // HillCipher hc;
    // hc.GenerateRandomKey();
    // cout << "\nORG - " << ans;
    // ans3 = hc.Encryption(ans);
    // cout << "\nENC - " << ans3;
    // ans3 = hc.Decryption(ans3);
    // cout << "\nDEC - " << ans3;

    // cout << "\n\n------------------------- One Time Pad --------------------------------\n";
    // // One Time Pad
    // OneTimePad otp;
    // string key = otp.generateKey(ans.size());
    // cout << "\nORG - " << ans;
    // ans3 = otp.encrypt(ans);
    // cout << "\nENC - " << ans3;
    // ans3 = otp.decrypt(ans3);
    // cout << "\nDEC - " << ans3;

    // cout << "\n\n------------------------- Diffie Hellman --------------------------------\n";
    // // Diffie Hellman
    // DiffieHellman dh(13);
    // dh.generateValues();
    // dh.computePublicKeys();
    // dh.computeSharedKeys();
    // dh.display();

    // cout << "\n\n------------------------- EL Gamal --------------------------------\n";
    // // El Gamal
    // ElGamal elg(257);
    // elg.generateKeys();
    // elg.displayKeys();
    // ZZ m = conv<ZZ>(15);
    // ZZ c1, c2;
    // elg.encrypt(m, c1, c2);
    // ZZ dec = elg.decrypt(c1, c2);
    // cout << "Original m = " << m << ", decrypted = " << dec << "\n\n";

    // vector<ZZ> c1s, c2s;
    // string msg = "Hi";
    // elg.encryptString(msg, c1s, c2s);
    // string decMsg = elg.decryptString(c1s, c2s);
    // cout << "Original msg = " << msg << ", decrypted msg = " << decMsg << "\n\n";

    // ZZ r, s;
    // ZZ mHash = conv<ZZ>(42);
    // elg.signMessage(mHash, r, s);
    // cout << "Signature: r = " << r << ", s = " << s << "\n";
    // bool ok = elg.verifyMessage(mHash, r, s);
    // cout << "Verify: " << (ok ? "valid" : "invalid") << "\n";

    // cout << "\n\n------------------------- Elliptic Curve -------------------------\n";

    // ZZ p = conv<ZZ>(97); // prime modulus
    // ZZ aEC = conv<ZZ>(2);
    // ZZ bEC = conv<ZZ>(3);

    // // Create elliptic curve and initialize ZZ_p field
    // ELCurve curve(p, aEC, bEC);

    // // Define points using ZZ_p type
    // ZZ_p Px = to_ZZ_p(3);
    // ZZ_p Py = to_ZZ_p(6);
    // ZZ_p Qx = to_ZZ_p(80);
    // ZZ_p Qy = to_ZZ_p(10);

    // ECPoint P(Px, Py);
    // ECPoint Q(Qx, Qy);

    // // Point At Curve or Not [ Validation ]
    // cout << "\nChecking points validity:\n";
    // cout << "P is " << (curve.isValidPoint(P) ? "valid" : "invalid") << endl;
    // cout << "Q is " << (curve.isValidPoint(Q) ? "valid" : "invalid") << endl;

    // // P + Q  Point Addition
    // ECPoint R = curve.pointAdd(P, Q);
    // cout << "\nR = P + Q" << endl;
    // if (R.infinity)
    //     cout << "R is point at infinity\n";
    // else
    //     cout << "R = (" << rep(R.x) << ", " << rep(R.y) << ")\n";

    // // 2P Point Doubling
    // ECPoint D = curve.pointDouble(P);
    // cout << "\nD = 2P" << endl;
    // if (D.infinity)
    //     cout << "D is point at infinity\n";
    // else
    //     cout << "D = (" << rep(D.x) << ", " << rep(D.y) << ")\n";

    // // scalar multiplication
    // ECPoint SR = curve.scalarMultiply(P, bEC);
    // cout << "\nSR.x = " << SR.x << ", SR.y = " << SR.y << endl;

    // cout << "\n---------------- ElGamal over Elliptic Curve ----------------\n";

    // ZZ p = conv<ZZ>(97);
    // ZZ_p::init(p);

    // ZZ_p a = conv<ZZ_p>(2);
    // ZZ_p b = conv<ZZ_p>(3);

    // ELCurve curve(a, b);
    // ECPoint G(conv<ZZ_p>(2), conv<ZZ_p>(7));
    // ZZ n = conv<ZZ>(5);

    // // --- Key Generation ---
    // ZZ priv = conv<ZZ>(2);
    // ECPoint pub = curve.generatePublicKey(G, priv);

    // cout << "Private key: " << priv << "\n";
    // cout << "Public key: (" << pub.x << ", " << pub.y << ")\n";

    // // --- Encryption ---
    // ECPoint M(conv<ZZ_p>(3), conv<ZZ_p>(6));
    // ZZ k = conv<ZZ>(4);
    // auto cipher = curve.encrypt(M, G, pub, k);

    // cout << "\nCiphertext:\nC1 = (" << cipher.first.x << ", " << cipher.first.y << ")\n";
    // cout << "C2 = (" << cipher.second.x << ", " << cipher.second.y << ")\n";

    // // --- Decryption ---
    // ECPoint dec = curve.decrypt(cipher, priv);
    // cout << "\nDecrypted Message: (" << dec.x << ", " << dec.y << ")\n";
 
    // // --- Digital Signature ---
    // ZZ msgHash = conv<ZZ>(25);
    // auto sig = curve.sign(msgHash, priv, G, n);
    // cout << "\nSignature: (r=" << sig.first << ", s=" << sig.second << ")\n";

    // bool valid = curve.verify(msgHash, sig, G, pub, n);
    // cout << "Signature verification: " << (valid ? "VALID" : "INVALID") << endl;

    cout << "\n---------------- Eliptic Curve over integrated + point Compression ----------------\n";
    
    ZZ prime = conv<ZZ>(97);
    ZZ_p::init(prime);

    ELCurve curve(to_ZZ_p(2), to_ZZ_p(3)); 
    ECPoint G(to_ZZ_p(3), to_ZZ_p(7));

    ZZ priv = conv<ZZ>(5);
    ECPoint pub = curve.generatePublicKey(G, priv);

    cout << "Public Key: (" << pub.x << ", " << pub.y << ")\n";

    CompressedPoint cp = curve.compressPoint(pub);
    cout << "Compressed form -> x: " << cp.x << ", y is odd: " << cp.y_is_odd << "\n";

    ECPoint decompressed = curve.decompressPoint(cp);
    cout << "Decompressed -> (" << decompressed.x << ", " << decompressed.y << ")\n";

    cout << " " << (curve.isValidPoint(decompressed) ? "Point is valid on the curve \n" : "Invalid point \n") << "\n";

    cout << "\n---------------- Integer Factorization ----------------\n";

    unsigned int bitsPerPrime = 32; 
    cout << "Generating RSA keys ...\n";
    RSAKeyPair key = RSA_GenerateKeys(bitsPerPrime);

    cout << "n = " << key.n << "\n";
    cout << "e = " << key.e << "\n";
    cout << "d = " << key.d << "\n";
    cout << "p = " << key.p << "\n";
    cout << "q = " << key.q << "\n";

    ZZ m = conv<ZZ>(12345);
    cout << "Plain: " << m << "\n";

    ZZ c = RSA_Encrypt(m, key);
    cout << "Cipher: " << c << "\n";

    ZZ mrec = RSA_Decrypt(c, key);
    cout << "Decrypted: " << mrec << "\n";

    ZZ hashv = conv<ZZ>(987654321);
    ZZ sig = RSA_Sign(hashv, key);
    cout << "Signature: " << sig << "\n";
    cout << "Verify: " << (RSA_Verify(hashv, sig, key) ? "OK" : "FAIL") << "\n";

    return 0;
}
