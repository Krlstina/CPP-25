#include <iostream>
#include <Windows.h>
#include <fstream>

int visits{};
int dfs(int** matrix, const int n, int from, int* visited, int* path);

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

    int* visited = new int[size];
    int* path = new int[size];

    for (int i = 0; i < size; i++)
    {
        visited[i] = 0;
        path[i] = 0;
    }

    std::cout << "Топологический порядок вершин: ";

    for (int i = 0; i < size; ++i)
    {
        if (visited[i] == 0)
        {
            dfs(matrix, size, i + 1, visited, path);
        }
    }

    for (int i = 0; i < size; ++i)
    {
        std::cout << path[i] << " ";
    }

    std::cout << std::endl;

    for (int row = 0; row < size; ++row)
    {
        delete[] matrix[row];
    }
    delete[] matrix;
    delete[] visited;

    return EXIT_SUCCESS;
}



int dfs(int** matrix, const int size, int vertex, int* visited, int* path)
{
    visited[vertex - 1] += 1;

    if (visited[vertex - 1] > 1)
    {
        return EXIT_SUCCESS;
    }

    for (int i = 0; i < size; ++i)
    {
        if (matrix[vertex - 1][i] == 1)
        {
            dfs(matrix, size, i + 1, visited, path);
        }
    }

    visits += 1;
    path[size - visits] = vertex;

    return EXIT_SUCCESS;
}