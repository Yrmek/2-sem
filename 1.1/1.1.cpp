#include <iostream>
#include <iomanip>
#include <time.h>  

using namespace std;

const int N = 5;

void input(int *arr)
{
	srand(time(NULL));
	cout << "enter sequence of 25 natural numbers:" << endl;
	for (int i = 0; i < 25; i++)
	{
		*(arr + i) = i;
	}
}

void output(int(*array)[N])
{
	for (int i = 0; i < N; i++)
	{
		cout << " " << endl;
		for (int j = 0; j < N; j++)
			cout << right << setfill(' ') << "|" << array[i][j] << left << setw(3) << "|";
	}
}

void fill(int (*matrix)[N], int *arr)
{
	int i = 0;
	int j = 0;
	int up = 0,
		down = 0,
		right = 0,
		left = 0;
	int k = 0;
	while (k <= N * N)
	{
		*(*matrix + j + i * N) = *(arr + 25 - k);
		if (i == up && j < N - right - 1)
			++j; // производится движение по столбцу вправо

		// Проверка возможности движения вниз
		else if (j == N - right - 1 && i < N - down - 1)
			++i; // производится движение по строкам вниз

		// Проверка возможности движения влево
		else if (i == N - down - 1 && j > left)
			--j; // производится движение по столбцу влево

		// Проверка возможности движения вверх
		else
			--i; // производится движение по строкам вверх

		// Сужение диапазона, если окружность заполнена
		if ((i == up + 1) && (j == left) && (left != N - right - 1))
		{
			++up;
			++down;
			++right;
			++left;
		}
		++k;
	}
}

int main()
{
	int matrix[N][N];
	int arr[25]{};
	input(arr);
	fill(matrix,arr);
	output(matrix);
	return 0;
}