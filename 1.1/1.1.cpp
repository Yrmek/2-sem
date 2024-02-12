//��������� �������, ������� ��� ����� �������(�����, ������, ����������).�������� ������� � ������� ������������ ����� ���������.
//�������� ���������� ������� ������� n, ���������� ������� �������� �������� ����� �1, �, �nn, ������������� � ��� �� �������(��.����� �� �������).
//������� ����� / �������� ������� ����������� � �������������� ����������.

#include <iostream>
#include <iomanip>

using namespace std;

void create_conseq(int* arr, int arr_size)
{
	for (int i = 0; i < arr_size * arr_size; i++)
	{
		*(arr + i) = i + 1;
	}
}

void print_matrix(int** array,int arr_size)
{
	for (int i = 0; i < arr_size; i++)
	{
		cout << " " << endl;
		for (int j = 0; j < arr_size; j++)
			cout << "|" <<setw(8) << array[i][j] << "|";
	}
}

void fill_arr_via_spiral(int **matrix, int *arr, int arr_size)
{
	int i = 0,
		j = 0,
		up = 0,
		down = 0,
		right = 0,
		left = 0,
		iter = 0;
	while (iter < arr_size * arr_size)
	{
		*(*(matrix + i) + j) = *(arr + arr_size * arr_size - 1 - iter); // �������� �������� ������
		if (i == up && j < arr_size - right - 1)
			++j; 
		else if (j == arr_size - right - 1 && i < arr_size - down - 1) // �������� ��������� ����
			++i;
		else if (i == arr_size - down - 1 && j > left) // �������� �������� �����
			--j; 
		else
			--i; // �������� �� ������� �����

		// ������� ������� 
		if ((i == up + 1) && (j == left) )
		{
			++up;
			++down;
			++right;
			++left;
		}
		++iter;
	}
}

void main()
{
	int arr_size = 0;
	cout << "Enter array size :" << endl;
	cin >> arr_size;

	int ** matrix = new int*[arr_size];
	for (int i = 0; i < arr_size; i++)
	{
		matrix[i] = new int[arr_size];
	}
	int *arr = new int[arr_size];

	create_conseq(arr,arr_size);
	fill_arr_via_spiral(matrix,arr,arr_size);
	print_matrix(matrix,arr_size);

	for (int i = 0; i < arr_size; i++)
	{
		delete[] matrix[i];
	}
	delete[] matrix;
}