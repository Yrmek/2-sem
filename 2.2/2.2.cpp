//Дана вещественная квадратная матрица А порядка n.Составить функцию для
//получения матрицы B = А + А2 + А
//4 + А8


#include <iostream>
#include <time.h>
#include <iomanip>
#include "Header.h"

using namespace std;

void main()
{
	int matrix_size = 0;
	cout << "enter a matrix size:" << endl;
	cin >> matrix_size;

	double** matrix = new double* [matrix_size];
	for (int i = 0; i < matrix_size; i++)
	{
		matrix[i] = new double[matrix_size];
	}

	fill_matrix(matrix, matrix_size);
	matrix = get_result_matrix(matrix, matrix_size);
	cout <<"final matrix :"<< endl;
	print_matrix(matrix, matrix_size);

	for (int i = 0; i < matrix_size; i++)
	{
		delete[] matrix[i];
	}
	delete[] matrix;
}