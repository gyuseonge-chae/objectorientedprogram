#include <iostream>
#include <string>

using namespace std;

int strLen(string str)
{
	int idx = 0;
	int length = 0;
	while (1)
	{
		if (str[idx] == '\n')
		{
			length++;
		}
		idx++;
	}
	return length;
}

int main()
{
	string temp1, temp2;
	string* tempStr1 = new string;
	string* tempStr2 = new string;
	string* newStr = new string;

	cout << "String 1 :";
	getline(cin, temp1);
	cout << endl << "String 2 :";
	getline(cin, temp2);
	
	for (int i = 0; i <= strLen(temp1); i++)
	{
		tempStr1[i] = temp1[i];
	}
	for (int j = 0; j <= strLen(temp2); j++)
	{
		tempStr2[j] = temp2[j];
	}
	for (int k = 0; k <= strLen(temp1) + strLen(temp2); k++)
	{
		if (k <= strLen(temp1))
		{
			newStr[k] = tempStr1[k];
		}
		else
		{
			newStr[k] = tempStr2[k];
		}
		cout << newStr[k];
	}
	
	delete[] tempStr1;
	delete[] tempStr2;
	
	return 0; delete[] newStr;
}