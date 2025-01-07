#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    vector<Node *> children;
    int data;

    Node(int value) : data(value) {}

    void addChild(Node *child)
    {
        children.push_back(child);
    }
    void BFS(Node *node)
    {
        if (node == nullptr)
        {
            return;
        }
        queue<Node *> q;
        Node *current_node = node;
        q.push(current_node);
        cout << current_node->data << " ";

        while (!q.empty())
        {
            current_node = q.front();
            q.pop();

            for (int i = 0; i < current_node->children.size(); i++)
            {
                cout << current_node->children[i]->data << " ";
                q.push(current_node->children[i]);
            }
        }
    }
};

int main()
{
    // Test implementation
    Node *root = new Node(1);
    Node *child1 = new Node(2);
    Node *child2 = new Node(3);
    Node *child3 = new Node(4);
    Node *child4 = new Node(5);
    Node *child5 = new Node(6);
    Node *child6 = new Node(7);
    Node *child7 = new Node(8);
    Node *child8 = new Node(9);
    Node *child9 = new Node(10);
    Node *child10 = new Node(11);
    Node *child11 = new Node(12);

    root->addChild(child1);
    root->addChild(child2);
    root->addChild(child3);
    child1->addChild(child4);
    child1->addChild(child5);
    child4->addChild(child7);
    child4->addChild(child8);
    child8->addChild(child9);
    child9->addChild(child10);
    child9->addChild(child11);
    root->BFS(root); // Should print: 1 2 4 3

    // Clean up
    delete child3;
    delete child2;
    delete child1;
    delete root;

    return 0;
}