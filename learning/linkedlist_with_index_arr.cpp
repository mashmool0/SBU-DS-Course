#include <iostream>
using namespace std;

const int MAX_SIZE = 100; // حداکثر اندازه آرایه

struct Node
{
    int data; // داده
    int next; // اندیس بعدی
};

class IndexedList
{
private:
    Node arr[MAX_SIZE]; // آرایه اصلی
    int head;           // اندیس اولین عنصر
    int freeIndex;      // اندیس اولین خانه خالی

public:
    IndexedList()
    {
        head = -1;     // لیست خالی
        freeIndex = 0; // همه خانه‌ها خالی هستند

        // مقداردهی اولیه لیست خالی‌ها
        for (int i = 0; i < MAX_SIZE - 1; i++)
        {
            arr[i].next = i + 1;
        }
        arr[MAX_SIZE - 1].next = -1; // آخرین عنصر
    }

    void insertAtBeginning(int value)
    {
        if (freeIndex == -1)
        {
            cout << "List Is Full" << endl;
            return;
        }
        int newIndex = freeIndex;
        freeIndex = arr[freeIndex].next;

        arr[newIndex].data = value;
        arr[newIndex].next = head;
        head = newIndex;
    }

    void deleteFromBeginning()
    {
        if (head == -1)
        {
            cout << "List is Empty" << endl;
            return;
        }
        int temp = head;
        head = arr[head].next;

        arr[temp].next = freeIndex;
        freeIndex = temp;
    }
    void display()
    {
        if (head == -1)
        {
            cout << "List is empty";
            return;
        }

        int index_check = head;
        while (index_check != -1)
        {
            cout << arr[index_check].data << " ";
            index_check = arr[index_check].next;
        }
    }
};

int main()
{
    IndexedList list;

    // تست عملیات‌ها
    list.insertAtBeginning(30);
    list.insertAtBeginning(20);
    list.insertAtBeginning(10);

    cout << "بعد از درج سه عنصر:" << endl;
    list.display();

    list.deleteFromBeginning();
    cout << "بعد از حذف یک عنصر:" << endl;
    list.display();

    return 0;
}