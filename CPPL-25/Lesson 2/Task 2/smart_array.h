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

	//Конструктор копирования
	smart_array(const smart_array& array)
	{
		size_ = array.size_;
		_data = new int[size_] {};

		for (int index = 0; index < array.size_; ++index)
		{
			_data[index] = array._data[index];
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
			return this->_data[index];
		}
		else
		{
			throw DivisionException("Ошибка! Невозможно получить элемент - некорректный индекс");
		}
	}

	//Присваивание копированием
	smart_array& operator=(const smart_array& array)
	{
		if (size_ >= array.size_)
		{
			for (int index = 0; index < array.size_; ++index)
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
	int size_{};
};

#endif