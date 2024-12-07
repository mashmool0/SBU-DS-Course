#include <iostream>
using namespace std;

int main()
{
    long long n, m;
    cin >> n >> m;
    long long stack1[n];
    long long stack2[m];
    long long max_len = 0;

    if (n >= m)
    {
        max_len = n;
    }
    else
    {
        max_len = m;
    }

    for (long long i = 0; i < n; i++)
    {
        cin >> stack1[i];
    }
    for (long long i = 0; i < m; i++)
    {
        cin >> stack2[i];
    }
    n--;
    m--;
    long long count = 0;
    while (n >= 0 && m >= 0)
    {
        if (stack1[n] > stack2[m])
        {
            n--;
            count++;
        }
        else if (stack1[n] < stack2[m])
        {
            m--;
            count++;
        }
        else
        {
            if (n > m)
            {
                n--;
                count++;
            }
            else
            {
                m--;
                count++;
            }
        }
    }
    cout << count;
    return 0;
}