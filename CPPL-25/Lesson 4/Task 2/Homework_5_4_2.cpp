#include <iostream>
#include "Windows.h"
#include <vector>
#include "template_class.h"

int main()
{
	setlocale(LC_ALL, "rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	auto test = Table<int>(5, 3);
	test[1][2] = 11;
	std::cout << test[1][2];
	std::cout << std::endl;
	test.Size();
	std::cout << std::endl;

	return EXIT_SUCCESS;
}