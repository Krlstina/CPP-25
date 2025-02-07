#include <iostream>
#include "Windows.h"
#include <string>
#include <string_view>
#include <exception>

class DivisionException : public std::exception
{
private:
	std::string error{};
public:
	DivisionException(std::string_view setError) : error{ setError } {}

	const char* what() const noexcept override { return error.c_str(); }
};

class smart_array
{
public:
	smart_array(int data = 5) { _data = new int[data] {}; }

	~smart_array()
	{
		if (nullptr != _data)
		{
			delete[] _data;
		}
	}

	int add_element(int count)
	{
		if (pointer < (_msize(_data) / sizeof(*_data))) {
			_data[pointer] = count;
			pointer += 1;

			return EXIT_SUCCESS;
		}
		else
		{
			throw DivisionException("Ошибка! Невозможно добавить элемент - количество элементов, на которое выделена память, максимально");
		}
	}

	int get_element(int index)
	{
		if (index < (_msize(_data) / sizeof(*_data))) {
			std::cout << index + 1 << "-ый элемент массива (с индексом " << index << "): ";
			return this->_data[index];
		}
		else
		{
			throw DivisionException("Ошибка! Невозможно получить элемент - некорректный индекс");
		}
	}

private:
	int* _data{ nullptr };
	int pointer{};
};


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