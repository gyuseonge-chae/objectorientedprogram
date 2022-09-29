#include <iostream>

using namespace std;

int main()
{
	int rowA, rowB, colA, colB;

	cout << "Matrix A :";
	cin >> rowA >> colA;
	cout << endl << "Matrix B :";
	cin >> rowB >> colB; // 행렬 크기 입력받기
	
	int** matrixA = new int* [rowA];
	for (int a = 0; a < rowA; a++)
	{
		matrixA[a] = new int[colA];
	}

	int** matrixB = new int* [rowB];
	for (int b = 0; b < rowB; b++)
	{
		matrixB[b] = new int[colB];
	}// 각 행렬들의 틀 세팅

	for (int x = 0; x < rowA; x++)
	{
		for (int y = 0; y < colA; y++)
		{
			matrixA[x][y] = rand() % 10 + 1;
			cout << matrixA[x][y] << "      ";
		}
		cout << endl;
	}

	cout << endl;

	for (int z = 0; z < rowB; z++)
	{
		for (int w = 0; w < colB; w++)
		{
			matrixB[z][w] = rand() % 10 + 1;
			cout << matrixB[z][w] << "      ";
		}
		cout << endl;
	}// 각 행렬에 숫자를 채움

	int** res = new int* [rowA];
	for (int c = 0; c < rowA; c++)
	{
		res[c] = new int[colB];
	}

	if (colA != rowB)
	{
		cout << "Can't Operate Matrix Multiplocation(" << rowB << "!=" << colA << ")";
	}
	else
	{
		cout << endl << "A*B Result :" << endl;
		
		for (int i = 0; i < rowA; i++)
	    {
		    for (int j = 0; j < colB; j++)
		    {
				res[i][j] = 0;
				for (int k = 0; k < colA; k++)
				{
					res[i][j] += matrixA[i][k] * matrixB[k][j];
				}
		    }
	    }
		for (int m = 0; m < rowA; m++)
		{
			for (int n = 0; n < colB; n++)
			{
				cout << res[m][n] << "    ";
			}
			cout << endl;
		}
	} // 행렬 곱 출력

	for (int d = 0; d < colA; d++)
	{
		delete matrixA[d];
	}
	delete[] matrixA;

	for (int e = 0; e < colB; e++)
	{
		delete[] matrixB[e];
	}
	delete[] matrixB; 

	for (int f = 0; f < colB; f++)
	{
		delete[] res[f];
	}
	delete[] res; // 각 행렬들 할당 해체

return 0;
}