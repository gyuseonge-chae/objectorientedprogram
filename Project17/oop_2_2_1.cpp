#include <iostream>
# include <string>

using namespace std;

int top = 0;

void push(int arr[], int n)
{
	arr[top] = n;
	top++;
	
} // push함수

void pop(int arr[])
{
	if (top < 0)
	{
		return;
	}
	else
	{
		--top;
		arr[top] = 0;
	}
} // pop함수

int main()
{
	string command;
	int* stack = new int[100];
	
	while (1)
	{
		cout << "Plesase Enter Command(push, pop) :";
		cin >> command;

		if (command == "push")
		{
			int input;
			cin >> input;
			push(stack, input);

			for (int i = 0; i < top; i++)
			{
				cout << stack[i] << endl;
			}
			continue;
		}
		else
		{
			pop(stack);

			for (int j = 0; j < top; j++)
			{
				cout << stack[j] << endl;
			}
			continue;
		}
	}

	delete[] stack;

	return 0;
}