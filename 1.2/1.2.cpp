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

}

void fill_c_string_rand(char str_arr[], const int arr_size )
{
	srand(time(NULL));
	for (int i = 0; i < arr_size; i++)
	{
		str_arr[i] = rand() % 100 + rand () % 100;
	}
}

char edit_string(char str_arr[], const int arr_size)
{

}
void main()
{
	enum  enmArrInit
	{
		ByRand , ByUser
	};
	short choice = 0;

	cout << "Chose an option :" << endl
		<< "a) To fill array by random write 1" << endl
		<< "b) To fill array manually write 2" << endl
		<< "other options will stop the programm" << endl;
	cin >> choice;

	switch (choice)
	{


	}
}