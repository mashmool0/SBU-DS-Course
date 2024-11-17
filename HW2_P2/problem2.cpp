#include <iostream>
using namespace std;

void printArray(const string arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i];
        if (i + 1 < size)
        {
            cout << endl;
        }
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    string main_word[n];

    for (int i = 0; i < n; i++)
    {
        cin >> main_word[i];
    }

    int num;
    cin >> num;
    string ans[num];
    string check_word[num];

    for (int i = 0; i < num; i++)
    {
        cin >> check_word[i];
    }

    for (int i = 0; i < num; i++)
    {
        bool is_found = false;
        const string &word = check_word[i];
        int len_word = word.size();

        // Check rows
        for (int row = 0; row < n && !is_found; row++)
        {
            for (int start = 0; start + len_word <= m; start++)
            {
                bool match = true;
                bool reverse_match = true;
                for (int k = 0; k < len_word; k++)
                {
                    if (main_word[row][start + k] != word[k])
                        match = false;
                    if (main_word[row][start + k] != word[len_word - 1 - k])
                        reverse_match = false;
                    if (!match && !reverse_match)
                        break;
                }
                if (match || reverse_match)
                {
                    is_found = true;
                    ans[i] = "YES";
                    break;
                }
            }
        }

        // Check columns
        if (!is_found)
        {
            for (int col = 0; col < m && !is_found; col++)
            {
                for (int start = 0; start + len_word <= n; start++)
                {
                    bool match = true;
                    bool reverse_match = true;
                    for (int k = 0; k < len_word; k++)
                    {
                        if (main_word[start + k][col] != word[k])
                            match = false;
                        if (main_word[start + k][col] != word[len_word - 1 - k])
                            reverse_match = false;
                        if (!match && !reverse_match)
                            break;
                    }
                    if (match || reverse_match)
                    {
                        is_found = true;
                        ans[i] = "YES";
                        break;
                    }
                }
            }
        }

        if (!is_found)
        {
            ans[i] = "NO";
        }
    }

    printArray(ans, num);
    return 0;
}
