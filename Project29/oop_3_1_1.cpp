#include <iostream>
#include <string>

using namespace std;

class Person
{
private:
	char name[20] = { 0, };
	int age = 0;
	char residence[40] = { 0, };
public:
	Person(){};

	friend std::istream& operator >> (std::istream& in, Person& p)
	{
		in >> p.name >> p.age >> p.residence;
		
		return in;
	}
	friend std::ostream& operator << (std::ostream& out, Person& p)
	{
		out << "이름 :" << p.name << endl << "나이 :" << p.age << endl << "거주지 :" << p.residence;
		
		return out;
	}
	~Person() {};
};

int main()
{
	Person P;
	cin >> P;
	cout << P;
	return 0;
}