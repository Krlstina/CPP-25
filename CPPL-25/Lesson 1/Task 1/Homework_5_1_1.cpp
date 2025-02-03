#include <iostream>
using namespace std;

struct Point {
	double m_x{};
	double m_y{};

	Point(double x, double y) {
		this->m_x = x;
		this->m_y = y;
	}
};

void print_point(const Point& point_object) {
	cout << "x:" << point_object.m_x << ", y:" << point_object.m_y << std::endl;
}

int main()
{
	Point my_point{0.0, 0.0};

	for (int i = 0; i < 5; i++)
	{
		my_point.m_x = i;
		my_point.m_y = 2 * i;
		print_point(my_point);
	}

	return EXIT_SUCCESS;
}