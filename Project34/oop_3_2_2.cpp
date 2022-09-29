#include <iostream>
#include <string>

using namespace std;

class ����
{
private:
	char U_Name[20];
	char U_StudID[20];
	int year;
	
public:
	����()
	{
		cout << "�б� :";
		cin >> U_Name;
		cout << "�й� :";
		cin >> U_StudID;
		cout << "�г� :";
		cin >> year;
	}
	char* get_id();
	virtual void print1();
	~����() {};
};
void ����::print1()
{
	cout << "�б�:" << this->U_Name << endl << "�й�:" << this->U_StudID << endl << "�г�:" << this->year << endl;
}
char* ����::get_id()
{
	return U_StudID;
}

class ��ǻ���������� : public ����
{
private:
	char Object_Oriented_Programing;
	char Digital_Logic_Circuit;
public:
	��ǻ����������() : ����()
	{
		cout << "��ü�������α׷��� ���� :";
		cin >> Object_Oriented_Programing;
		cout << "�����г�ȸ�� ���� :";
		cin >> Digital_Logic_Circuit;
	}
	virtual void print2();
	~��ǻ����������() {};
};
void ��ǻ����������::print2()
{
	cout << "��ü�������α׷��� ����:" << this->Object_Oriented_Programing << endl << "�����г�ȸ�� ����:" <<  this->Digital_Logic_Circuit << endl;
}

class �л����� : public ��ǻ����������
{
private:
	char Name[10];
	int age;
public:
	�л�����() : ��ǻ����������()
	{
		cout << "�̸� :";
		cin >> Name;
		cout<< "���� :";
		cin >> age;
	}
	void print3();
	char* get_name();
	~�л�����() {};
};
void �л�����::print3()
{
	cout << this->Name << this->age;
}
char* �л�����::get_name()
{
	return Name;
}

int main()
{
	char cmd[10] = {0,};
	int count = 0;
	�л�����** dp_stds = new �л�����* [100];

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
			dp_stds[count] = new �л�����;
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