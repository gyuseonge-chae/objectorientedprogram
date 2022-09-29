#include <iostream>
# include <fstream>

using namespace std;

void bubbleUp(int list[], int current, int last)
{
	for (int walker = last; walker > current; walker--)
	{
		if (list[walker] < list[walker - 1])
		{
			int temp = list[walker];
			list[walker] = list[walker - 1];
			list[walker - 1] = temp;
		}
	}
	return;
}

void ascnd_ord(int list[], int last)
{
	for (int current = 0; current < last; current++)
	{
		bubbleUp(list, current, last);
	}
	return;
}



int main()
{
	int input_array[20] = { 0 };
	fstream assgn;
	assgn.open("Assignment.txt");

	if (assgn.is_open())
	{
		cout << "Input array :";
		for (int i = 0; i <= 19; i++)
		{
			assgn >> input_array[i];
			cout << input_array[i] << " ";
		}
		cout << endl;
		int output_array[20] = { 0 }; //sorting 전 과정
		
        ascnd_ord(input_array, 19); //sorting 중

		cout << "Sorted array :";
		for (int j = 0; j <= 19; j++)
		{
			output_array[j] = input_array[j];
			cout << output_array[j] << " ";
		}
	}
	else
	{
		cout << "Cannot read file";
	}
	assgn.close();
	return 0;
}