//��������� ��������� ������� ��� ��������� ������.�������� ������� �
//���� ������ ������� : ������� �������� ������� ����, ������� ��������� �������������� ������.
//����� � �������� ������������������ ��������.
//����� � �������� ������������������ ����� ��������, ����� �������� - ������������.
//����������� � ������������������ ����, ����������� ����� ��� ����������� ��������� - �������������.
//������� - ����������� : �������, �.�, �, �, � : �, �; �, �!�, � ? �, � - �, �(�, �)�.

//��������������� �������� �����������, ������ �� ���� �����, ������� ���
//����������� � ����������� ������.


#include <iostream>
#include <iomanip>
#include <string.h>
#include <time.h> 

using namespace std;
void fill_c_string_manual(char str_arr[], const int arr_size)
{
	cout <<"Enter array of words : "<< endl;
	int i = 0;
	char symbol = 0;
	while (true)
	{
		cin >> symbol;
		i++;
		if (symbol == 0 || i == arr_size - 1) break;
	}
}

void fill_c_string_rand(char str_arr[], const int arr_size )
{
	srand(time(NULL));
	for (int i = 0; i < arr_size; i++)
	{
		str_arr[i] = rand() % 100 + rand () % 100;
	}
}
void print_string(char str_arr[], const int arr_size)
{
	for (int i = 0; i < arr_size; i++)
	{
		cout << str_arr[i];
	}
}

char edit_string(char str_arr[], const int arr_size)
{
	return 0;
}
void main()
{
	enum  enmArrInit
	{
		ByRand =1 , ByUser
	};
	short choice = 0;

	cout << "Chose an option :" << endl
		<< "a) To fill array by random write 1" << endl
		<< "b) To fill array manually write 2" << endl
		<< "other options will stop the programm" << endl;
	cin >> choice;
	const int arr_size = 100;
	char str_arr[arr_size]{};

	switch (choice)
	{
	case(ByRand):
		fill_c_string_rand(str_arr, arr_size);
		print_string(str_arr, arr_size);
		break;
		;
	case(ByUser):
		fill_c_string_manual(str_arr, arr_size);
		print_string(str_arr, arr_size);
		break;
		;
	}
}