#include <iostream>
#include <time.h>
#include <iomanip>

using namespace std;

void print_matrix(int** matrix, int matrix_size)
{
	for (int i = 0; i < matrix_size; i++)
	{
		for (int j = 0; j < matrix_size; j++)
		{
			cout << "|" << setw(3) << *(*(matrix + i) + j) << "|";
		}
		cout << endl;
	}
}

void fill_matrix(int** matrix, int matrix_size)
{
	srand(time(NULL));
	for (int i = 0; i < matrix_size; i++)
	{
		for (int j = 0; j < matrix_size; j++)
		{
			*(*(matrix + i) + j) = rand() % 2;
		}
	}
	print_matrix(matrix, matrix_size);
}

int** multiply_matrix(int** matrix, int matrix_size)
{
	int sum = 0;
	int** temp_matrix = new int* [matrix_size];
	for (int i = 0; i < matrix_size; i++)
	{
		temp_matrix[i] = new int[matrix_size];
	}

	for (int j = 0; j < matrix_size; j++)
	{
		for (int i = 0; i < matrix_size; i++)
		{
			sum = 0;
			for (int k = 0; k < matrix_size; k++)
			{
				sum += matrix[j][k] * matrix[k][i];
			}
			temp_matrix[j][i] = sum;
		}
	}
	return temp_matrix;
	for (int i = 0; i < matrix_size; i++)
	{
		delete[] temp_matrix[i];
	}
	delete[] temp_matrix;
}

int** raise_matrix_to_power(int** matrix, int matrix_size, int power)
{
	int k_iter = power / 2;
	int** temp_matrix = new int* [matrix_size];
	for (int i = 0; i < matrix_size; i++)
	{
		temp_matrix[i] = new int[matrix_size];
	}

	temp_matrix = multiply_matrix(matrix, matrix_size);
	if (k_iter != 1)
	{
		for (int i = 0; i < k_iter; i++)
		{
			temp_matrix = multiply_matrix(temp_matrix, matrix_size);
		}
	}


	return temp_matrix;
	for (int i = 0; i < matrix_size; i++)
	{
		delete[] temp_matrix[i];
	}
	delete[] temp_matrix;
}

int** matrix_sum(int** matrix_1, int** matrix_2, int matrix_size)
{
	int** temp_matrix = new int* [matrix_size];
	for (int i = 0; i < matrix_size; i++)
	{
		temp_matrix[i] = new int[matrix_size];
	}
	for (int i = 0; i < matrix_size; i++)
	{
		for (int j = 0; j < matrix_size; j++)
		{
			temp_matrix[i][j] = matrix_1[i][j] + matrix_2[i][j];
		}
	}
	return temp_matrix;
	for (int i = 0; i < matrix_size; i++)
	{
		delete[] temp_matrix[i];
	}
	delete[] temp_matrix;
}

int** get_fin_matrix(int** matrix, int matrix_size)
{
	return matrix_sum(matrix_sum(raise_matrix_to_power(matrix, matrix_size, 2), matrix, matrix_size), matrix_sum(raise_matrix_to_power(matrix, matrix_size, 4), raise_matrix_to_power(matrix, matrix_size, 8), matrix_size),matrix_size);
}

void main()
{
	int matrix_size = 0;
	cout << "enter a matrix size:" << endl;
	cin >> matrix_size;

	int** matrix = new int* [matrix_size];
	for (int i = 0; i < matrix_size; i++)
	{
		matrix[i] = new int[matrix_size];
	}

	fill_matrix(matrix, matrix_size);
	matrix = get_fin_matrix(matrix, matrix_size);
	cout << endl;
	print_matrix(matrix, matrix_size);

	for (int i = 0; i < matrix_size; i++)
	{
		delete[] matrix[i];
	}
	delete[] matrix;
}