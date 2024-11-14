#include <iostream>
#include <map>
using namespace std;

void bubbleSort(long long tavan_ans[], long long zarib_ans[], int len_max)
{
    for (int i = 0; i < len_max; i++)
    {
        for (int j = 1; j < len_max; j++)
        {
            if (tavan_ans[j] < tavan_ans[j - 1])
            {
                swap(tavan_ans[j], tavan_ans[j - 1]);
                swap(zarib_ans[j], zarib_ans[j - 1]);
            }
        }
    }
}
bool isZeroResult(long long zarib_ans[], int len_max)
{
    for (int i = 0; i < len_max; i++)
    {
        if (zarib_ans[i] != 0)
        {
            return false;
        }
    }
    return true;
}
void printArray(long long arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void sumTwoArray(long long zarib1[], long long tavan1[], long long zarib2[], long long tavan2[], long long zarib_ans[], long long tavan_ans[], int n, int m, int *len_max)
{
    for (int i = 0; i < n; i++)
    {
        bool is_eq = false;
        for (int j = 0; j < m; j++)
        {
            if (tavan1[i] == tavan2[j])
            {
                zarib_ans[i] = zarib1[i] + zarib2[j];
                tavan_ans[i] = tavan1[i];
                is_eq = true;
                break;
            }
        }
        if (is_eq)
        {
            continue;
        }
        tavan_ans[i] = tavan1[i];
        zarib_ans[i] = zarib1[i];
    }
    // TODO : Check tavan2 was in tavan ans
    for (int i = 0; i < m; i++)
    {
        int it_was = false;
        for (int j = 0; j < n; j++)
        {
            if (tavan2[i] == tavan_ans[j])
            {
                it_was = true;
                break;
            }
        }
        if (it_was)
        {
            continue;
        }
        else
        {
            tavan_ans[*len_max] = tavan2[i];
            zarib_ans[*len_max] = zarib2[i];
            (*len_max) += 1;
        }
    }
    bubbleSort(tavan_ans, zarib_ans, *len_max);
}

void subTwoArray(long long zarib1[], long long tavan1[], long long zarib2[], long long tavan2[], long long zarib_ans[], long long tavan_ans[], int n, int m, int *len_max)
{
    for (int i = 0; i < n; i++)
    {
        bool is_eq = false;
        for (int j = 0; j < m; j++)
        {
            if (tavan1[i] == tavan2[j])
            {
                zarib_ans[i] = zarib1[i] - zarib2[j];
                tavan_ans[i] = tavan1[i];
                is_eq = true;
                break;
            }
        }
        if (is_eq)
        {
            continue;
        }
        tavan_ans[i] = tavan1[i];
        zarib_ans[i] = zarib1[i];
    }
    // TODO : Check tavan2 was in tavan ans
    for (int i = 0; i < m; i++)
    {
        int it_was = false;
        for (int j = 0; j < n; j++)
        {
            if (tavan2[i] == tavan_ans[j])
            {
                it_was = true;
                break;
            }
        }
        if (it_was)
        {
            continue;
        }
        else
        {
            tavan_ans[*len_max] = tavan2[i];
            zarib_ans[*len_max] = zarib2[i] * -1;
            (*len_max) += 1;
        }
    }
    bubbleSort(tavan_ans, zarib_ans, *len_max);
}

void mulTowArray(long long zarib1[], long long tavan1[], long long zarib2[], long long tavan2[], long long zarib_ans[], long long tavan_ans[], int n, int m, int *len_max)
{
    map<int, long long> result; //----------------

    // Iterate over both polynomials
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int jam_tavan = tavan1[i] + tavan2[j];
            long long zarb_zarib = zarib1[i] * zarib2[j];

            // Add to the map, summing coefficients for each unique power
            result[jam_tavan] += zarb_zarib; //----------------
        }
    }

    // Copy results from map to zarib_ans and tavan_ans arrays
    *len_max = 0;
    for (const auto &entry : result) //----------------
    {
        if (entry.second != 0) // Skip zero coefficients
        {
            tavan_ans[*len_max] = entry.first;
            zarib_ans[*len_max] = entry.second;
            (*len_max)++;
        }
    }

    // Sorting is not required here because map iterates in ascending order of keys by default
}

int main()
{
    // Define Varables
    int n, m;
    // Take input for n , m
    cin >> n >> m;

    long long zarib1[n];
    long long tavan1[n];
    long long zarib2[m];
    long long tavan2[m];
    long long zarib_ans[n * m]; //---------------- Adjusted to allow up to n * m terms
    long long tavan_ans[n * m]; //---------------- Adjusted to allow up to n * m terms
    char tag;

    // Take input for first poly
    for (int i = 0; i < n; i++)
    {
        cin >> zarib1[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> tavan1[i];
    }

    // Take input for second poly
    for (int i = 0; i < m; i++)
    {
        cin >> zarib2[i];
    }
    for (int i = 0; i < m; i++)
    {
        cin >> tavan2[i];
    }
    // find biggest between m and n
    int len_max = 0;
    if (m >= n)
    {
        len_max = m;
    }
    else
    {
        len_max = n;
    }

    // Take input for operations
    cin >> tag;

    // Check what is operations
    if (tag == '+')
    {
        sumTwoArray(zarib1, tavan1, zarib2, tavan2, zarib_ans, tavan_ans, n, m, &len_max);
        if (isZeroResult(zarib_ans, len_max))
        {
            // If result is zero, set len_max to 1 and print zero arrays
            len_max = 1;
            cout << len_max << endl;
            cout << "0" << endl;
            cout << "0" << endl;
        }
        else
        {
            cout << len_max << endl;
            printArray(zarib_ans, len_max);
            printArray(tavan_ans, len_max);
        }
    }
    else if (tag == '-')
    {
        subTwoArray(zarib1, tavan1, zarib2, tavan2, zarib_ans, tavan_ans, n, m, &len_max);
        if (isZeroResult(zarib_ans, len_max))
        {
            // If result is zero, set len_max to 1 and print zero arrays
            len_max = 1;
            cout << len_max << endl;
            cout << "0" << endl;
            cout << "0" << endl;
        }
        else
        {
            cout << len_max << endl;
            printArray(zarib_ans, len_max);
            printArray(tavan_ans, len_max);
        }
    }
    else if (tag == '*')
    {
        mulTowArray(zarib1, tavan1, zarib2, tavan2, zarib_ans, tavan_ans, n, m, &len_max);
        cout << len_max << endl;
        printArray(zarib_ans, len_max);
        printArray(tavan_ans, len_max);
    }

    return 0;
}
