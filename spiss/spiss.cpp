#include <stdlib.h>
#include <iostream>

using namespace std;
struct Node 
{
    int x;
    Node* Next, * Prev;
};

class List
{
    Node* Head, * Tail;
public:
    List() :Head(NULL), Tail(NULL) {};
    ~List();
    void Show();
    void Add(int x);
};

List::~List()
{
    while (Head)
    {
        Tail = Head->Next;
        delete Head;
        Head = Tail;
    }
}

void List::Add(int x)
{
    Node* temp = new Node;
    temp->Next = NULL;
    temp->x = x;

    if (Head != NULL) //Если список не пуст
    {
        temp->Prev = Tail; 
        Tail->Next = temp; 
        Tail = temp;
    }
    else //Если список пустой
    {
        temp->Prev = NULL;
        Head = Tail = temp; 
    }
}

void List::Show()
{
    //СПИСОК С КОНЦА
    Node* temp = Tail;
    while (temp != NULL) 
    {
        cout << temp->x << " "; 
        temp = temp->Prev;
    }
    cout << "\n";

    //СПИСОК С НАЧАЛА
    temp = Head;
    while (temp != NULL)
    {
        cout << temp->x << " "; 
        temp = temp->Next;
    }
    cout << "\n";
}

int main()
{
    List lst; 
    lst.Add(1);
    lst.Add(2);
    lst.Add(3);
    lst.Add(4);
    lst.Add(5);
    lst.Add(6);
    lst.Add(7);

    lst.Show();

}