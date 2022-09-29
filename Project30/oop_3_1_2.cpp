#include <iostream>
#include <cmath>

using namespace std;

class Polygon
{
private:
	int Area = 0;
	int Perimeter = 0;
public:
	Polygon() {};
	~Polygon() {};
	void print_Area();
	void print_Perimeter() {};
};

class Triangle : public Polygon
{
private:
	int A, B, C;
public:
	Triangle(int s1, int s2, int s3)
	{
		A = s1;
		B = s2;
		C = s3;
	}
	void print_Area()
	{
		double area = sqrt(4 * pow(A, 2) * pow(B, 2) - pow((pow(A, 2) + pow(B, 2) - pow(C, 2)), 2)) / 4;
		cout << "Area is " << area << endl;
	}
	void print_Perimeter()
	{
		int peri = A + B + C;
		cout << "Perimeter is " << peri << endl;
	}
	~Triangle() {};
};

class Square : public Polygon
{
private:
	int A, B;
public:
	Square(int base, int height)
	{
		A = base;
		B = height;
	}
	void print_Area()
	{
		int area = A * B;
		cout << "Area is " << area << endl;
	}
	void print_Perimeter()
	{
		int peri = 2 * (A + B);
		cout << "Perimeter is " << peri << endl;
	}
	~Square() {};
};

int main()
{
	class Square A(5, 4);
	class Triangle B(13, 14, 15);

	cout << "--------Square--------" << endl;
	A.print_Area();
	A.print_Perimeter();
	cout << "----------------------" << endl;
	cout << "-------Triangle-------" << endl;
	B.print_Area();
	B.print_Perimeter();
	cout << "----------------------" << endl;

	return 0;
}