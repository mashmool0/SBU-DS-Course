#include <iostream>
using namespace std;

int partition(long arr[], int low, int high)
{
    long pivot = arr[high];
    int i = (low - 1);
    for (int j = low; j <= high - 1; j++)
    {
        if (arr[j] <= pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}

void quickSort(long arr[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

bool is_prime(long num)
{
    if (num <= 1)
        return false;
    if (num <= 3)
        return true;
    if (num % 2 == 0 || num % 3 == 0)
        return false;
    for (long i = 5; i * i <= num; i += 6)
    {
        if (num % i == 0 || num % (i + 2) == 0)
        {
            return false;
        }
    }
    return true;
}

bool binarySearch(long arr[], int low, int high, long x)
{
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (arr[mid] == x)
            return true; // Element found
        if (arr[mid] < x)
            low = mid + 1; // Search right half
        else
            high = mid - 1; // Search left half
    }
    return false; // Element not found
}

int main()
{
    long n;
    cin >> n;
    long lst_inputs[n];

    for (long i = 0; i < n; i++)
    {
        cin >> lst_inputs[i];
    }

    quickSort(lst_inputs, 0, n - 1);

    // Check for number 2 in the sorted array using binary search
    bool was_two = binarySearch(lst_inputs, 0, n - 1, 2);

    if (was_two)
    {
        long number = 3;
        while (true)
        {
            if (is_prime(number) && !binarySearch(lst_inputs, 0, n - 1, number))
            {
                cout << number;
                return 0;
            }
            number += 2; // Skip even numbers since they're not prime (after 2)
        }
    }
    else
    {
        cout << 2;
    }

    return 0;
}
