//Описать функцию, которая из списка символов L удаляет все вхождения
//списка L1(если такой есть).

#include <iostream>
#include <iomanip>
#include <time.h>
#include <windows.h>

using namespace std;

struct Node
{
	char symbol;
	Node* next;
};

void print_list(Node*);
void fill_list(Node*&, int);
bool search_element(Node*, char);
void find_equal_element(Node*, char, Node*&);
void del_element(Node*&, char);
void myfunction(Node*&, Node*);

int main()
{
	srand(time(NULL));
	cout << "Enter quantity of elements in lists" << endl;
	int quantity;
	cin >> quantity;

	Node* top_l = NULL;
	Node* top_l1 = NULL;

	fill_list(top_l, quantity);
	cout << "List L:" << endl;
	print_list(top_l);

	fill_list(top_l1, quantity);
	cout << "List L1:" << endl;
	print_list(top_l1);

	myfunction(top_l, top_l1);
	cout << "Transformed list L without symbols of L1:" << endl;
	print_list(top_l);
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
		Node* ppv = NULL;
		Node* nv = new Node;
		nv->symbol = rand() % 100 + 50;
		nv->next = NULL;
		if (!top)
			top = nv;
		else
		{
			nv->next = top;
			top = nv;
		}
	}
	Sleep(10);
}

void del_element(Node*& top, char key)
{
	Node* pv, * ppv;
	find_equal_element(top, key, ppv);
	pv = ppv->next;
	if (pv)
	{
		if (top->symbol == key)
			top = top->next;
		else
			ppv->next = pv->next;

		delete pv;
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

bool search_element(Node* top, char key)
{
	bool k = 0;
	while (top) {
		if (key == top->symbol)
		{
			k = 1;
		}
		top = top->next;
	}
	return k;
}

void myfunction(Node*& top, Node* top1)
{
	char key;
	while (top1)
	{
		key = top1->symbol;
		if (search_element(top, key))
		{
			del_element(top, key);
		}
		top1 = top1->next;
	}
}

