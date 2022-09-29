#include <iostream>

using namespace std;

int main()
{
	class A
	{
	private:
		int num = 1;
		
	public:
        A()
		{
			cout << "Enter Any Number :";
			cin >> num;
			cout << "Class A is Created with " << num << endl;
		}
		~A()
		{
			cout << "Class A is Destroyed with " << num;
		}
	};

	A arbit;

	return 0;
}