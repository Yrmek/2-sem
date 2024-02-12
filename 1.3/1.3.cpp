//9. Напишите функцию, возвращающую ссылку на максимальное число, встре -
//чающееся в заданном массиве произвольного размера(аргумент функции) больше
//одного раза.Если такого числа нет, то возвратить ссылку на максимальное число
//массива.Замените значение этого элемента нулевым значением.

#include <iostream>

using namespace std;

int& get_max_repnum(int arr[],const short arr_size)
{
	int imax = 0;
	int repnum = 0;
	int repmaxnum = 0;
	bool if_repnum = 0;
	bool if_arr_repnum = 1;

	for (int i = 0; i < arr_size; i++)
	{
		if_repnum = 0;
		for (int j = 0; j < arr_size; j++)
		{
			if (i == j) continue;
			if (arr[i] == arr[j])
			{
				if_repnum = 1;
				break;
			}
		}
		if (arr[i] > repmaxnum && if_repnum)
		{
			imax = i;
			repmaxnum = arr[i];
		}
		if (if_repnum) if_arr_repnum = 0;
	}
		if (if_arr_repnum)
		{
			for (int i = 0; i < arr_size; i++)
			{
				if (arr[imax] > arr[i]) imax = imax;
				else imax = i;
			}
			arr[imax] = 0;
		}
	return arr[imax];
}

	void main()
{
	const short arr_size = 10;
	int arr[arr_size]{13,3,2,7,1,123,321,11,34,9};
	int x = get_max_repnum(arr, arr_size);
	cout << x << endl;
	for (int i = 0; i < arr_size; i++)
	{
		cout << "|" << arr[i] << "|";
	}
}