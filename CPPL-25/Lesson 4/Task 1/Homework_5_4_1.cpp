#include <iostream>
#include "Windows.h"
#include <vector>
#include "template_function.h"

int main()
{
	setlocale(LC_ALL, "rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	std::vector<int> vec{ 3, 2 };

	printResult(50);
	printResult(2.5);
	printResult(vec);

	return EXIT_SUCCESS;
}