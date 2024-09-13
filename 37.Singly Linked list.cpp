#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *next;

    // Constructor for the node
    node(int value)
    {
        data = value;
        next = nullptr;
    }
};

node *newnode, *temp;

// Create function that takes head by reference to a pointer
void create(node *&head, int value)
{
    newnode = new node(value);

    if (head == nullptr) // If the list is empty
    {
        head = temp = newnode;
    }
    else
    {
        temp->next = newnode; // Link the new node
        temp = newnode;       // Move temp to the new node
    }
}

// Display function
void display(node *head)
{
    temp = head;
    cout << endl;
    while (temp != nullptr) // Traverse till the end of the list
    {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

/// Delete head of list
void deleteAtHead(node *&head){
    node* todelete = head;
    head = head->next;
    delete todelete;
}

// Delete specific value from list
void deletion(node *&head, int value){
    node* temp = head;

    if(head == nullptr){  // If the list is empty
        return;
    }
    
    // Check if the value to be deleted is at the head
    if(head->data == value){
        deleteAtHead(head);
        return;
    }

    // Check if there is only one element in the list
    if(head->next == nullptr){
        deleteAtHead(head);
        return;
    }

    // Traverse to find the node before the target node
    while(temp->next->data!=value){
        temp = temp->next;
    }

    if(temp->next == nullptr){ // If the value is not found
        return;
    }

    node* todelete = temp->next;
    temp->next = temp->next->next;

    delete todelete;
}


//make a node and insert at first node
void insertTop(node *&head, int value)
{
    newnode = new node(value);
    temp = head;

    newnode->next = head;
    head = newnode;
}

//make a node and insert at specific position
void insertatPos(node *&head, int value)
{
    int pos;
    cout << "Enter position to insert value " << endl;
    cin >> pos;
    newnode = new node(value);

    temp = head;
}

//make a node and insert at specfic position
void insertEnd(node *&head, int value)
{
    newnode = new node(value);
    temp = head;

    temp = temp->next;
    while (temp->next != nullptr)
    {
        temp = temp->next;
    }
    temp->next = newnode;
}

node* reverse(node *&head){
    if(head==nullptr || head->next==nullptr){
        return head;
    }

    newnode =reverse(head->next);
    head->next->next=head;
    head->next=nullptr;
    return newnode;
}
int main()
{
    node *head = nullptr; // Head pointer initialized to nullptr (empty list)

    create(head, 10);
    create(head, 20);
    create(head, 30);

    insertTop(head, 5);
    insertEnd(head, 35);

    insertTop(head, 2);
    insertEnd(head, 40);
insertatPos(head,200);
    display(head); // Display the list

    deletion(head,30);

    deleteAtHead(head);
    display(head); // Display the list

    head=reverse(head);
    display(head); // Display the list

    return 0;
}
