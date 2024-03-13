//#include <iostream>
//#include <string>
//
//using namespace std;
//
//struct Node
//{
//	string FIO;
//	string birth_date;
//	int course;
//	double performance;
//	Node* next;
//};
//
//void find_greater(Node* top, string key, Node*& ppv)
//{
//	Node* pv = top;
//	ppv = top;
//	//����� �������� c ������ > key
//	while (pv && pv->FIO <= key)
//	{
//		ppv = pv;   // ���������� ����� ����������� ��������
//		pv = pv->next;
//	}
//}
//
//void add_element(Node*& top, string FIO, string birth_date, int course, int performance)
//{
//	Node* ppv = NULL;
//	Node* nv = new Node;
//	nv->FIO = FIO;
//	nv->birth_date = birth_date;
//	nv->course = course;
//	nv->performance = performance;
//	nv->next = NULL;
//	if (!top)
//	{
//		top = nv;
//	}
//	else
//	{
//		if (top->FIO >= FIO)
//		{
//			nv->next = top;
//			top = nv;
//		}
//		else
//		{
//			find_greater(top, FIO, ppv);
//			// ����� �� ����� ����� ��� ������ ��������
//			nv->next = ppv->next;
//			// ��������� ����� ���������� � �������� ppv � pv 
//			ppv->next = nv;
//		}
//	}
//}
//
//void print_list(Node* top)
//{
//	while (top)
//	{
//		cout << "-------------------------" << endl;
//		cout <<"FIO : "<< top->FIO << endl
//			<<"Birth date : "<<top->birth_date << endl
//			<<"Course : "<<top->course << endl
//			<<"Performance : "<< top->performance << endl;
//		top = top->next;
//	}
//}
//void find_less(Node* top, double key, int course, Node*& ppv) {
//    Node* pv = top;
//    ppv = pv;
//    do {
//        if (pv->performance < key && pv->course == course) {
//            return; // ������������� ������ �������
//        }
//        ppv = pv; // ���������� ���������� �������
//        pv = pv->next;
//    } while (pv);
//    ppv = NULL; // ���� ������ ��������� � ������� ������ ������
//}
//
//void del(Node*& top, double key, int course, Node*& bad_top)
//{
//    Node* pv, * ppv;
//
//    while (top) {
//        find_less(top, key, course, ppv);
//
//        if (ppv) {
//            if (ppv == top) { 
//                add_element(bad_top, top->FIO, top->birth_date, top->course, top->performance);
//                Node* temp = top;
//                top = top->next; 
//                delete temp; 
//            }
//            else { 
//                pv = ppv->next;
//                add_element(bad_top, pv->FIO, pv->birth_date, pv->course, pv->performance);
//                ppv->next = pv->next; 
//                delete pv; 
//            }
//        }
//        if (!ppv) { 
//            break; 
//        }
//    }
//}
//
//int main() {
//    Node* top = NULL;
//
//    cout << "Enter quantity of students: ";
//    int quantity;
//    cin >> quantity;
//
//    string FIO = "";
//    string birth_date = "";
//    int course;
//    double performance;
//
//    for (int i = 0; i < quantity; i++) {
//        cout << "Enter name: ";
//        cin >> FIO;
//        cout << "Enter birthday: ";
//        cin >> birth_date;
//        cout << "Enter course: ";
//        cin >> course;
//        cout << "Enter mark: ";
//        cin >> performance;
//
//        add_element(top, FIO, birth_date, course, performance);
//        cout << endl;
//    }
//
//    print_list(top);
//    cout << endl;
//    cout << "Enter the lowest posible mark: ";
//    double Low_Mark;
//    cin >> Low_Mark;
//    cout << " Enter course of studens:" << endl;
//    int bad_course;
//    cin >> bad_course;
//
//    Node* bad_top = NULL;
//
//    del(top, Low_Mark,bad_course, bad_top);
//    cout << endl;
//    cout << "Good students:" << endl;
//    print_list(top);
//    cout << endl;
//    cout << "Bad students:" << endl;
//    print_list(bad_top);
//    return 0;
//}
#include <iostream>
#include <string>

using namespace std;

struct Node
{
    string FIO;
    string birth_date;
    int course;
    double performance;
    Node* next;
};

void add_element(Node*& top, string FIO, string birth_date, int course, double performance)
{
    Node* nv = new Node;
    nv->FIO = FIO;
    nv->birth_date = birth_date;
    nv->course = course;
    nv->performance = performance;
    nv->next = top;
    top = nv;
}

void print_list(Node* top)
{
    while (top)
    {
        cout << "-------------------------" << endl;
        cout << "FIO : " << top->FIO << endl
            << "Birth date : " << top->birth_date << endl
            << "Course : " << top->course << endl
            << "Performance : " << top->performance << endl;
        top = top->next;
    }
}

void move_failing_students(Node*& top, Node*& bad_top, int course, double min_mark)
{
    Node* current = top;
    Node* prev = nullptr;

    while (current)
    {
        if (current->course == course && current->performance < min_mark)
        {
            if (prev)
            {
                prev->next = current->next; // ������� ������� ������� �� ��������� ������
            }
            else
            {
                top = current->next; // ��������� ������ ��������� ������
            }

            Node* temp = current; // ��������� ��������� �� ������� �������
            current = current->next; // ��������� � ���������� ��������

            temp->next = bad_top; 
            bad_top = temp; 
        }
        else
        {
            prev = current; 
            current = current->next;
        }
    }
}

int main()
{
    Node* students_list = nullptr;
    setlocale(LC_ALL, "");
    // ���������� �������� ������ � �������� ������ ���������
    add_element(students_list, "������ ����", "01.01.2000", 3, 4.5);
    add_element(students_list, "������ ����", "02.02.2001", 2, 3.2);
    add_element(students_list, "������� ������", "03.03.1999", 3, 2.8);
    add_element(students_list, "������� ����", "03.03.1999", 3, 1);

    cout << "�������� ������ ���������:" << endl;
    print_list(students_list);

    int target_course = 3; // ������� ���� ��� ������ ������������ ���������
    double min_mark = 3.0; // ����� ������ ��� ����������� ������������ ���������

    Node* failing_students_list = nullptr;

    move_failing_students(students_list, failing_students_list, target_course, min_mark);

    cout << endl<<"������ ������������ ��������� " << target_course << " �����:" << endl;
    print_list(failing_students_list);

    cout <<endl << "����������� ������ �������� ���������:" << endl;
    print_list(students_list);

    return 0;
}