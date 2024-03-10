//Описать функцию, которая из списка символов L удаляет все вхождения
//списка L1(если такой есть).

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

void deleteSublist(Node*& top, Node* top1) 
{
	Node* current = top;
	Node* prev = nullptr;

	while (current != nullptr) 
	{
		if (current->symbol == top1->symbol) 
		{
			Node* tempMain = current;
			Node* tempSub = top1;

			while (tempMain != nullptr && tempSub != nullptr && tempMain->symbol == tempSub->symbol) 
			{
				tempMain = tempMain->next;
				tempSub = tempSub->next;
			}

			if (tempSub == nullptr) 
			{ 
				if (prev == nullptr) 
				{ 
					top = tempMain;
					current = top;
				}
				else 
				{
					prev->next = tempMain;
					current = prev; 
				}
			}
		}
		prev = current;
		if (current != nullptr) 
		{
			current = current->next;
		}
	}
}
int main()
{
	srand(time(NULL));
	cout << "Enter quantity of elements in lists" << endl;
	int quantity;
	int quantity1;
	cin >> quantity >>quantity1;

	Node* top_l = NULL;
	Node* top_l1 = NULL;

	fill_list(top_l, quantity);
	cout << "List L:" << endl;
	print_list(top_l);

	fill_list(top_l1, quantity1);
	cout << "List L1:" << endl;
	print_list(top_l1);

	deleteSublist(top_l, top_l1);
	cout << "Transformed list L without symbols of L1:" << endl;
	print_list(top_l);
	return 0;
}

void fill_list(Node*& top, int quantity)
{
	for (int i = 0; i < quantity; i++) {
		Node* ppv = NULL;
		Node* nv = new Node;
		cin >> nv->symbol; //rand() % 25 + 65;
		nv->next = NULL;
		if (!top)
			top = nv;
		else
		{
			nv->next = top;
			top = nv;
		}
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

