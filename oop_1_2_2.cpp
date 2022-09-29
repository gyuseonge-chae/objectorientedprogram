#include <iostream>

using namespace std;

int main()
{
	int a;
	cout << "Enter any Number :";
	cin >> a;

	int i = 0; 

	for (int i = 1; i <= 20; i++)
	{
		if (i % a == 0)
		{
			cout << i << endl;
			continue;
		}
		else 
		{
			cout << i << " ";
			continue;
		}
	}
	
	return 0;
}