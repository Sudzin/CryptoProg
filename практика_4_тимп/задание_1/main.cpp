#include <iostream>
#include <iomanip>
#include <fstream>
#include <cryptopp/cryptlib.h>
#include <cryptopp/sha.h>
#include <cryptopp/hex.h>
int main()
{
    using namespace CryptoPP;
    std::ifstream input_file("chitay.txt", std::ios::binary);
    std::string
    file_contents((std::istreambuf_iterator<char>(input_file)), std::istreambuf_iterator<char>());
    SHA256 hash;
    byte digest[SHA256::DIGESTSIZE];
    hash.CalculateDigest(digest,(byte*)file_contents.c_str(), file_contents.size());
    std::cout << "SHA256 хеш файла: ";
    for (int i = 0; i < SHA256::DIGESTSIZE; i++) {
        std::cout << std::hex << std::setw(1) << std::setfill('0') << std::uppercase << static_cast<int>(digest[i]);
    }
    std::cout << std::endl;
    return 0;
}
