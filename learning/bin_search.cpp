#include <iostream>
using namespace std;
// تعریف ابعاد ماتریس‌ها
const int ROWS = 5;
const int COLS = 5;

int main()
{

    // ماتریس اول
    int matrix1[ROWS][COLS] = {
        {3, 0, 0, 5, 0},
        {0, 0, 4, 0, 0},
        {0, 0, 0, 0, 0},
        {0, 2, 0, 0, 0},
        {0, 0, 0, 0, 1}};

    // ماتریس دوم
    int matrix2[ROWS][COLS] = {
        {2, 0, 0, 0, 0},
        {0, 0, 3, 0, 0},
        {0, 0, 0, 4, 0},
        {0, 1, 0, 0, 0},
        {0, 0, 0, 0, 2}};

    int ans_matrix[ROWS][COLS];

    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            ans_matrix[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
    int count = 0;
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            if (ans_matrix[i][j] == 0)
                continue;

            count += 1;
        }
    }

    cout << "Ans Is" << "\n";
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            cout << ans_matrix[i][j] << " ";
        }
        cout << "\n";
    }

    int sparse[count][3];
    int check_count = 0;
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            if (ans_matrix[i][j] != 0)
            {
                sparse[check_count][0] = i;
                sparse[check_count][1] = j;
                sparse[check_count][2] = ans_matrix[i][j];
                check_count++;
            }
        }
    }

    cout << "\n";
    cout << "R C V" << "\n";
    for (int i = 0; i < count; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << sparse[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}