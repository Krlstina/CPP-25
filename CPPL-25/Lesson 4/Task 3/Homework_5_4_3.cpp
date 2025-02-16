#include <iostream>
#include "Windows.h"
#include <vector>
#include "functor.h"

int main()
{
	setlocale(LC_ALL, "rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	std::vector<int> vec{ 3, 23, -5, 90, 7 };

	std::cout << "[IN]: ";
	for (size_t i = 0; i < vec.size(); ++i) {
		std::cout << vec[i];
		i != vec.size() - 1 ? std::cout << ", " : std::cout << " ";
	}
	std::cout << std::endl;

	Functor func = vec;
	std::cout << "[OUT]: get_sum() = " << func.get_sum() << std::endl;
	std::cout << "[OUT]: get_count() = " << func.get_count() << std::endl;

	return EXIT_SUCCESS;
}