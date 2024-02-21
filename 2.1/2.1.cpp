//Выполнить задание, используя динамическое выделение памяти для одномер -
//ного массива.Дана последовательность натуральных чисел, в которой каждое
//число
//104.Последовательность генерируется случайным образом или вводится с
//клавиатуры.Длина последовательности n
// 109. Получить итоговый массив за
//один просмотр элементов(не храня в памяти всю последовательность)

//9. образованный из чисел, встречающихся в исходной последовательности ровно
//два раза, по убыванию(без повторений);

#include <iostream>
#include <iomanip>
#include <time.h>

using namespace std;

int get_paired_numbers(int arr[],int if_pair[], int arr_size, int max_num_size)
{
	enum  enmArrayInit
	{
		by_rand = 1, manually
	};
	int choice = 0;
	cout << "Chose an option :" << endl
		<< "a) To fill array by random write 1" << endl
		<< "b) To fill array manually write 2" << endl
		<< "other options will stop the programm" << endl;
	cin >> choice;
	switch (choice)
	{
	case by_rand:
		srand(time(NULL));
		for (int i = 0; i < arr_size; i++)
		{
			arr[i] = rand() % 100;
			cout << "|" << setw(4) << arr[i] << "|";
			if_pair[arr[i]] += 1;
		}
		break;
	case manually:
		for (int i = 0; i < arr_size; i++)
		{
			cin >> arr[i];
			if_pair[arr[i]] += 1;
		}
		break;
	default:   return 0;
	}
	cout << endl << "Array of paired numbers" << endl;
	for (int i = max_num_size - 1; i >= 0; i--)
	{
		if (if_pair[i] == 2)
			cout << "|" << setw(5) << i << "|";
	}
	return 0;
}
int main()
{
	int arr_size = 10e09;
	cout << "Enter an array size:" << endl;
	cin >> arr_size;
	int max_num_size = 10e4;
	int* if_pair = new int[max_num_size]{0};
	int* sequence = new int[arr_size];
	get_paired_numbers(sequence, if_pair, arr_size, max_num_size);
	delete[] if_pair;
	delete[] sequence;
	return 0;
}
