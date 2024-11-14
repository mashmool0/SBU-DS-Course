#include <iostream>
using namespace std;

void printArray(long long arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// Function to sum two arrays based on coefficients and indices
void sumTwoArray(long long arr1[], long long arr2[], int n, int m, int counter, long long ans_arr[])
{
    counter--;

    for (int i = counter; i >= 0; i--)
    {
        if (i > m)
        {
            ans_arr[i] = arr1[i];
        }
        else if (i > n)
        {
            ans_arr[i] = arr2[i];
        }
        else
        {
            ans_arr[i] = arr1[i] + arr2[i];
        }
    }
}

void subTowArray(long long arr1[], long long arr2[], int n, int m, int counter, long long ans_arr[])
{
    counter--;

    for (int i = counter; i >= 0; i--)
    {
        if (i > m)
        {
            ans_arr[i] = arr1[i];
        }
        else if (i > n)
        {
            ans_arr[i] = arr2[i] * -1;
        }
        else
        {
            ans_arr[i] = arr1[i] - arr2[i];
        }
    }
}

void mulTowArray(long long arr1[], long long arr2[], int n, int m, int counter, long long ans_arr[])
{
    // Initialize ans_arr to zero
    for (int i = 0; i < counter; i++)
    {
        ans_arr[i] = 0;
    }

    // Print arr1 and arr2 once at the start for debugging

    for (int i = n; i >= 0; i--)
    {
        for (int j = m; j >= 0; j--)
        {
            ans_arr[i + j] += (arr1[i] * arr2[j]);
            // Debug print statements to track changes to ans_arr
        }
    }
}

int main()
{
    int n, m;
    cin >> n >> m;

    long long arr1[n + 1];
    long long arr2[m + 1];

    for (int i = 0; i < n + 1; i++)
    {
        cin >> arr1[i];
    }

    for (int i = 0; i < m + 1; i++)
    {
        cin >> arr2[i];
    }

    char tag;
    cin >> tag;

    int counter = (tag == '*') ? (m + n + 1) : max(n, m) + 1;
    long long ans[counter] = {0}; // Initialize ans array with zeros

    if (tag == '+')
    {
        sumTwoArray(arr1, arr2, n, m, counter, ans);
    }
    else if (tag == '-')
    {

        subTowArray(arr1, arr2, n, m, counter, ans);
    }
    else if (tag == '*')
    {
        mulTowArray(arr1, arr2, n, m, counter, ans);
    }

    int max_index = 0;
    bool all_zeros = true;
    for (int i = 0; i < counter; i++)
    {
        if (ans[i] != 0 && i > max_index)
        {
            max_index = i;
            all_zeros = false;
        }
    }
    if (all_zeros)
    {
        cout << 0 << endl;
        cout << 0 << endl;
    }
    else
    {
        cout << max_index << endl;
        printArray(ans, counter);
    }

    return 0;
}
