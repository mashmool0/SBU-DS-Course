#include <bits/stdc++.h>
using namespace std;

int sumRightSubtree(int tree[], int parent[], int n, int target, int border1, int border2)
{
    // پیدا کردن ایندکس گره هدف
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
        return 0; // گره پیدا نشد

    int sum = 0;

    // تابع کمکی برای پیدا کردن فرزند راست
    auto getRightChild = [&](int index) -> int
    {
        int rightChildIndex = 2 * index + 2;
        if (rightChildIndex < n && parent[rightChildIndex] == index + 1)
        {
            return rightChildIndex;
        }
        return -1;
    };

    // تابع کمکی برای جمع کردن تمام زیردرخت
    std::function<void(int)> sumSubtree = [&](int index)
    {
        if (index == -1)
            return;

        // چک کردن اینکه آیا گره فعلی یکی از مرزها است
        if (tree[index] == border1 || tree[index] == border2)
        {
            return;
        }

        sum += tree[index];

        // پیدا کردن فرزندان
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

    // شروع از فرزند راست گره هدف
    int rightChild = getRightChild(targetIndex);
    if (rightChild != -1)
    {
        sumSubtree(rightChild);
    }

    return sum;
}
int sumLeftSubtree(int tree[], int parent[], int n, int target, int border1, int border2)
{
    // پیدا کردن ایندکس گره هدف
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
        return 0; // گره پیدا نشد

    int sum = 0;

    // تابع کمکی برای پیدا کردن فرزند چپ
    auto getLeftChild = [&](int index) -> int
    {
        int leftChildIndex = 2 * index + 1;
        if (leftChildIndex < n && parent[leftChildIndex] == index + 1)
        {
            return leftChildIndex;
        }
        return -1;
    };

    // تابع کمکی برای جمع کردن تمام زیردرخت
    std::function<void(int)> sumSubtree = [&](int index)
    {
        if (index == -1)
            return;

        // چک کردن اینکه آیا گره فعلی یکی از مرزها است
        if (tree[index] == border1 || tree[index] == border2)
        {
            return;
        }

        sum += tree[index];

        // پیدا کردن فرزندان
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

    // شروع از فرزند چپ گره هدف
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

    // 10 5 15 3 7 12 20 2 6 24
    for (int i = 0; i < n; i++)
    {
        cin >> tree[i];
    }
    cin >> k1 >> k2;
    int count_parent = 1;
    for (int i = 0; i < n; i = i + 2)
    {

        for (int j = i + 1; j <= i + 2; j++)
        {
            parent[j] = count_parent;
        }

        count_parent++;

        if (i + 4 >= n)
        {
            for (int j = i + 3; j < n; j++)
            {
                parent[j] = count_parent;
            }
            break;
        }
    }

    // find all parent of a node
    // first find index
    for (int i = 0; i < n; i++)
    {
        if (tree[i] == k1)
        {
            k1 = i;
        }
        else if (tree[i] == k2)
        {
            k2 = i;
        }
    }
    int parents_k1[n];
    int parents_k2[n];

    int size1 = 0;
    while (k1 != 0)
    {
        parents_k1[size1] = tree[k1];
        k1 = parent[k1] - 1;
        size1++;
    }
    parents_k1[size1] = tree[0];

    int size2 = 0;
    while (k2 != 0)
    {
        parents_k2[size2] = tree[k2];
        k2 = parent[k2] - 1;
        size2++;
    }
    parents_k2[size2] = tree[0];

    int same_parent = 0;
    bool flag = false;
    for (int i = 1; i <= size1; i++)
    {
        for (int j = 1; j <= size2; j++)
        {
            if (parents_k1[i] == parents_k2[j])
            {
                same_parent = parents_k1[i];
                flag = true;
                break;
            }
        }
        if (flag)
            break;
    }

    vector<int> path; // with flag -1
    int count = 1;
    path.push_back(parents_k1[0]);
    while (parents_k1[count] != same_parent)
    {
        path.push_back(parents_k1[count]);
        count++;
    }
    path.push_back(parents_k1[count]);
    count++;

    int counter_k2 = 1;
    while (parents_k2[counter_k2] != same_parent)
    {
        path.push_back(parents_k2[counter_k2]);
        count++;
        counter_k2++;
    }
    path.push_back(parents_k2[0]);
    path.push_back(-1);

    vector<int> right;
    vector<int> left;
    flag = false;
    for (int item : path)
    {

        if (item == -1)
        {
            break;
        }
        else if (item == same_parent)
        {
            flag = true;
            continue;
        }
        else if (flag)
        {
            right.push_back(item);
        }
        else
        {
            left.push_back(item);
        }
    }

    int sum = 0;
    for (int item : left)
    {
        sum += sumRightSubtree(tree, parent, n, item, parents_k1[0], parents_k2[0]);
    }

    for (int item : right)
    {
        sum += sumLeftSubtree(tree, parent, n, item, parents_k1[0], parents_k2[0]);
    }
    cout << sum;
    return 0;
}