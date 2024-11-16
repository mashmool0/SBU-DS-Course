#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void printArray(string arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i];
        if (i + 1 == size)
        {
            break;
        }
        cout << endl;
    }
}

int main()
{
    int n, m;
    int num;
    cin >> n >> m;
    string main_word[n];

    // O(n)
    for (int i = 0; i < n; i++)
    {
        cin >> main_word[i];
    }

    cin >> num;
    string ans[num];
    string check_word[num];
    int index = 0;

    // Take inputs to check
    // O(n)
    for (int i = 0; i < num; i++)
    {
        cin >> check_word[i];
    }

    // Check rows
    for (int i = 0; i < num; i++)
    {
        // Reset is_find for each check_word
        bool is_find = false; // ---------------- Reset here

        // Take the current check word
        string check_word_ = check_word[i];
        string reverse_check_word = string(check_word_.rbegin(), check_word_.rend());
        int len_word = check_word_.size();

        for (int j = 0; j < n; j++)
        {
            // Take the main word
            string main_word_ = main_word[j];

            // If already found, break out of main word loop
            if (is_find)
            {
                break;
            }

            // Check for substring match within main word
            for (int l = 0; l + len_word <= m; l++)
            {
                string st;

                // Ensure correct substring range (l to l + len_word)
                for (int z = l; z < l + len_word; z++) // ---------------- Fix range
                {
                    st += main_word_[z];
                }

                // Check if the substring matches the word or its reverse
                if (st == check_word_ || st == reverse_check_word)
                {
                    is_find = true;
                    ans[index] = "YES";
                    break;
                }
            }
        }

        // If not found, check column
        if (!is_find) // ---------------- Check if not found
        {
            ans[index] = "NO";
        }

        index += 1; // ---------------- Increment index after each check
    }

    printArray(ans, num);
    return 0;
}
