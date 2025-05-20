#ifndef FUNCTOR_H
#define FUNCTOR_H

#include <iostream>

class Functor
{
public:
	Functor() {}

    void operator()(int x)
    {
        if (x % 3 == 0) {
            sum += x;
            _counter += 1;
        }
    }

    int get_sum() const { return sum; }
    int get_count() const { return _counter; }

private:
	int _counter{};
	int sum{};
};


#endif	//FUNCTOR_H