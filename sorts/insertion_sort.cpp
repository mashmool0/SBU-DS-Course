#include <bits/stdc++.h>
using namespace std;

void insert_sort(int arr[], int n)
{
    for (int j = 1; j < n; j++)
    {
        int current = arr[j];
        int i = j - 1;

        while (i >= 0 && arr[i] > current)
        {
            arr[i + 1] = arr[i];
            i--;
        }
        arr[i + 1] = current;
    }

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    int arr[5] = {12, 3, 8, 9, 20};
    insert_sort(arr, 5);
    return 0;
}