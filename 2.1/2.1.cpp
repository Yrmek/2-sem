//Выполнить задание, используя динамическое выделение памяти для одномер -
//ного массива.Дана последовательность натуральных чисел, в которой каждое
//число
//104.Последовательность генерируется случайным образом или вводится с
//клавиатуры.Длина последовательности n
// 109. Получить итоговый массив за
//один просмотр элементов(не храня в памяти всю последовательность)

#include <iostream>
#include <iomanip>
#include <time.h>

using namespace std;

void fill_arr_manually(int arr[],  int arr_size)
{
	for (int i = 0; i < arr_size; i++)
	{
		cin >> arr[i];
	}
}

void fill_arr_by_rand(int arr[],  int arr_size)
{
	srand(time(NULL));
	for (int i = 0; i < arr_size; i++)
	{
		arr[i] = rand() % 100;
	}
}
void print_arr(int arr[],int arr_size)
{
	for (int i = 0; i < arr_size; i++)
	{
		cout << "|" << arr[i] << "|";
	}
	cout << " " << endl;
}

void quicksort(int arr[], int left, int right)
{
	int i = left, j = right;
	int mid = arr[(left + right) / 2];
	do 
	{
		while (arr[i] > mid) i++;
		while (arr[j] < mid) j--;
		if (i <= j) 
		{
			int temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
			i++; j--;
		}
	} while (i < j);
	if (left < j) quicksort(arr, left, j);
	if (i < right) quicksort(arr, i, right);
}

int get_pair_numbers(int arr[], int arr_size, int final_arr[])
{
	int bufnum = arr[0];
	int j = 0;
	for (int i = 1; i < arr_size; i++)
	{
		if (arr[i] == arr[i + 1] && arr[i] != arr[i - 1] && arr[i] != arr[i + 2])
		{
			final_arr[j] = arr[i];
			j++;
			bufnum = arr[i];
		}
	}
	return j;
}
int main()
{
	int arr_size = 10e09;
	int pair_arr_size = 10e03;
	int* sequence = new int[arr_size];
	int* pair_sequence = new int[pair_arr_size];
	int fin_arr_size = 0;
	enum  enmArrayInit
	{
		by_rand = 1, manually
	};

	int choice = 0;
	cout << "write an array size:" << endl;
	cin >> arr_size;
	cout << "Chose an option :" << endl
		<< "a) To fill array by random write 1" << endl
		<< "b) To fill array manually write 2" << endl
		<< "other options will stop the programm" << endl;
	cin >> choice;

	switch (choice)
	{
	case by_rand:
		fill_arr_by_rand(sequence, arr_size);
		quicksort(sequence, 0, arr_size);
		print_arr(sequence, arr_size);
		fin_arr_size = get_pair_numbers(sequence, arr_size, pair_sequence);
		print_arr(pair_sequence, fin_arr_size);
		break;

	case manually:
		fill_arr_manually(sequence, arr_size);
		quicksort(sequence, 0, arr_size);
		print_arr(sequence, arr_size);
		fin_arr_size = get_pair_numbers(sequence, arr_size, pair_sequence);
		print_arr(pair_sequence, fin_arr_size);
		break;

	default: return 0;
	}
	delete[] sequence;
	delete[] pair_sequence;
	return 0;
}
