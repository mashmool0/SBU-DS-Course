#include <bits/stdc++.h>
using namespace std;

int minSwaps(vector<int> &arr)
{
    int n = arr.size();

    // ذخیره مقادیر و ایندکس‌های اصلی
    vector<pair<int, int>> pairs;
    for (int i = 0; i < n; i++)
    {
        pairs.push_back({arr[i], i});
    }

    // مرتب‌سازی بر اساس مقادیر
    sort(pairs.begin(), pairs.end());

    vector<bool> visited(n, false);
    int swaps = 0;

    // پیدا کردن تعداد swap‌های مورد نیاز
    for (int i = 0; i < n; i++)
    {
        // اگر عنصر در جای خودش است یا قبلاً بررسی شده، ادامه بده
        if (visited[i] || pairs[i].second == i)
            continue;

        // پیدا کردن سایز چرخه
        int cycle_size = 0;
        int j = i;
        while (!visited[j])
        {
            visited[j] = true;
            j = pairs[j].second;
            cycle_size++;
        }

        // تعداد swap‌های مورد نیاز برای این چرخه
        swaps += (cycle_size - 1);
    }

    return swaps;
}

int main()
{
    // تست کیس نمونه
    vector<int> arr = {5, 6, 7, 8, 9, 10, 11};
    cout << minSwaps(arr) << endl; // خروجی باید 0 باشد چون درخت مرتب است

    vector<int> arr2 = {5, 2, 6, 1, 3, 4, 7};
    cout << minSwaps(arr2) << endl; // خروجی باید تعداد swap های مورد نیاز را نشان دهد

    return 0;
}