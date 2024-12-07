#include <iostream>
using namespace std;

class Queue
{
private:
    static const int MAX_SIZE = 5; // حداکثر اندازه صف
    int arr[MAX_SIZE];             // آرایه برای ذخیره عناصر
    int front;                     // شاخص ابتدای صف
    int rear;                      // شاخص انتهای صف
    int itemCount;                 // تعداد عناصر موجود در صف

public:
    // سازنده
    Queue()
    {
        front = 0;
        rear = -1;
        itemCount = 0;
    }

    // توابعی که باید پیاده‌سازی شوند
    void enqueue(int value)
    {
        if (itemCount >= MAX_SIZE)
        {
            cout << "Queue is Full" << endl;
            return;
        }
        rear++;
        arr[rear] = value;
        itemCount++;
    }
    int dequeue()
    {
        if (itemCount == 0)
        {
            cout << "Queue is Empyt" << endl;
            return;
        }
        int value = arr[front];
        cout << value << endl;
        itemCount--;
        front++;

        return value;
    }

    int peek()
    {
        if (itemCount == 0)
        {
            cout << "Queue is Empty";
            return;
        }

        cout << arr[front] << endl;
        return arr[front];
    }
};
