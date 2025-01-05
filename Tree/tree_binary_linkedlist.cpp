#include <iostream>
using namespace std;

class Tree
{
public:
    int data;
    Tree *RC;
    Tree *LC;
    Tree(int value) : data(value), RC(nullptr), LC(nullptr) {}
};

class BinaryTree
{
private:
    Tree *root;                      // Changed Position to root as Position is a type
    const Tree *NULL_TREE = nullptr; // Changed Null definition

public:
    BinaryTree() : root(nullptr) {} // Added constructor

    int Size(Tree *T) // Fixed parameter type to pointer
    {
        if (T == nullptr) // Changed null check
        {
            return 0;
        }
        return 1 + Size(T->LC) + Size(T->RC); // Fixed pointer access
    }
    Tree *LMC(Tree *T) // Changed return type and parameter to pointer
    {
        if (T == nullptr) // Added null check
        {
            return nullptr;
        }
        if (T->LC != nullptr) // Fixed pointer syntax
        {
            return T->LC;
        }
        else
        {
            return T->RC;
        }
    }
    bool Empty(Tree *T)
    {
        if (T == nullptr)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    void MakeNull(Tree *T)
    {
        if (T == nullptr)
        {
            return;
        }
        MakeNull(T->LC);
        MakeNull(T->RC);
        delete T;
    }
    int Height(Tree *T)
    {
        if (T == nullptr)
        {
            return 0;
        }
        return 1 + max(Height(T->LC), Height(T->RC));
    }
    Tree *Parent(Tree *Node, Tree *T)
    {
        if (T == nullptr || T == Node)
        {
            return nullptr;
        }
        if (T->LC == Node || T->RC == Node)
        {
            return T;
        }

        Tree *temp;
        temp = Parent(Node, T->LC);
        if (temp == nullptr)
        {
            temp = Parent(Node, T->RC);
        }
        return temp;
    }
};

int main()
{
    BinaryTree tree;
    return 0;
}
