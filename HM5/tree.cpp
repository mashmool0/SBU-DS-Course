#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, k1, k2;
    cin >> n;
    int tree[n];
    int parent[n];
    parent[0] = 0;

    // 10 5 15 3 7 12 20 2 6 24
    for (int i = 0; i < n; i++)
    {
        cin >> tree[i];
    }
    cin >> k1 >> k2;
    int count_parent = 1;
    for (int i = 0; i < n; i = i + 2)
    {

        for (int j = i + 1; j <= i + 2; j++)
        {
            parent[j] = count_parent;
        }

        count_parent++;

        if (i + 4 >= n)
        {
            for (int j = i + 3; j < n; j++)
            {
                parent[j] = count_parent;
            }
            break;
        }
    }

    for (int i = 0; i < n; i++)
    {
        cout << parent[i] << " ";
    }
    // 2 24
    // 7 9
    return 0;
}