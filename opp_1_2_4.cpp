#include <iostream>

using namespace std;


int sig(int x);

int main()
{
	int N;
	cout << "Enter Any Positive Number :";
	cin >> N;

	int sigma = sig(N);

	cout << sigma;

	return 0;
}

int sig(int x)
{
	int i = 0;
	int sum = 0;

	while (i <= x)
	{
		sum = sum + i * pow(2, i);
		i = i + 1;
	}
	return sum;
}