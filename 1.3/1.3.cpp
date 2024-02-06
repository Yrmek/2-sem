//9. Напишите функцию, возвращающую ссылку на максимальное число, встре -
//чающееся в заданном массиве произвольного размера(аргумент функции) больше
//одного раза.Если такого числа нет, то возвратить ссылку на максимальное число
//массива.Замените значение этого элемента нулевым значением.

#include <iostream>

using namespace std;

int& maxnum(int arr[],const short N)
{
	int imax = 0;
	int Repnum = 0;
	int Repmaxnum = 0;
	bool Boba = 0;
	bool Biba = 1;

	for (int i = 0; i < N; i++)
	{
		Boba = 0;
		for (int j = 0; j < N; j++)
		{
			if (i == j) continue;
			if (arr[i] == arr[j])
			{
				Boba = 1;
				break;
			}
		}
		if (arr[i] > Repmaxnum && Boba)
		{
			imax = i;
			Repmaxnum = arr[i];
		}
		if (Boba) Biba = 0;
	}
		if (Biba)
		{
			for (int i = 0; i < N; i++)
			{
				if (imax = arr[imax] > arr[i]) imax = imax;
				else imax = i;
			}
			arr[imax] = 0;
		}
	return arr[imax];
}

	void main()
{
	const short N = 10;
	int arr[N]{1,3,2,7,1,123,7,11,9,9};
	int x = maxnum(arr, N);
	cout << x << endl;
	for (int i = 0; i < N; i++)
	{
		cout << "|" << arr[i] << "|";
	}
}