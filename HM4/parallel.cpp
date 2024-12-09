#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    string data;
    Node *next;
    Node(string new_data)
    {
        this->data = new_data;
        this->next = nullptr;
    }
};

class Stack
{
    Node *head;

public:
    Stack()
    {
        this->head = nullptr;
    }

    bool isEmpty()
    {
        return head == nullptr;
    }

    void push(string new_data)
    {
        Node *new_node = new Node(new_data);
        new_node->next = head;
        head = new_node;
    }

    string pop()
    {
        if (this->isEmpty())
        {
            return "";
        }
        string popped_data = head->data;
        Node *temp = head;
        head = head->next;
        delete temp;
        return popped_data;
    }

    string peek()
    {
        if (!isEmpty())
            return head->data;
        return "";
    }
};

class QueueNode
{
public:
    int data;
    QueueNode *next;
    QueueNode(int x) : data(x), next(nullptr) {}
};

class Queue
{
public:
    QueueNode *front, *rear;
    int size;

    Queue() : front(nullptr), rear(nullptr), size(0) {}
};

void enqueue(Queue *queue, int item)
{
    QueueNode *newNode = new QueueNode(item);
    if (queue->rear == nullptr)
    {
        queue->front = queue->rear = newNode;
        queue->size++;
        return;
    }
    queue->rear->next = newNode;
    queue->rear = newNode;
    queue->size++;
}

int dequeue(Queue *queue)
{
    if (queue->front == nullptr)
        return -1;

    QueueNode *temp = queue->front;
    int item = temp->data;
    queue->front = queue->front->next;
    queue->size--;

    if (queue->front == nullptr)
        queue->rear = nullptr;

    delete temp;
    return item;
}

int getFront(Queue *queue)
{
    if (queue->front == nullptr)
        return -1;
    return queue->front->data;
}

int main()
{
    int n, q;
    cin >> n >> q;
    cin.ignore();

    // Initialize stacks for each program
    vector<Stack> program_stacks(n);
    for (int i = 0; i < n; i++)
    {
        program_stacks[i].push("main");
    }

    // Initialize program queue
    Queue *program_queue = new Queue();
    for (int i = 0; i < n; i++)
    {
        enqueue(program_queue, i);
    }

    vector<string> output;

    for (int i = 0; i < q; i++)
    {
        string command;
        getline(cin, command);

        if (command == "DoFunction")
        {
            int current_program = getFront(program_queue);
            if (current_program != -1)
            {
                string function = program_stacks[current_program].pop();
                output.push_back(to_string(current_program + 1) + ":" + function);
            }
        }
        else if (command == "NextProgram")
        {
            if (program_queue->size > 0)
            {
                int current_program = dequeue(program_queue);
                if (!program_stacks[current_program].isEmpty())
                {
                    enqueue(program_queue, current_program);
                }
            }
        }
        else if (command.substr(0, 4) == "Call")
        {
            int current_program = getFront(program_queue);
            if (current_program != -1)
            {
                string function_name = command.substr(5);
                program_stacks[current_program].push(function_name);
            }
        }
    }

    // Print output
    for (size_t i = 0; i < output.size(); i++)
    {
        cout << output[i];
        if (i < output.size() - 1)
        {
            cout << endl;
        }
    }

    delete program_queue;
    return 0;
}
