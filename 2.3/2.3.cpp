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
//	//поиск элемента c ключом > key
//	while (pv && pv->FIO <= key)
//	{
//		ppv = pv;   // запоминаем адрес предыдущего элемента
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
//			// поиск по ключу места для нового элемента
//			nv->next = ppv->next;
//			// вставляем между элементами с адресами ppv и pv 
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
//            return; // останавливаем проход массива
//        }
//        ppv = pv; // запоминаем предыдущий элемент
//        pv = pv->next;
//    } while (pv);
//    ppv = NULL; // нету больше студентов с оценкой больше порога
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
                prev->next = current->next; // удаляем текущий элемент из исходного списка
            }
            else
            {
                top = current->next; // обновляем начало исходного списка
            }

            Node* temp = current; // сохраняем указатель на текущий элемент
            current = current->next; // переходим к следующему элементу

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
    // Добавление тестовых данных в исходный список студентов
    add_element(students_list, "Иванов Иван", "01.01.2000", 3, 4.5);
    add_element(students_list, "Петров Петр", "02.02.2001", 2, 3.2);
    add_element(students_list, "Сидоров Андрей", "03.03.1999", 3, 2.8);
    add_element(students_list, "Морозов Иван", "03.03.1999", 3, 1);

    cout << "Исходный список студентов:" << endl;
    print_list(students_list);

    int target_course = 3; // Целевой курс для поиска неуспевающих студентов
    double min_mark = 3.0; // Порог оценки для определения неуспевающих студентов

    Node* failing_students_list = nullptr;

    move_failing_students(students_list, failing_students_list, target_course, min_mark);

    cout << endl<<"Список неуспевающих студентов " << target_course << " курса:" << endl;
    print_list(failing_students_list);

    cout <<endl << "Обновленный список успешных студентов:" << endl;
    print_list(students_list);

    return 0;
}