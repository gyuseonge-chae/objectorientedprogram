#include <iostream>

using namespace std;

int main()
{
	int a; int b;
	cout << "Ener Two Number :";
	cin >> a >> b;

	if (a > b)
	{
		cout << a << " " << ">" << " " << b;
	}
	else if (a == b)
	{
		cout << a << " " << "=" << " " << b;
	}
	else
	{
		cout << a << " " << "<" << " " << b;
	}
	return 0;
}
