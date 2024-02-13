//9. Напишите функцию, возвращающую ссылку на максимальное число, встре -
//чающееся в заданном массиве произвольного размера(аргумент функции) больше
//одного раза.Если такого числа нет, то возвратить ссылку на максимальное число
//массива.Замените значение этого элемента нулевым значением.

#include <iostream>

using namespace std;

int& get_max_rep_num(int arr[],const short arr_size)
{
	int imax = 0;
	int rep_max_num = 0;
	bool is_rep_found = 0;
	bool if_arr_contains_rep_target = 1;

	for (int i = 0; i < arr_size; i++)
	{
		is_rep_found = 0;
		for (int j = 0; j < arr_size; j++)
		{
			if (i == j) continue;
			if (arr[i] == arr[j])
			{
				is_rep_found = 1;
				break;
			}
		}
		if (arr[i] > rep_max_num && is_rep_found)
		{
			imax = i;
			rep_max_num = arr[i];
		}
		if (is_rep_found) if_arr_contains_rep_target = 0;
	}
		if (if_arr_contains_rep_target)
		{
			for (int i = 0; i < arr_size; i++)
			{
				if (arr[imax] > arr[i]) imax = imax;
				else imax = i;
			}
			cout << "there are no reapeating numbers" << endl;
		}
		if (!if_arr_contains_rep_target)
			cout << "there are reapeating numbers in array" << endl;
	return arr[imax];
}

	void main()
{
	const short arr_size = 10;
	int arr[arr_size]{ 13,3,2,7,112,11,321,113,34,11 };
	get_max_rep_num(arr, arr_size) = 0;
	for (int i = 0; i < arr_size; i++)
	{
		cout << "|" << arr[i] << "|";
	}
}