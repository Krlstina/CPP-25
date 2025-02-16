#ifndef FUNCTOR_H
#define FUNCTOR_H

#include <iostream>

class Functor
{
public:
	Functor(std::vector<int>& arr) : _arr{arr}, _counter{0}	{}

	int get_sum() {
		int sum{};

		for (int i : _arr)	{
			if (i % 3 == 0) {
				sum += i;
				_counter += 1;
			}
		}

		return sum;
	}

	int get_count() { return _counter; }

private:
	std::vector<int> _arr{};
	int _counter{};
};


#endif	//FUNCTOR_H