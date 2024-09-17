#include <iostream>
using namespace std;
class node
{
public:
    int data;
    node *next, *prev;

    node(int value)
    {
        data = value;
        next = nullptr;
        prev = nullptr;
    }
};
node *newnode, *temp;
void create(node *&head, int value)
{
    newnode = new node(value);

    if (head == nullptr)
    {
        head = newnode;
    }
    else
    {
        temp = head;
        while (temp->next != nullptr)
        {
            temp = temp->next;
        }

        temp->next = newnode;
        newnode->prev = temp;
    }
}
void insertAtFirst(node *&head, int value)
{
    newnode = new node(value);
    if (head == nullptr)
    {
        head = newnode;
    }
    else
    {
        newnode->next = head;
        head->prev = newnode;
        head = newnode;
    }
}
void insert(node *&head, int value)
{
    create(head, value);
}
void display(node *&head)
{
    temp = head;
    while (temp != nullptr)
    {
        cout << temp->data;
        if (temp->next != nullptr)
        {
            cout << "->";
        }
        temp = temp->next;
    }
}

void insertAtPos(node *&head, int value, int pos)
{
    newnode = new node(value);
    temp = head;
    for (int i = 1; i < pos - 1 && temp != nullptr; i++)
    {
        temp = temp->next;
    }

    if (temp != nullptr)
    {
        newnode->next = temp->next;
        temp->next = newnode;
    }
}
void Count(node *&head)
{
    temp = head;
    int a = 0;
    while (temp != nullptr)
    {
        ++a;
        temp = temp->next;
    }
    cout << "\nThere are " << a << " nodes in the list" << endl;
}
/*
void deleteAtPos(node *&head int Pos){
    temp=head;
    if(head==nullptr){
        cout<<"List is empty "<<endl;
    }
    else{
        if(head->next ==nullptr){
            delete head;
            return;
        }
        else{
            for(int i = 1; i < pos - 1 && temp != nullptr; i++){
                break;
            }
            temp->next
        }
    }
}*/
void deleteAtTail(node *&head)
{
    temp = head;
    if (head == nullptr)
    {
        cout << "List is empty " << endl;
        return;
    }
    else
    {

        if (head->next == nullptr)
        {
            delete head;
            head=nullptr;
            return;
        }
        else
        {
            while (temp->next != nullptr)
            {
                temp = temp->next;
            }
            temp->prev->next=nullptr;
            delete temp;
        }
    }
}
void deleteAtHead(node *&head)
{
    temp = head;
    if (head == nullptr)
    {
        cout << "The list is empty " << endl;
        return;
    }
    else
    {
        if (head->next == nullptr)
        {
            delete head;
            return;
        }
        else
        {
            head = head->next;
            head->prev = nullptr;
            delete temp;
        }
    }
}
int main()
{
    node *head = nullptr;
    // Create a node
    create(head, 2);
    create(head, 3);
    create(head, 4);
    insert(head, 8);

    // insert at first position
     insertAtFirst(head, 1);

    // insert at given position
     insertAtPos(head, 20, 3);

    // delete a head node
     deleteAtHead(head);

    // delete last node
     deleteAtTail(head);
    // display list of nodes
    display(head);

    // count the node
    Count(head);
}