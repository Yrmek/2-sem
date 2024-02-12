//Выполнить задание, оформив его через функции(ввода, вывода, заполнение).Передачу массива в функции организовать через указатели.
//Получить квадратную матрицу порядка n, элементами которой являются заданные числа а1, …, аnn, расположенные в ней по спирали(см.схему на рисунке).
//Перебор строк / столбцов матрицы осуществить с использованием указателей.

#include <iostream>
#include <iomanip>
/*#include <time.h> */ 

using namespace std;

void fill_arr_consequence(int* arr, int arr_size)
{
	/*srand(time(NULL));*/
	cout << "enter sequence of "<<arr_size * arr_size<<" natural numbers : " << endl;
	for (int i = 0; i < arr_size * arr_size; i++)
	{
		*(arr + i) = i + 1;
		cout << arr[i] << endl;
	}
}

void display_spiral(int** array,int arr_size)
{
	for (int i = 0; i < arr_size; i++)
	{
		cout << " " << endl;
		for (int j = 0; j < arr_size; j++)
			cout << "|" <<setw(3) << array[i][j] << setw(3) << "|";
	}
}

void spiral_array(int **matrix, int *arr, int arr_size)
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
		*(*(matrix + i) + j) = *(arr + arr_size * arr_size - 1 - iter); // проверка движения вправо
		cout << matrix[i][j] << endl;
		if (i == up && j < arr_size - right - 1)
			++j; 
		else if (j == arr_size - right - 1 && i < arr_size - down - 1) // проверка движенгия вниз
			++i;
		else if (i == arr_size - down - 1 && j > left) // проверка движения влево
			--j; 
		else
			--i; // движение по строкам вверх

		// Сужение спирали 
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

	fill_arr_consequence(arr,arr_size);
	spiral_array(matrix,arr,arr_size);
	display_spiral(matrix,arr_size);

	for (int i = 0; i < arr_size; i++)
	{
		delete[] matrix[i];
	}
	delete[] matrix;
}