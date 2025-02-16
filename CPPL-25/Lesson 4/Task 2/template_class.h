#ifndef TEMPLATE_CLASS_H
#define TEMPLATE_CLASS_H

#include <iostream>

template<class T>
class Table
{
public:

	Table(int rows, int columns) {
		_matrix.resize(rows);
		for (auto& row : _matrix) {
			row.resize(columns);
		}
	}

	const void Size() {
		std::cout << "Размер таблицы - " << _matrix.size() << " строк(и), " << _matrix[0].size() << " столбца(ов)" << std::endl;
	}

	const std::vector<T>& operator [] (int i) const {
		return _matrix[i];
	}

	std::vector<T>& operator [] (int i) {
		return _matrix[i];
	}

private:
	std::vector<std::vector<T>> _matrix{};
};


#endif	//TEMPLATE_CLASS_H