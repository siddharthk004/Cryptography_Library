#ifndef RSA_HPP
#define RSA_HPP

#include <NTL/ZZ.h>
#include <utility>

using namespace NTL;
using namespace std;

struct RSAKeyPair
{
    ZZ n, e, d, p, q, dp, dq, qinv;
};

RSAKeyPair RSA_GenerateKeys(unsigned int bitsPerPrime, const ZZ &publicE = conv<ZZ>(65537));

ZZ RSA_Encrypt(const ZZ &m, const RSAKeyPair &pubkey);
ZZ RSA_Decrypt(const ZZ &c, const RSAKeyPair &privkey);
ZZ RSA_Sign(const ZZ &hashValue, const RSAKeyPair &privkey);
bool RSA_Verify(const ZZ &hashValue, const ZZ &signature, const RSAKeyPair &pubkey);

void RSA_CompletePrivateFromPQ(RSAKeyPair &key);

#endif
