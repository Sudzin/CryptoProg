#include <iostream>
#include <iomanip>
#include <fstream>
#include "encryption.h"

using namespace std;

int main() {
    cout << "=== Программа зашифрования/расшифрования файлов ===" << endl << endl;

    int mode = 0;
    string filename;
    string password;

    cout << "Выберите режим работы (1 - Зашифрование, 2 - Расшифрование): ";
    cin >> mode;

    cout << "Введите имя файла: ";
    cin >> filename;

    cout << "Введите пароль: ";
    cin >> password;

    Encryption encryption;

    if (mode == 1) {
        if (encryption.encryptFile(filename, password))
            cout << "Файл '" << filename << "' успешно зашифрован." << endl;
        else
            cout << "Ошибка при зашифровании файла." << endl;
    } else if (mode == 2) {
        if (encryption.decryptFile(filename, password))
            cout << "Файл '" << filename << "' успешно расшифрован." << endl;
        else
            cout << "Ошибка при расшифровании файла." << endl;
    } else {
        cout << "Некорректный режим работы." << endl;
    }

    cout << endl;
    cout << "=== Программа завершена ==="<<endl;

    return 0;
}
