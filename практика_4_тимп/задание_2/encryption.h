#ifndef ENCRYPTION_H
#define ENCRYPTION_H

#include <string>

class Encryption {
public:
    bool encryptFile(const std::string& filename, const std::string& password);
    bool decryptFile(const std::string& filename, const std::string& password);

private:
    std::string generateKey(const std::string& password);
};

#endif // ENCRYPTION_H
