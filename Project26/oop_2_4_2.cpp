# include <iostream>

using namespace std;

class Student
{
private:
	char name[20];
	int Score;
public:
	Student() {};
	void insertInfo();
	void showInfo();
	int getScore();
	char* getName();
	~Student() {};
};

//멤버 함수
void Student::insertInfo()
{
	cout << "Name :";
	cin >> name;
	cout << "Score :";
	cin >> Score;

	return;
}

void Student::showInfo()
{
	for (int k = 0; name[k] != NULL; k++)
	{
		cout << name[k];
	}
	cout << " " << Score << endl;

	return;
}

int Student::getScore()
{
	return Score;
}

char* Student::getName()
{
	return name;
}

//전역 함수
void sortScore(Student* sample, int t)
{
	Student temp;

	for (int a = 0; a < t - 1 ; a++)
	{
		for (int b = 0; b < t - 1 - a; b++)
		{
			if (sample[b].getScore() > sample[b + 1].getScore())
			{
				temp = sample[b];
				sample[b] = sample[b + 1];
				sample[b + 1] = temp;
			}
		}
	}
	return;
}

void sortName(Student* sample, int s)
{
	Student temp;

	for (int c = 0; c < s; c++)
	{
		for (int d = 0; d < c; d++)
		{
			if (strcmp(sample[c].getName(), sample[d].getName()) < 0)
			{
				temp = sample[c];
				sample[c] = sample[d];
				sample[d] = temp;
			}
		}
	}
	return;
}

int main()
{
	Student stud_arr[30];
	int cmd = 0;
	int i = 0;

	while (1)
	{
		cout << "Please Enter Comand(1: insert, 2: sort by name, 3: sort by score, 4: quit) :";
		cin >> cmd;
		
		if (cmd == 1)
		{
			stud_arr[i].insertInfo();
			i++;
		}
		else if (cmd == 2)
		{
			sortName(stud_arr, i);
			for (int idx = 0; idx< i; idx++)
			{
				stud_arr[idx].showInfo();
			}
		}
		else if (cmd == 3)
		{
			Student temp[30];
			for(int x = 0; x < i; x++)
			{
				temp[x] = stud_arr[x];
			}
			sortScore(temp, i);
			for (int idx = 0; idx < i; idx++)
			{
				temp[idx].showInfo();
			}
		}
		else if (cmd == 4)
		{
			for (int j = 0; j < 30; j++)
			{
				stud_arr[j].~Student();
			}
			break;
		}
		else 
		{
			cout << "Invalid Command Detected." << endl;
			continue;
		}
		cout << endl;
	}

	return 0;
}

