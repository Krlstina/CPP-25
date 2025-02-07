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

	smart_array& operator=(const smart_array& array)
	{		
		if ((_msize(_data) / sizeof(*_data)) >= (_msize(array._data) / sizeof(*array._data)))
		{
			for (int index = 0; index < (_msize(array._data) / sizeof(*array._data)); ++index)
			{
				this->_data[index] = array._data[index];
			}
			return *this;
		}
		else
		{
			throw DivisionException("Ошибка! Невозможно присвоить элементы одного массива другому - в принимающем массиве количество элементов меньше");
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

		smart_array arrayFirst(3);
		arrayFirst.add_element(1);
		arrayFirst.add_element(4);
		arrayFirst.add_element(155);

		smart_array arraySecond(2);
		arraySecond.add_element(44);
		arraySecond.add_element(34);

		arrayFirst = arraySecond;

		std::cout << arrayFirst.get_element(1) << std::endl;
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