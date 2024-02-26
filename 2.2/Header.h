#pragma once
#include <iostream>
#include <time.h>
#include <iomanip>

using namespace std;

void print_matrix(double** matrix, int matrix_size)
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

void fill_matrix(double** matrix, int matrix_size)
{
	srand(time(NULL));
	for (int i = 0; i < matrix_size; i++)
	{
		for (int j = 0; j < matrix_size; j++)
		{
			*(*(matrix + i) + j) = rand() % 2;
		}
	}
	cout << "Entry matrix :" << endl;
	print_matrix(matrix, matrix_size);
}

double** multiply_matrix(double** matrix, int matrix_size)
{
	int sum = 0;
	double** temp_matrix = new double* [matrix_size];
	for (int i = 0; i < matrix_size; i++)
	{
		temp_matrix[i] = new double[matrix_size];
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

double** matrix_pow(double** matrix, int matrix_size, int power)
{
	int k_iter = log2(power);
	for (int i = 0; i < k_iter; i++)
	{
			matrix = multiply_matrix(matrix, matrix_size);
	}
	return matrix;
}

double** sum_matrix(double** matrix_1, double** matrix_2, int matrix_size)
{
	for (int i = 0; i < matrix_size; i++)
	{
		for (int j = 0; j < matrix_size; j++)
		{
			matrix_1[i][j] = matrix_1[i][j] + matrix_2[i][j];
		}
	}
	return matrix_1;
}

double** get_result_matrix(double** matrix, int matrix_size)
{
	return sum_matrix(sum_matrix(matrix_pow(matrix, matrix_size, 2), matrix, matrix_size), sum_matrix(matrix_pow(matrix, matrix_size, 4), matrix_pow(matrix, matrix_size, 8), matrix_size), matrix_size);
}
