#include <iostream>

using namespace std;

int add(int x, int y)
{
	int sumation = x + y;
	return sumation;
}
int sub(int x, int y)
{
	int substract = x - y;
	return substract;
}
int prod(int x, int y)
{
	int product = x * y;
	return product;
}
int rem(int x, int y)
{
	int remainder = x % y;
	return remainder;
}

int main()
{
	double A, B;
	cout << "Enter Two Numbers :";

	cin >> A >> B;

	int sum = add(A, B);
	int minus = sub(A, B);
	int multi = prod(A, B);
	double quo = A / B;
	int R = rem(A, B);

	cout << A << " " << '+' << " " << B << ':' << sum << endl;
	cout << A << " " << '-' << " " << B << ':' << minus << endl;
	cout << A << " " << '*' << " " << B << ':' << multi << endl;
	cout << A << " " << '/' << " " << B << ':' << quo << endl;
	cout << A << " " << '%' << " " << B << ':' << R;

	return 0;
}