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
    cout << "������� ���������� ��������� � �������" << endl;
    int quantity1;
    int quantity2;
    cin >> quantity1;
    cin >> quantity2;

    Node* top_l = NULL;
    Node* top_l1 = NULL;

    fill_list(top_l, quantity1);
    cout << "������ L:" << endl;
    print_list(top_l);

    fill_list(top_l1, quantity2);
    cout << "������ L1:" << endl;
    print_list(top_l1);

    myfunction(top_l, top_l1);
    cout << "��������������� ������ L ��� �������� �� L1:" << endl;
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
            if (prev == nullptr) // ���� ���������� � ������ ������
            {
                temp = current;
                current = current->next;
                delete temp;
                top = current; // ��������� ������ ������
            }
            else
            {
                temp = current;
                prev->next = current->next; // ������� ���� �� �������� ������
                current = current->next; // ��������� � ���������� ����
                delete temp; // ������� ������� ����
            }
        }
        else
        {
            prev = current; // ��������� � ���������� ����
            current = current->next; // ��������� � ���������� ����
        }

        if (current == nullptr) // ���� �������� ����� ������ L, ��������� � ���������� ������� � ������ L1
        {
            top1 = top1->next; // ��������� � ���������� ������� � ������ L1
            current = top; // ������������ � ������ ������ L ��� ������� ������� � ������ L1
            prev = nullptr; // ���������� prev ��� ������� ������� � ������ L1
        }
    }
}