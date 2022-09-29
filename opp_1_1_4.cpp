#include <iostream>

using namespace std;

void sqr(int& x);
void cub(int& y);

void sqr(int& x)
{
	x = (x * x);
	return;
}

void cub(int& y)
{
	y = (y * y * y);
	return;
}

int main()
{
	int A; int B;
	cout << "Number :";
	cin >> A;
	B = A;
	
	sqr(A);
	cout << "Number^2 :" << A << endl;

	cub(B);
	cout << "Number^3 :" << B << endl;
	return 0;
}