// virtual functions
#include <iostream>
using namespace std;

class Polygon {
public:
	int width, height;
	void set_values(int a, int b)
	{
		width = a; height = b;
	}

	virtual int area()
	{
		return 0;

	}
};

class Rectangle : public Polygon {
public:
	int area()
	{
		return width * height;

	}
};

class Triangle : public Polygon {
public:
	int area()
	{
		return (width * height / 2);

	}
};

int main() {
	Rectangle rect;
	Triangle trgl;
	Polygon poly;

	rect.set_values(4, 5);
	trgl.set_values(4, 5);
	poly.set_values(4, 5);
	cout << "Rectangle area =" << rect.area() << '\n';
	cout << "Triangle area =" << trgl.area() << '\n';
	cout << "Polygon area =" << poly.area() << '\n';
	return 0;
}