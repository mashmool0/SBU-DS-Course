#include <bits/stdc++.h>
using namespace std;

int sumRightSubtree(int tree[], int parent[], int n, int target, int border1, int border2)
{
    int targetIndex = -1;
    for (int i = 0; i < n; i++)
    {
        if (tree[i] == target)
        {
            targetIndex = i;
            break;
        }
    }

    if (targetIndex == -1)
        return 0;

    int sum = 0;

    auto getRightChild = [&](int index) -> int
    {
        int rightChildIndex = 2 * index + 2;
        if (rightChildIndex < n && parent[rightChildIndex] == index + 1)
        {
            return rightChildIndex;
        }
        return -1;
    };

    std::function<void(int)> sumSubtree = [&](int index)
    {
        if (index == -1 || index >= n)
            return;

        // اول چک می‌کنیم که آیا این گره یکی از مرزهاست
        if (tree[index] == border1 || tree[index] == border2)
        {
            return;
        }

        // اگر مرز نبود، مقدارش را اضافه می‌کنیم
        sum += tree[index];

        int leftChild = 2 * index + 1;
        int rightChild = 2 * index + 2;

        if (leftChild < n && parent[leftChild] == index + 1)
        {
            sumSubtree(leftChild);
        }
        if (rightChild < n && parent[rightChild] == index + 1)
        {
            sumSubtree(rightChild);
        }
    };

    int rightChild = getRightChild(targetIndex);
    if (rightChild != -1)
    {
        sumSubtree(rightChild);
    }

    return sum;
}

int sumLeftSubtree(int tree[], int parent[], int n, int target, int border1, int border2)
{
    int targetIndex = -1;
    for (int i = 0; i < n; i++)
    {
        if (tree[i] == target)
        {
            targetIndex = i;
            break;
        }
    }

    if (targetIndex == -1)
        return 0;

    int sum = 0;

    auto getLeftChild = [&](int index) -> int
    {
        int leftChildIndex = 2 * index + 1;
        if (leftChildIndex < n && parent[leftChildIndex] == index + 1)
        {
            return leftChildIndex;
        }
        return -1;
    };

    std::function<void(int)> sumSubtree = [&](int index)
    {
        if (index == -1 || index >= n)
            return;

        if (tree[index] == border1 || tree[index] == border2)
        {
            return;
        }

        sum += tree[index];

        int leftChild = 2 * index + 1;
        int rightChild = 2 * index + 2;

        if (leftChild < n && parent[leftChild] == index + 1)
        {
            sumSubtree(leftChild);
        }
        if (rightChild < n && parent[rightChild] == index + 1)
        {
            sumSubtree(rightChild);
        }
    };

    int leftChild = getLeftChild(targetIndex);
    if (leftChild != -1)
    {
        sumSubtree(leftChild);
    }

    return sum;
}

int main()
{
    int n, k1, k2;
    cin >> n;
    int tree[n];
    int parent[n];
    parent[0] = 0;

    for (int i = 0; i < n; i++)
    {
        cin >> tree[i];
    }
    cin >> k1 >> k2;

    // ساخت آرایه parent - بدون تغییر
    int count_parent = 1;
    for (int i = 0; i < n; i = i + 2)
    {
        for (int j = i + 1; j <= i + 2 && j < n; j++)
        {
            parent[j] = count_parent;
        }
        count_parent++;
    }

    // پیدا کردن ایندکس k1 و k2 - بدون تغییر
    int k1_index = -1, k2_index = -1;
    for (int i = 0; i < n; i++)
    {
        if (tree[i] == k1)
            k1_index = i;
        if (tree[i] == k2)
            k2_index = i;
    }

    // تغییر در نحوه پیدا کردن والدین
    vector<pair<int, int>> parents_k1; // <value, index>
    int current = k1_index;
    while (current != 0)
    {
        parents_k1.push_back({tree[current], current});
        current = parent[current] - 1;
    }
    parents_k1.push_back({tree[0], 0});

    vector<pair<int, int>> parents_k2;
    current = k2_index;
    while (current != 0)
    {
        parents_k2.push_back({tree[current], current});
        current = parent[current] - 1;
    }
    parents_k2.push_back({tree[0], 0});

    // پیدا کردن اولین والد مشترک با در نظر گرفتن عمق
    pair<int, int> same_parent = {tree[0], 0};
    int min_depth = INT_MAX;

    for (int i = 0; i < parents_k1.size(); i++)
    {
        for (int j = 0; j < parents_k2.size(); j++)
        {
            if (parents_k1[i].first == parents_k2[j].first &&
                parents_k1[i].first != k1 && parents_k1[i].first != k2)
            {
                int depth = min(i, j);
                if (depth < min_depth)
                {
                    min_depth = depth;
                    same_parent = parents_k1[i];
                }
            }
        }
    }

    // ساخت مسیر با استفاده از اندیس‌ها
    vector<int> left, right;

    // مسیر k1 تا والد مشترک
    for (auto p : parents_k1)
    {
        if (p.first == same_parent.first)
            break;
        if (p.first != k1 && p.first != k2)
        {
            bool isValid = true;
            // چک کردن اینکه آیا این گره در مسیر k2 هست
            for (auto p2 : parents_k2)
            {
                if (p.first == p2.first)
                {
                    isValid = false;
                    break;
                }
            }
            if (isValid)
                left.push_back(p.first);
        }
    }

    // مسیر k2 تا والد مشترک
    for (auto p : parents_k2)
    {
        if (p.first == same_parent.first)
            break;
        if (p.first != k1 && p.first != k2)
        {
            bool isValid = true;
            // چک کردن اینکه آیا این گره در مسیر k1 هست
            for (auto p1 : parents_k1)
            {
                if (p.first == p1.first)
                {
                    isValid = false;
                    break;
                }
            }
            if (isValid)
                right.push_back(p.first);
        }
    }

    // محاسبه مجموع با اعمال محدودیت‌های بیشتر
    int sum = 0;
    set<int> processed; // برای جلوگیری از محاسبه تکراری

    for (int item : left)
    {
        if (processed.find(item) == processed.end())
        {
            int temp = sumRightSubtree(tree, parent, n, item, k1, k2);
            sum += temp;
            processed.insert(item);
        }
    }

    for (int item : right)
    {
        if (processed.find(item) == processed.end())
        {
            int temp = sumLeftSubtree(tree, parent, n, item, k1, k2);
            sum += temp;
            processed.insert(item);
        }
    }

    cout << sum;
    return 0;
}