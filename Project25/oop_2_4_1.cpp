# include <iostream>

using namespace std;
class Overloading {
private:
	int i_a = 0; 
	int i_b = 0;
	float f_a = 0;
	float f_b = 0;
	unsigned int u_a = 0;
	unsigned int u_b = 0;
public:
	Overloading(void) {};
	~Overloading(void) {};
	void add(int i_a, int i_b);
	void add(float f_a, float f_b);
	void add(unsigned int u_a, unsigned int u_b);
};

void Overloading::add(int i_a, int i_b)
{
	long long int intSum = 0;
	intSum = i_a + i_b;
	cout << "Int type add :" << intSum <<endl;
}

void Overloading::add(float f_a, float f_b)
{
	double floatSum = 0.0;
	floatSum = f_a + f_b;
	cout << "Float type add :" << floatSum << endl;
}

void Overloading::add(unsigned int u_a, unsigned int u_b)
{
	unsigned long long int res = 0;
	res = u_a + u_b;
	cout << "Unsigned int type add :" << res << endl;
}

int main()
{
	class Overloading A;
	int int_a = 5, int_b = -10;
	float float_a = 5.1, float_b = 5.3;
	unsigned int unsigned_int_a = 5, unsigned_int_b = 5;

	A.add(int_a, int_b);
	A.add(float_a, float_b);
	A.add(unsigned_int_a, unsigned_int_b);
	return 0;
}