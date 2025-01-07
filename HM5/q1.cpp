#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *RC;
    Node *LC;
    Node(int value) : data(value), RC(nullptr), LC(nullptr) {}
};

class BinaryTree
{
public:
    Node *root;

    int CalculateSubTree(Node *node)
    {
        if (node == nullptr)
        {
            return 0;
        }

        return node->data + CalculateSubTree(node->LC) + CalculateSubTree(node->RC);
    }

    bool IsEqual(Node *node, int number)
    {
        if (node == nullptr)
        {
            return false;
        }
        if (number == CalculateSubTree(node))
        {
            return true;
        }
        return false;
    }
};

// تست کیس ها با استفاده از چت جی پی تی نوشته شده اند
int main()
{
}