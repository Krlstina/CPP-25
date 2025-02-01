#include <iostream>
#include <Windows.h>
#include <fstream>

int main()
{
    setlocale(LC_ALL, "rus");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    std::ifstream readFile("input.txt");

    int size{};
    readFile >> size;
    int** matrix = new int* [size];

    for (int row = 0; row < size; ++row)
    {
        matrix[row] = new int[size];
    }

    for (int row = 0; row < size; ++row)
    {
        for (int columns = 0; columns < size; ++columns)
        {
            readFile >> matrix[row][columns];
        }
    }
    readFile.close();

    int pathNumber{};

    std::cout << "Текстовый вид орграфа: " << std::endl;

    for (int i = 0; i < size; ++i)
    {
        std::cout << i + 1 << ": ";

        for (int vertex = 0; vertex < size; ++vertex)
        {
            if (matrix[i][vertex] == 1)
            {
                std::cout << vertex + 1 << " ";
                pathNumber += 1;
            }
        }

        if (pathNumber == 0)
        {
            std::cout << "нет";
        }

        pathNumber = 0;
        std::cout << std::endl;
    }

    std::cout << std::endl;

    for (int row = 0; row < size; ++row)
    {
        delete[] matrix[row];
    }
    delete[] matrix;

    return EXIT_SUCCESS;
}