#include <iostream>
#include <time.h>

using namespace std;

struct Node
{
	int num;
	Node* next;
	Node* prev;
};
void add_element(Node*& top, Node*& end, double key)
{
	Node* nv = new Node;
	nv->num = key;
	nv->next = NULL;
	nv->prev = NULL;
	if (!top)
	{
		top = nv;
		end = nv;
	}
	else
	{
		nv->next = top;
		top->prev = nv;
		top = nv;
	}
}

void fill_list(Node*& top, Node*& end, int quantity)
{
	srand(time(NULL));
	double key;
	for (int i = 0; i < quantity; i++)
	{
		key = rand() % 100;
		add_element(top, end, key);
	}
}

void print_list(Node* top)
{
	while (top)
	{
		cout << top->num << " " ;
		top = top->next;
	}
	cout << endl;
}

double find_min_sum(Node* top, Node* end)
{
	double min = top->num + end->num;
	do
	{
		if (min > top->num + end->num) min = top->num + end->num;
		top = top->next;
		end = end->prev;
	} while (top->next != end);
	return min;
}

int main()
{
	int n = 0;
	cout << "Enter value of n :" << endl;
	cin >> n;

	Node* top = NULL;
	Node* end = NULL;
	fill_list(top, end, 2*n);
	print_list(top);

	cout << "Min element =" << find_min_sum(top, end);
	return 0;
}