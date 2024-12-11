#include <iostream>
using namespace std;

class Stack
{
private:
    int *arr;
    int top;
    int capacity;

public:
    Stack(int size)
    {
        arr = new int[size];
        capacity = size;
        top = -1;
    }

    ~Stack()
    {
        delete[] arr;
    }

    void push(int x)
    {
        if (top >= capacity - 1)
            return;
        arr[++top] = x;
    }

    void pop()
    {
        if (top < 0)
            return;
        top--;
    }

    int peek()
    {
        if (top < 0)
            return -1;
        return arr[top];
    }

    bool isEmpty()
    {
        return top < 0;
    }
};

int findMaxDifference(int arr[], int n)
{
    if (n <= 1)
        return 0;

    Stack leftStack(n);
    Stack rightStack(n);
    int *leftSmaller = new int[n];
    int *rightSmaller = new int[n];

    // Initialize arrays
    for (int i = 0; i < n; i++)
    {
        leftSmaller[i] = rightSmaller[i] = 0;
    }

    // Find smallest element on left side
    for (int i = 1; i < n; i++)
    {
        while (!leftStack.isEmpty() && arr[leftStack.peek()] > arr[i])
        {
            leftStack.pop();
        }
        leftSmaller[i] = leftStack.isEmpty() ? 0 : arr[leftStack.peek()];
        leftStack.push(i);
    }

    // Find smallest element on right side
    for (int i = n - 2; i >= 0; i--)
    {
        while (!rightStack.isEmpty() && arr[rightStack.peek()] > arr[i])
        {
            rightStack.pop();
        }
        rightSmaller[i] = rightStack.isEmpty() ? 0 : arr[rightStack.peek()];
        rightStack.push(i);
    }

    // Find maximum absolute difference
    int maxDiff = 0;
    for (int i = 0; i < n; i++)
    {
        maxDiff = max(maxDiff, abs(leftSmaller[i] - rightSmaller[i]));
    }

    delete[] leftSmaller;
    delete[] rightSmaller;
    return maxDiff;
}

void runTestCase(int arr[], int n, int expectedResult, int testCaseNumber)
{
    int result = findMaxDifference(arr, n);
    cout << "Test Case " << testCaseNumber << ":\n";
    cout << "Input Array: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << "\nExpected Result: " << expectedResult;
    cout << "\nActual Result: " << result;
    cout << "\nStatus: " << (result == expectedResult ? "PASSED" : "FAILED") << "\n\n";
}

int main()
{
    // Test Case 1: Basic case
    int arr1[] = {2, 4, 8, 7, 7, 9, 3};
    runTestCase(arr1, 7, 4, 1);

    // Test Case 2: Array in ascending order
    int arr2[] = {1, 2, 3, 4, 5};
    runTestCase(arr2, 5, 1, 2);

    // Test Case 3: Array in descending order
    int arr3[] = {5, 4, 3, 2, 1};
    runTestCase(arr3, 5, 1, 3);

    // Test Case 4: Array with same elements
    int arr4[] = {4, 4, 4, 4};
    runTestCase(arr4, 4, 0, 4);

    // Test Case 5: Array with single element
    int arr5[] = {1};
    runTestCase(arr5, 1, 0, 5);

    return 0;
}
