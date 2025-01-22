#include <iostream>
#include <Windows.h>
#include <string>

int real_string_hash(std::string word, int primeNumber, int module)
{
    long long stringHash{};

    for (int i = 0; i < word.length(); ++i)
    {
        stringHash += word[i] * pow(primeNumber, i);
    }

    return stringHash % module;
}

int main()
{
    setlocale(LC_ALL, "rus");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    std::string enterLine{};
    int prime{};
    int module{};

    std::cout << "Введите р: ";
    std::cin >> prime;
    std::cout << "Введите n: ";
    std::cin >> module;

    do
    {
        std::cout << "Введите строку: ";
        std::cin >> enterLine;
        std::cout << "Наивный хеш строки " << enterLine << " = " << real_string_hash(enterLine, prime, module) << std::endl;
    } while (enterLine != "exit");

    return EXIT_SUCCESS;
}