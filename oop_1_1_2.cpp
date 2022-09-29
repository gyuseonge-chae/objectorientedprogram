#include <iostream>

using namespace std;

unsigned long long int sum(unsigned long A, unsigned long B);

int main()
{
	cout << "Enter Two Numbers :";
	unsigned long A;
	unsigned long B;
	cin >> A >> B;

	unsigned long long int s = sum(A, B);
	cout << s;

	return 0;
}//main

unsigned long long int sum(unsigned long A, unsigned long B)
{
	unsigned long long int result = A + B;
	return result;
}//sum