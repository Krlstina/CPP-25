#ifndef TEMPLATE_FUNCTION_H
#define TEMPLATE_FUNCTION_H

#include <iostream>
#include <vector>

template <typename T>
T Square(T number)
{
	return number * number;
}

template <typename T>
std::vector<T> Square(std::vector<T>& vec)
{
	for (size_t i = 0; i < vec.size(); ++i) {
		vec[i] = Square(vec[i]);
	}

	return vec;
}

template<typename Type>
void printResult(Type number)
{
	std::cout << "[IN]: " << number << "\t[OUT]: " << Square(number) << std::endl;
}

template<typename Type>
void printResult(std::vector<Type>& vec)
{
	std::cout << "[IN]: ";

	for (size_t i = 0; i < vec.size(); ++i) {
		std::cout << vec[i];
		i != vec.size() - 1 ? std::cout << ", " : std::cout << " ";
	}

	Square(vec);
	std::cout << "\t" << "[OUT]: ";

	for (size_t i = 0; i < vec.size(); ++i) {
		std::cout << vec[i];
		i != vec.size() - 1 ? std::cout << ", " : std::cout << " ";
	}
	std::cout << std::endl;
}

#endif	//TEMPLATE_FUNCTION_H