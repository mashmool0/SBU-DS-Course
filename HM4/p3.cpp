#include <bits/stdc++.h>
using namespace std;

class Queue
{
    int rear, front;
    int size;
    int *arr;

public:
    Queue(int s)
    {
        front = -1;
        rear = -1;
        size = s;
        arr = new int[s];
    }
    void enQueue(int value);
    int deQueue();
    void displayQueue();
};

void Queue::enQueue(int value)
{
    // Check full
    if ((rear == size - 1 && front == 0) || ((rear + 1) % size == front))
    {
        cout << "Queue is Full";
        return;
    }

    // Check is it empty

    else if (front == -1)
    {
        front = rear = 0;
        arr[rear] = value;
    }

    else if (rear + 1 == size && front != 0)
    {
        rear = 0;
        arr[rear] = value;
    }

    else
    {
        rear += 1;
        arr[rear] = value;
    }
}

int Queue::deQueue()
{
    if (front == -1)
    {
        return INT_MIN;
    }

    int data = arr[front];

    if (front == rear)
    {
        front = rear = -1;
    }
    else if (front == size - 1)
    {
        front = 0;
    }
    else
    {
        front++;
    }

    return data;
}
void Queue::displayQueue()
{
    if (front == -1)
    {
        printf("\nQueue is Empty");
        return;
    }
    printf("\nElements in Circular Queue are: ");
    if (rear >= front)
    {
        for (int i = front; i <= rear; i++)
            printf("%d ", arr[i]);
    }
    else
    {
        for (int i = front; i < size; i++)
            printf("%d ", arr[i]);

        for (int i = 0; i <= rear; i++)
            printf("%d ", arr[i]);
    }
}

// Note : i used geeks for geeks test case for check my code
// Geeks for geeks test case
int main()
{
    Queue q(5);

    q.enQueue(14);
    q.enQueue(22);
    q.enQueue(13);
    q.enQueue(-6);

    // Display elements present in Circular Queue
    q.displayQueue();

    // Deleting elements from Circular Queue
    printf("\nDeleted value = %d", q.deQueue());
    printf("\nDeleted value = %d", q.deQueue());

    q.displayQueue();

    q.enQueue(9);
    q.enQueue(20);
    q.enQueue(5);

    q.displayQueue();

    q.enQueue(20);
    return 0;
}