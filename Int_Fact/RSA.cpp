#include "RSA.hpp"
#include <NTL/ZZ.h>
#include <NTL/BasicThreadPool.h>
#include <iostream>

using namespace NTL;
using namespace std;

RSAKeyPair RSA_GenerateKeys(unsigned int bitsPerPrime, const ZZ &publicE) {
    RSAKeyPair key;
    ZZ e = publicE;
    ZZ p, q;

    cout << " Generating random primes (" << bitsPerPrime << " bits each)...\n";

    do {
        do {
            p = RandomBits_ZZ(bitsPerPrime) | 1; 
        } while (!ProbPrime(p)); 

        do {
            q = RandomBits_ZZ(bitsPerPrime) | 1; 
        } while (!ProbPrime(q) || p == q);
    } while (p == q);

    key.p = p;
    key.q = q;
    key.n = p * q;

    ZZ phi = (p - 1) * (q - 1);

    if (GCD(e, phi) != 1) {
        e = conv<ZZ>(3);
        while (GCD(e, phi) != 1) e += 2;
    }

    key.e = e;
    key.d = InvMod(e, phi);

    RSA_CompletePrivateFromPQ(key);

    cout << " RSA keys generated successfully.\n";
    return key;
}

void RSA_CompletePrivateFromPQ(RSAKeyPair &key) {
    key.dp = key.d % (key.p - 1);
    key.dq = key.d % (key.q - 1);
    key.qinv = InvMod(key.q, key.p); 
}

ZZ RSA_Encrypt(const ZZ &m, const RSAKeyPair &pubkey) {
    return PowerMod(m, pubkey.e, pubkey.n);
}

ZZ RSA_Decrypt(const ZZ &c, const RSAKeyPair &privkey) {
    ZZ m1 = PowerMod(c % privkey.p, privkey.dp, privkey.p);
    ZZ m2 = PowerMod(c % privkey.q, privkey.dq, privkey.q);
    ZZ h = (m1 - m2) % privkey.p;
    if (h < 0) h += privkey.p;
    h = MulMod(h, privkey.qinv, privkey.p);
    ZZ m = m2 + h * privkey.q;
    m %= privkey.n;
    return m;
}

ZZ RSA_Sign(const ZZ &hashValue, const RSAKeyPair &privkey) {
    return PowerMod(hashValue % privkey.n, privkey.d, privkey.n);
}

bool RSA_Verify(const ZZ &hashValue, const ZZ &signature, const RSAKeyPair &pubkey) {
    ZZ v = PowerMod(signature % pubkey.n, pubkey.e, pubkey.n);
    return v == (hashValue % pubkey.n);
}
