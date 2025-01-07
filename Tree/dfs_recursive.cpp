#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    vector<Node *> children;
    int data;
    bool visited;

    // Initialize visited to false in constructor
    Node(int value) : data(value), visited(false) {}

    // Helper function to add a child
    void addChild(Node *child)
    {
        children.push_back(child);
    }

    // Traverse with dfs method
    void DFS(Node *node)
    {
        if (node == nullptr)
        {
            return;
        }
        cout << node->data << " "; // Added space for better readability
        node->visited = true;

        while (true)
        {
            Node *nextChild = nullptr;
            for (Node *child : node->children)
            {
                if (!child->visited) // Simplified condition
                {
                    nextChild = child;
                    break;
                }
            }

            if (nextChild == nullptr)
            {
                break;
            }

            DFS(nextChild);
        }
    }
};

int main()
{
    // Test the implementation
    Node *root = new Node(1);
    Node *child1 = new Node(2);
    Node *child2 = new Node(3);
    Node *child3 = new Node(4);

    root->addChild(child1);
    root->addChild(child2);
    child1->addChild(child3);

    root->DFS(root);

    return 0;
}