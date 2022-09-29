#include <iostream>

using namespace std;

void makeHelixMat(unsigned int n, unsigned long long int** matrix)
{
	unsigned long long int** arr = new unsigned long long int* [n];
	for (unsigned int a = 0; a < n; a++)
	{
		arr[a] = new unsigned long long int[n];
	} // 행렬 공간 확보

	int row = 0, col = -1, rev = 1, value = 0;
	int p = n;

	while (1)
	{
		for (int i = 0; i < p; i++)
		{
			col = col + rev;
			arr[row][col] = value;
			value++;
		}
		p--;
		if (p == 0)
		{
			break;
		}
		for (int i = 0; i < p; i++)
		{
			row = row + rev;
			arr[row][col] = value;
			value++;
		}
		rev = -rev;
	}

	for (unsigned int x = 0; x < n; x++)
	{
		for (unsigned int y = 0; y < n; y++)
		{
			cout << arr[x][y] << "   ";
		}
		cout << endl;
	}

	for (unsigned int z = 0; z < n; z++)
	{
		delete[] arr[z];
	}
	delete[] arr; // 할당 해체

	return;
}

int main()
{
	unsigned int N = 0;
	cout << "Please enter the length of matrix :";
	cin >> N;
	cout << endl;

	unsigned long long int** matrix = new unsigned long long int* [N];
	for (unsigned int a = 0; a < N; a++)
	{
		matrix[a] = new unsigned long long int[N];
	} // 행렬 공간 확보

	makeHelixMat(N, matrix);

	for (unsigned int x = 0; x < N; x++)
	{
		delete[] matrix[x];
	}
	delete[] matrix;

	return 0;
}