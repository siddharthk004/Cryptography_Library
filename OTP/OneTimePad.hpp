#ifndef ONE_TIME_PAD_HPP
#define ONE_TIME_PAD_HPP

#include <string>
#include <vector>
#include <random>
#include <stdexcept>
using namespace std;

class OneTimePad {
private:
    string key;

public:
    string generateKey(size_t length);

    void setKey(const string &k);
    string encrypt(const string &plaintext);
    string decrypt(const string &ciphertext);
};

#endif