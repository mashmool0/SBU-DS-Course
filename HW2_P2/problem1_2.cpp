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
    map<int, long long> result; //---------------- Combined terms with the same powers

    // Process first array
    for (int i = 0; i < n; i++)
    {
        result[tavan1[i]] += zarib1[i];
    }

    // Process second array
    for (int i = 0; i < m; i++)
    {
        result[tavan2[i]] += zarib2[i];
    }

    *len_max = 0;
    for (const auto &entry : result)
    {
        if (entry.second != 0)
        {
            tavan_ans[*len_max] = entry.first;
            zarib_ans[*len_max] = entry.second;
            (*len_max)++;
        }
    }
}

void subTwoArray(long long zarib1[], long long tavan1[], long long zarib2[], long long tavan2[], long long zarib_ans[], long long tavan_ans[], int n, int m, int *len_max)
{
    map<int, long long> result; //---------------- Combined terms with the same powers for subtraction

    // Process first array
    for (int i = 0; i < n; i++)
    {
        result[tavan1[i]] += zarib1[i];
    }

    // Process second array with subtraction
    for (int i = 0; i < m; i++)
    {
        result[tavan2[i]] -= zarib2[i];
    }

    *len_max = 0;
    for (const auto &entry : result)
    {
        if (entry.second != 0)
        {
            tavan_ans[*len_max] = entry.first;
            zarib_ans[*len_max] = entry.second;
            (*len_max)++;
        }
    }
}

void mulTowArray(long long zarib1[], long long tavan1[], long long zarib2[], long long tavan2[], long long zarib_ans[], long long tavan_ans[], int n, int m, int *len_max)
{
    map<int, long long> result; //---------------- Handled multiplication with zero coefficients

    // Iterate over both polynomials
    for (int i = 0; i < n; i++)
    {
        if (zarib1[i] == 0)
            continue; //---------------- Skip zero coefficients
        for (int j = 0; j < m; j++)
        {
            if (zarib2[j] == 0)
                continue; //---------------- Skip zero coefficients
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
