#ifndef SMARTARRAY_H
#define SMARTARRAY_H

#include <iostream>
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
	smart_array(int data = 5) { _data = new int[data] {}; size_ = data; }

	~smart_array()
	{
		if (nullptr != _data)
		{
			delete[] _data;
		}
	}

	int add_element(int count)
	{
		if (pointer < size_) {
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
		if (index < size_) {
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
	int size_{};
};

#endif