#include <iostream>
using namespace std;

// Making a node struct containing a data int and a pointer
// to another node
struct Node { 
  int data; 
  Node *next; 
};

class LinkedList
{
    // Head pointer
    Node* head;

  public:
    // default constructor. Initializing head pointer
    LinkedList()
    {
      head = NULL;
    }

    // inserting elements (At start of the list)
    void insert(int val)
    {
      // make a new node
      Node* new_node = new Node;
      new_node->data = val;
      new_node->next = NULL;

      // If list is empty, make the new node, the head
      if (head == NULL)
        head = new_node;
      // else, make the new_node the head and its next, the previous
      // head
      else
      {
        new_node->next = head;
        head = new_node;
      }
    }

    // loop over the list. return true if element found
    bool search(int val)
    {
      Node* temp = head;
      while(temp != NULL)
      {
        if (temp->data == val)
          return true;
        temp = temp->next;
      }
      return false;
    }

    
    void remove(int val)
    {
      // If the head is to be deleted
      if (head->data == val)
      {
        delete head;
        head = head->next;
        return;
      }

      // If there is only one element in the list
      if (head->next == NULL)
      {
        // If the head is to be deleted. Assign null to the head
        if (head->data == val)
        {
          delete head;
          head = NULL;
          return;
        }
        // else print, value not found
        cout << "Value not found!" << endl;
        return;
      }

      // Else loop over the list and search for the node to delete
      Node* temp = head;
      while(temp->next!= NULL)
      {
        // When node is found, delete the node and modify the pointers
        if (temp->next->data == val)
        {
          Node* temp_ptr = temp->next->next;
          delete temp->next;
          temp->next = temp_ptr;
          return;
        }
        temp = temp->next;
      }

      // Else, the value was neve in the list
      cout << "Value not found" << endl;
    }

    void display()
    {
      Node* temp = head;
      while(temp != NULL)
      {
        cout << temp->data << " ";
        temp = temp->next;
      }
      cout << endl;
    }
};

int main() {
  
    LinkedList l;
    int n, operasi;
    char pilihan;
    
    do{
    // inserting elements
    cout << "Masukkan elemen2: ";
    std::cin >> n;
    l.insert(n);
    
    cout << "\nCurrent Linked List: ";
    l.display();

    cout << "\nIngin memasukkan lagi?(y/t): ", cin >> pilihan;
    }while (pilihan == 'Y' || pilihan == 'y');

    pilihan = 'f';

    do{
    cout << "Operasi yang tersedia\n";
    cout << "Code\t Operation\n";
    cout << "1.\t Delete\n";
    cout << "2.\t Insert\n";
    cout << "3.\t Search\n";
    cout << "4.\t Display\n";

    cout << "Input kode: ", cin >> operasi;
    cin.ignore();

    switch (operasi)
    {
        case 1:
            l.display();
            cout << "Remove?: ", cin >> n;
            l.remove(n);
            l.display();
            break;

        case 2:
            l.display();
            cout << "Add?: ", cin >> n;
            l.insert(n);
            l.display();
            break;

        case 3:
            l.display();
            cout << "Search?: ", cin >> n;
            l.search(n);
            break;

        case 4:
            l.display();
            break;
    }

    cout << "Ada lagi?(y/t): ", cin >> pilihan;
    }while(pilihan=='y' || pilihan=='Y');

}