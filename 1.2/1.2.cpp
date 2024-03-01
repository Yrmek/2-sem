//Выполнить следующее задание для заданного текста.Оформить задание в
//виде набора функций : функция создания массива слов, функция получения результирующей строки.
//Текст – непустая последовательность символов.
//Слово – непустая последовательность любых символов, кроме символов - разделителей.
//Предложение – последовательность слов, разделенных одним или несколькими символами - разделителями.
//Символы - разделители : «пробел», «.», «, », « : », «; », «!», « ? », « - », «(», «)».

//Отредактировать заданное предложение, удаляя из него слова, которые уже
//встречались в предложении раньше.

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string.h>

using namespace std;

void RemoveDuplicateWords(char* str_arr, const int arr_size) {
    char* words[20]; // Массив указателей на слова
    char sep_symbols[] = " .,:;!?-()"; // Разделители слов
    int words_quant = 0;

    // Разбиваем строку на слова
    char* word = strtok(str_arr, sep_symbols);
    while (word != nullptr) {
        // Проверяем наличие слова в уникальном массиве
        bool duplicate = false;
        for (int i = 0; i < words_quant; i++) {
            if (strcmp(words[i], word) == 0) {
                duplicate = true;
                break;
            }
        }
        // Если слово уникальное, добавляем его в массив
        if (!duplicate) {
            words[words_quant] = word;
            words_quant++;
        }
        word = strtok(nullptr, sep_symbols);
    }

    char new_str[40];
    new_str[0] = '\0';
    for (int i = 0; i < words_quant; i++) {
        strcat(new_str, words[i]);
        strcat(new_str, " ");
    }
    strcpy(str_arr, new_str);
}

int main() {
    const int arr_size = 40;
    char str_arr[arr_size];

    cout << "Enter array of words : " << endl;
    cin.getline(str_arr, arr_size);

    RemoveDuplicateWords(str_arr, arr_size);

    cout << "Text after removing duplicate words:" << endl << str_arr << endl;

    return 0;
}