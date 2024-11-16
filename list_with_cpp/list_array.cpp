#include <iostream>
using namespace std;

template <typename T>
class Node
{
public:
    T data;
    Node *next;

    // Constructor
    Node(T value)
    {
        data = value;
        next = nullptr;
    }
};

// List class to manage the linked list
template <typename T>
class List
{
private:
    Node<T> *head; // Points to first node
    int size;      // Number of nodes in list

public:
    // Constructor - create empty list
    List()
    {
        head = nullptr;
        size = 0;
    }

    // Destructor - clean up memory
    ~List()
    {
        Node<T> *current = head;
        while (current != nullptr)
        {
            Node<T> *next = current->next;
            delete current;
            current = next;
        }
    }

    void pushFront(T value)
    {
        Node<T> *newNode = new Node<T>(value);
        newNode->next = head;
        head = newNode;
        size++;
    }
    void pushBack(T vlaue)
    {
        Node<T> *newNode = new Node<T>(vlaue);
        if (head == nullptr)
        {
            head = newNode;
        }
        else
        {
            Node<T> *current = head;
            while (current->next != nullptr)
            {
                current = current->next;
            }
            current->next = newNode;
        }
        size++;
    }
    bool popFront()
    {
        if (head == nullptr)
        {
            return false;
        }
        else
        {
            Node<T> *temp = head;
            head = head->next;
            delete temp;
            size--;
            return true;
        }
    }
    int getSize()
    {
        return size;
    }
    bool isEmpty()
    {
        return head == nullptr;
    }
    void print()
    {

        Node<T> *current = head;
        while (current->next != nullptr)
        {
            cout << current->data;
            current = current->next;
            if (current->next != nullptr)
            {
                cout << "->";
            }
        }
    }
    bool search(T val)
    {
        if (head == nullptr)
        {
            return false;
        }
        Node<T> *current;
        current = head;
        while (current->next != nullptr)
        {
            if (current->data == val)
            {
                return true;
            }
            current = current->next;
        }

        return false;
    }
    Node<T> *getHead() const
    {
        return head;
    }
    void setHead(Node<T> *node)
    {
        head = node;
    }
};

// recursive
template <typename T>
void PrintList(const List<T> &list, Node<T> *node = nullptr)
{
    if (node == nullptr)
    {
        node = list.getHead();
    }

    if (node == nullptr)
    {
        cout << endl;
        return;
    }

    cout << node->data;
    if (node->next != nullptr)
    {
        cout << "->";
    }

    delete list.getHead();
    PrintList(list, node->next);
}
int main()
{
    // Create a list of integers
    List<int> numbers;

    // Add some numbers
    numbers.pushBack(1);
    numbers.pushBack(2);
    numbers.pushBack(3);
    numbers.pushFront(0);
    cout << "is exist two " << numbers.search(4) << endl;
    // Print list contents recursive
    cout << "List contents Recursive:";
    PrintList(numbers);

    // Print the list
    cout << "List contents: ";
    numbers.print();

    // Remove first element
    numbers.popFront();
    cout << "After removing first element: ";
    numbers.print();

    cout << "List size: " << numbers.getSize() << endl;
    cout << "Is list empty? " << (numbers.isEmpty() ? "Yes" : "No") << endl;

    // Create a list of strings
    List<string> names;

    // Add some names
    names.pushBack("John");
    names.pushBack("Jane");
    names.pushFront("Mike");

    // Print the list
    cout << "\nNames list: ";
    names.print();

    return 0;
}
