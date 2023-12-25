#include "encryption.h"
#include <cryptopp/aes.h>
#include <cryptopp/hex.h>
#include <cryptopp/filters.h>
#include <cryptopp/files.h>
#include <cryptopp/modes.h>

using namespace CryptoPP;

bool Encryption::encryptFile(const std::string& filename, const std::string& password) {
    std::string key = generateKey(password);
    std::string encryptedFilename = filename + ".enc";

    try {
        CBC_Mode<AES>::Encryption encryption((byte*)key.c_str(), key.length(), (byte*)"0000000000000000");
        FileSource(filename.c_str(), true, new StreamTransformationFilter(encryption, new FileSink(encryptedFilename.c_str())));
    } catch (Exception& e) {
        return false;
    }

    remove(filename.c_str());
    return true;
}

bool Encryption::decryptFile(const std::string& filename, const std::string& password) {
    std::string key = generateKey(password);
    std::string decryptedFilename = filename + ".dec";

    try {
        CBC_Mode<AES>::Decryption decryption((byte*)key.c_str(), key.length(), (byte*)"0000000000000000");
        FileSource(filename.c_str(), true, new StreamTransformationFilter(decryption, new FileSink(decryptedFilename.c_str())));
    } catch (Exception& e) {
        return false;
    }

    remove(filename.c_str());
    return true;
}

std::string Encryption::generateKey(const std::string& password) {
    std::string key;
    StringSource(password, true, new HexEncoder(new StringSink(key)));
    return key.substr(0, 16);
}
