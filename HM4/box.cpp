#include <bits/stdc++.h>
using namespace std;

#define MAX 100000

// Define Stack class
class Stack
{
private:
    long long top;
    long long arr[MAX];

public:
    Stack() { top = -1; }

    void push(long long x)
    {
        if (top >= MAX - 1)
        {
            return;
        }
        arr[++top] = x;
    }

    long long pop()
    {
        if (top < 0)
        {
            return 0;
        }
        return arr[top--];
    }

    long long peek()
    {
        if (top < 0)
        {
            return 0;
        }
        return arr[top];
    }

    bool isEmpty()
    {
        return (top < 0);
    }
};

int main()
{

    long long n, m;
    cin >> n >> m; // Read n and m first

    Stack s1;
    Stack s2;
    Stack ans;
    long long size1 = 0;
    long long size2 = 0;
    for (long long i = 0; i < n; i++)
    {
        long long x;
        cin >> x;
        s1.push(x);
        size1++;
    }

    for (long long i = 0; i < m; i++)
    {
        long long x;
        cin >> x;
        s2.push(x);
        size2++;
    }

    // start checking
    for (long long i = 0; s1.isEmpty() == 0 && s2.isEmpty() == 0; i++)
    {
        if (s1.peek() > s2.peek())
        {
            if (s2.peek() > ans.peek())
            {
                ans.pop();
                ans.push(s2.pop());
                size2--;
            }
            else if (s1.peek() > ans.peek())
            {
                ans.pop();
                ans.push(s1.pop());
                size1--;
            }
            else
            {
                ans.push(s2.pop());
                size2--;
            }
        }
        else if (s1.peek() < s2.peek())
        {
            if (s1.peek() > ans.peek())
            {
                ans.pop();
                ans.push(s1.pop());
                size1--;
            }
            else if (s2.peek() > ans.peek())
            {
                ans.pop();
                ans.push(s2.pop());
                size2--;
            }
            else
            {
                ans.push(s1.pop());
                size1--;
            }
        }
        else
        {
            if (size1 > size2)
            {
                if (s1.peek() > ans.peek())
                {
                    ans.pop();
                    ans.push(s1.pop());
                    size1--;
                }
                else
                {
                    ans.push(s1.pop());
                    size1--;
                }
            }
            else
            {
                if (s2.peek() > ans.peek())
                {
                    ans.pop();
                    ans.push(s2.pop());
                }
                else
                {
                    ans.push(s2.pop());
                    size2--;
                }
            }
        }
    }

    while (!s1.isEmpty())
    {
        if (s1.peek() > ans.peek())
        {
            ans.pop();
            ans.push(s1.pop());
            size1--;
        }
        else if (s2.peek() > ans.peek())
        {
            ans.pop();
            ans.push(s2.pop());
            size2--;
        }
        else
        {
            ans.push(s1.pop());
            size1--;
        }
    }
    while (!s2.isEmpty())
    {
        if (s2.peek() > ans.peek())
        {
            ans.pop();
            ans.push(s2.pop());
            size2--;
        }
        else if (s1.peek() > ans.peek())
        {
            ans.pop();
            ans.push(s1.pop());
            size1--;
        }
        else
        {
            ans.push(s2.pop());
            size2--;
        }
    }

    int count = 0;
    while (ans.isEmpty() != 1)
    {
        ans.pop();
        count++;
    }
    cout << count;
    return 0;
}