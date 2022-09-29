#include <iostream>

using namespace std;

class TwoPoint
{
protected:
	float x;
	float y;
	float z;
	float w;
public:
	TwoPoint();
	TwoPoint(float a, float b, float c, float d);
	~TwoPoint() {};
	virtual void print();
};
TwoPoint::TwoPoint()
{
	x = 0;
	y = 0;
	w = 0;
	z = 0;
}
TwoPoint::TwoPoint(float a, float b, float c, float d)
{
	x = a;
	y = b;
	z = c;
	w = d;
}
void TwoPoint::print()
{
	cout << "Point 1 : " << x << "," << y << endl << "Point 2 : " << z << "," << w << endl;
}

class Equation : public TwoPoint
{
public:
	Equation() {};
	Equation(float a, float b, float c, float d);
	~Equation() {};
	virtual void print();
};
Equation::Equation(float a, float b, float c, float d)
{
	x = a;
	y = b;
	z = c;
	w = d;
}
void Equation::print()
{
	float gradiant = 0.0;
	gradiant = (w - y) / (z - x);
	float y_intercept = 0.0;
	y_intercept = gradiant * (-1) * x + y;

	cout << "Equation : " << "y = " << gradiant << "x + " << y_intercept;
}

int main()
{
	class TwoPoint* A = new TwoPoint(3, 6, 5, 8);
	class TwoPoint* B = new Equation(3, 6, 5, 8);
	A->print();
	B->print();
	delete A;
	delete B;

	return 0;
}