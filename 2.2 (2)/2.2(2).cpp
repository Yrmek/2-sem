#include <iostream>
#include <time.h>
#include <iomanip>
#include "Header(2).h"

using namespace std;

void main()
{
	int matrix_size = 0;
	cout << "enter a matrix size:" << endl;
	cin >> matrix_size;
	double* matrix = new double [matrix_size];

	fill_matrix(matrix, matrix_size);
	matrix = get_result_matrix(matrix, matrix_size);
	cout << "final matrix :" << endl;
	print_matrix(matrix, matrix_size);

	delete[] matrix;
}