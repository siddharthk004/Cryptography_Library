#include "OneTimePad.hpp"

string OneTimePad::generateKey(size_t length) {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dist(0, 255);

    key.clear();
    for (size_t i = 0; i < length; i++) {
        char c = static_cast<char>(dist(gen));
        key.push_back(c);
    } 
    return key;
}

void OneTimePad::setKey(const string &k) {
    key = k;
}

string OneTimePad::encrypt(const string &plaintext) {
    if (key.size() < plaintext.size()) {
        throw runtime_error("Key too short for plaintext");
    }
    string ciphertext;
    ciphertext.resize(plaintext.size());

    for (size_t i = 0; i < plaintext.size(); i++) {
        ciphertext[i] = plaintext[i] ^ key[i];
    }
    return ciphertext;
}

string OneTimePad::decrypt(const string &ciphertext) {

    if (key.size() < ciphertext.size()) {
        throw runtime_error("Key too short for ciphertext");
    }
    string plaintext;
    plaintext.resize(ciphertext.size());

    for (size_t i = 0; i < ciphertext.size(); i++) {
        plaintext[i] = ciphertext[i] ^ key[i];
    }
    return plaintext;
}
