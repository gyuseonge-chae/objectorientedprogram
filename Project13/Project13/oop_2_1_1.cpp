#include <iostream>

using namespace std;


int findMax(int arr1[], int size)
{
	int max = arr1[0];

	for (int i = 0; i < size; i++)
	{
		if (max < arr1[i])
		{
			max = arr1[i];
		}
		else
		{
			continue;
		}
	}
	return max;
}
int findMin(int arr1[], int size)
{
	int min = arr1[0];

	for (int i = 0; i < size; i++)
	{
		if (min >= arr1[i])
		{
			min = arr1[i];
		}
		else
		{
			continue;
		}
	}
	return min;
}

int* maxAddress(int arr2[], int size)
{
	int* maxPtr = &(arr2[0]);
	int a = findMax(arr2, size);

	for (int j = 0; j < size; j++)
	{
		if (arr2[j] == a)
		{
			maxPtr = &(arr2[j]);
		}
		else
		{
			continue;
		}
	}
	return maxPtr;
}
int* minAddress(int arr2[], int size)
{
	int* minPtr = &(arr2[0]);
	int a = findMin(arr2, size);

	for (int j = 0; j < size; j++)
	{
		if (arr2[j] == a)
		{
			minPtr = &(arr2[j]);
		}
		else
		{
			continue;
		}
	}
	return minPtr;
}

int main()
{
	int* ary = new int [10];

	for (int i = 0; i <= 9; i++)
	{
		ary[i] = rand() % 10;
		int* ptr = &(ary[i]);
		cout << "Memory Address is " << ptr << endl;
		cout << "Value is " << ary[i] << endl;
	}
	cout << "Max Data is " << findMax(ary, 10) << "(" << maxAddress(ary, 10) << ")" << endl;
	cout << "Min Data is " << findMin(ary, 10) << "(" << minAddress(ary, 10) << ")";
	
	delete[] ary;
	return 0;
}