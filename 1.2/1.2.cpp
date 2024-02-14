//Выполнить следующее задание для заданного текста.Оформить задание в
//виде набора функций : функция создания массива слов, функция получения результирующей строки.
//Текст – непустая последовательность символов.
//Слово – непустая последовательность любых символов, кроме символов - разделителей.
//Предложение – последовательность слов, разделенных одним или несколькими символами - разделителями.
//Символы - разделители : «пробел», «.», «, », « : », «; », «!», « ? », « - », «(», «)».

//Отредактировать заданное предложение, удаляя из него слова, которые уже
//встречались в предложении раньше.


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