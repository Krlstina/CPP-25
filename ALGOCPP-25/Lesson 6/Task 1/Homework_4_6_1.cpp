#include <iostream>
#include <Windows.h>
#include <string>

int simple_string_cash(std::string word)
{
    int stringСash{};

    for (int i = 0; i < word.length(); ++i)
    {
        stringСash += word[i];
    }

    return stringСash;
}

int main()
{
    setlocale(LC_ALL, "rus");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    std::string enterLine{};

    do
    {
        std::cout << "Введите строку: ";
        std::cin >> enterLine;
        std::cout << "Наивный хеш строки " << enterLine << " = " << simple_string_cash(enterLine) << std::endl;
    } while (enterLine != "exit");

    return EXIT_SUCCESS;
}