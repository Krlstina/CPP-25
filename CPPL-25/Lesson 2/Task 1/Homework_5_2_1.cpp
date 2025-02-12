#include <iostream>
#include "Windows.h"
#include "smart_array.h"

int main()
{
	setlocale(LC_ALL, "rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	
	try {
		smart_array arr(5);
		arr.add_element(1);
		arr.add_element(4);
		arr.add_element(155);
		arr.add_element(14);
		arr.add_element(15);

		std::cout << arr.get_element(1) << std::endl;
	}
	catch (const DivisionException& ex) {
		std::cerr << ex.what() << std::endl;

		return EXIT_FAILURE;
	}
	catch (...)
	{
		std::cerr << "Неизвестная ошибка!!!" << std::endl;

		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}