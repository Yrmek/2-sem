#include <iostream>
#include <iomanip>
#include <time.h>

using namespace std;

struct Node
{
    char symbol;
    Node* next;
};

void print_list(Node*);
void fill_list(Node*&, int);
void find_equal_element(Node*, char, Node*&);
void del_list(Node*&);
void del_element(Node*&, char);
void myfunction(Node*&, Node*);

int main()
{
    setlocale(LC_ALL, "");
    srand(time(NULL));
    cout << "Введите количество элементов в списках" << endl;
    int quantity1;
    int quantity2;
    cin >> quantity1;
    cin >> quantity2;

    Node* top_l = NULL;
    Node* top_l1 = NULL;

    fill_list(top_l, quantity1);
    cout << "Список L:" << endl;
    print_list(top_l);

    fill_list(top_l1, quantity2);
    cout << "Список L1:" << endl;
    print_list(top_l1);

    myfunction(top_l, top_l1);
    cout << "Преобразованный список L без символов из L1:" << endl;
    print_list(top_l);

    del_list(top_l);
    del_list(top_l1);

    return 0;
}

void find_equal_element(Node* top, char key, Node*& ppv)
{
    Node* pv = top;
    ppv = top;

    while (pv && pv->symbol != key)
    {
        ppv = pv;
        pv = pv->next;
    }
}

void fill_list(Node*& top, int quantity)
{
    for (int i = 0; i < quantity; i++) {
        Node* nv = new Node;
        cin >> nv->symbol; /*= rand() % 25 + 65;*/
        nv->next = top;
        top = nv;
    }
}


void del_list(Node*& top)
{
    while (top) {
        Node* temp = top;
        top = top->next;
        delete temp;
    }
}

void print_list(Node* top)
{
    while (top) {
        cout << top->symbol << " ";
        top = top->next;
    }

    cout << endl;
}

void myfunction(Node*& top, Node* top1)
{
    Node* current = top;
    Node* prev = nullptr;
    Node* temp;

    while (current && top1)
    {
        if (current->symbol == top1->symbol)
        {
            if (prev == nullptr) // Если совпадение в начале списка
            {
                temp = current;
                current = current->next;
                delete temp;
                top = current; // Обновляем начало списка
            }
            else
            {
                temp = current;
                prev->next = current->next; // Удаляем узел из середины списка
                current = current->next; // Переходим к следующему узлу
                delete temp; // Удаляем текущий узел
            }
        }
        else
        {
            prev = current; // Переходим к следующему узлу
            current = current->next; // Переходим к следующему узлу
        }

        if (current == nullptr) // Если достигли конца списка L, переходим к следующему символу в списке L1
        {
            top1 = top1->next; // Переходим к следующему символу в списке L1
            current = top; // Возвращаемся в начало списка L для каждого символа в списке L1
            prev = nullptr; // Сбрасываем prev для каждого символа в списке L1
        }
    }
}