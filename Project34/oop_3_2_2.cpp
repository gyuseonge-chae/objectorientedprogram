#include <iostream>
#include <string>

using namespace std;

class 대학
{
private:
	char U_Name[20];
	char U_StudID[20];
	int year;
	
public:
	대학()
	{
		cout << "학교 :";
		cin >> U_Name;
		cout << "학번 :";
		cin >> U_StudID;
		cout << "학년 :";
		cin >> year;
	}
	char* get_id();
	virtual void print1();
	~대학() {};
};
void 대학::print1()
{
	cout << "학교:" << this->U_Name << endl << "학번:" << this->U_StudID << endl << "학년:" << this->year << endl;
}
char* 대학::get_id()
{
	return U_StudID;
}

class 컴퓨터정보공학 : public 대학
{
private:
	char Object_Oriented_Programing;
	char Digital_Logic_Circuit;
public:
	컴퓨터정보공학() : 대학()
	{
		cout << "객체지향프로그래밍 학점 :";
		cin >> Object_Oriented_Programing;
		cout << "디지털논리회로 학점 :";
		cin >> Digital_Logic_Circuit;
	}
	virtual void print2();
	~컴퓨터정보공학() {};
};
void 컴퓨터정보공학::print2()
{
	cout << "객체지향프로그래밍 학점:" << this->Object_Oriented_Programing << endl << "디지털논리회로 학점:" <<  this->Digital_Logic_Circuit << endl;
}

class 학생정보 : public 컴퓨터정보공학
{
private:
	char Name[10];
	int age;
public:
	학생정보() : 컴퓨터정보공학()
	{
		cout << "이름 :";
		cin >> Name;
		cout<< "나이 :";
		cin >> age;
	}
	void print3();
	char* get_name();
	~학생정보() {};
};
void 학생정보::print3()
{
	cout << this->Name << this->age;
}
char* 학생정보::get_name()
{
	return Name;
}

int main()
{
	char cmd[10] = {0,};
	int count = 0;
	학생정보** dp_stds = new 학생정보* [100];

	while(1)
	{
		cout << "Command (INSERT, FIND, EXIT) : ";
		cin >> cmd;

		if (count > 100)
		{
			break;
		}

		if (strcmp(cmd, "INSERT") == 0)
		{
			dp_stds[count] = new 학생정보;
			count++;
		}
		else if (strcmp(cmd, "FIND") == 0)
		{
			char temp_Name[10];
			char temp_studID[20];
			cin >> temp_Name >> temp_studID;

			for (int idx = 0; idx < count; idx++)
			{
				int nameLen = strlen(temp_Name);
				int idLen = strlen(temp_studID);
				
				if (strncmp(dp_stds[idx]->get_name(), temp_Name, nameLen) == 0 && strncmp(dp_stds[idx]->get_id(), temp_studID, idLen) == 0)
				{
					dp_stds[idx]->print1();
					dp_stds[idx]->print2();
				}
			}
		}
		else if (strcmp(cmd, "EXIT") == 0)
		{
			break;
		}

		cout << endl;
	}
	return 0;
}