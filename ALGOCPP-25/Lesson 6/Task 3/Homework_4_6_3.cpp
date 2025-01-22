#include <iostream>
#include <Windows.h>
#include <string>

int simple_string_cash(std::string word)
{
    int stringCash{};

    for (int i = 0; i < word.length(); ++i)
    {
        stringCash += word[i];
    }

    return stringCash;
}

int find_substring_light_rabin_karp(std::string line, std::string subline)
{
    int hashSubline{simple_string_cash(subline)};
    int actualHash{};

    for (int i = 0; i < line.length(); ++i)
    {
        if (i == 0)
        {
            for (int j = 0; j < subline.length(); ++j)
            {
                actualHash += line[j];
            }
        }
        else {
            if (i + subline.length() -1 == line.length()) { return -1; }

            actualHash -= line[i - 1];
            actualHash += line[i + subline.length() - 1];
        }

        if (actualHash != hashSubline)
        {
            continue;
        }
        else {
            for (int k = 0; k < subline.length(); ++k)
            {
                if (line[i + k] != subline[k])
                {
                    return -1;
                }

                return i;
            }
        }
    }
}

int main()
{
    setlocale(LC_ALL, "rus");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    std::string enterLine{};
    std::string enterSubline{};
    int index{};

    std::cout << "Введите строку, в которой будет осуществляться поиск: ";
    std::cin >> enterLine;

    do
    {
        std::cout << "Введите подстроку, которую нужно найти: ";
        std::cin >> enterSubline;
        index = find_substring_light_rabin_karp(enterLine, enterSubline);
        if (index == -1)
        {
            std::cout << "Подстрока " << enterSubline << " не найдена" << std::endl;
        }
        else {
            std::cout << "Подстрока " << enterSubline << " найдена по индексу " << index << std::endl;
        }    
    } while (enterSubline != "exit");

    return EXIT_SUCCESS;
}