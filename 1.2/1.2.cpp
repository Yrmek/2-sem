//��������� ��������� ������� ��� ��������� ������.�������� ������� �
//���� ������ ������� : ������� �������� ������� ����, ������� ��������� �������������� ������.
//����� � �������� ������������������ ��������.
//����� � �������� ������������������ ����� ��������, ����� �������� - ������������.
//����������� � ������������������ ����, ����������� ����� ��� ����������� ��������� - �������������.
//������� - ����������� : �������, �.�, �, �, � : �, �; �, �!�, � ? �, � - �, �(�, �)�.

//��������������� �������� �����������, ������ �� ���� �����, ������� ���
//����������� � ����������� ������.

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string.h>

using namespace std;

void RemoveDuplicateWords(char* str_arr, const int arr_size) {
    char* words[20]; // ������ ���������� �� �����
    char sep_symbols[] = " .,:;!?-()"; // ����������� ����
    int words_quant = 0;

    // ��������� ������ �� �����
    char* word = strtok(str_arr, sep_symbols);
    while (word != nullptr) {
        // ��������� ������� ����� � ���������� �������
        bool duplicate = false;
        for (int i = 0; i < words_quant; i++) {
            if (strcmp(words[i], word) == 0) {
                duplicate = true;
                break;
            }
        }
        // ���� ����� ����������, ��������� ��� � ������
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