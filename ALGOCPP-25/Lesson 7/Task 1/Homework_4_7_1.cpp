#include <iostream>
#include <Windows.h>
#include <fstream>

int dfs(int** matrix, const int n, int from, int* visited, int pathNumber);


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
    int* visited = new int [size];

    for (int i = 0; i < size; i++)
    {
        visited[i] = 0;
    }

    std::cout << "Порядок обхода вершин: ";

    //запуск обхода в глубину от первой вершины с индексом 1
    dfs(matrix, size, 1, visited, pathNumber);

    std::cout << std::endl;

    for (int row = 0; row < size; ++row)
    {
        delete [] matrix[row];
    }
    delete[] matrix;
    delete[] visited;

    return EXIT_SUCCESS;
}



int dfs(int** matrix, const int size, int vertex, int* visited, int pathNumber)
{
    if (pathNumber == size)
    {
        return EXIT_SUCCESS;
    }

    pathNumber += 1;
    visited[vertex-1] = 1;
    std::cout << vertex << " ";

    for (int i = 0; i < size; ++i)
    {
        if (matrix[vertex-1][i] == 1 && visited[i] == 0)
        {
            dfs(matrix, size, i+1, visited, pathNumber);
        }
    }
    
    return EXIT_SUCCESS;
}