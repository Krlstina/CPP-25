#include <iostream>
#include "Windows.h"
#include "smart_array.h"


int main()
{
	setlocale(LC_ALL, "rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	try {

		smart_array arrayFirst(3);
		arrayFirst.add_element(1);
		arrayFirst.add_element(4);
		arrayFirst.add_element(155);

		smart_array arrayThird(arrayFirst);

		std::cout << "Creating arrayThird - a copy of arrayFirst (wait 4) : " << arrayThird.get_element(1) << std::endl;


		smart_array arraySecond(2);
		arraySecond.add_element(44);
		arraySecond.add_element(34);

		std::cout << "arrayFirst before assignment by copying arraySecond (wait 4): " << arrayFirst.get_element(1) << std::endl;

		arrayFirst = arraySecond;
		
		std::cout << "arrayFirst after assignment by copying arraySecond (wait 34): " << arrayFirst.get_element(1) << std::endl;


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