#include <iostream>

using namespace std;

class Tree
{
public:
    int data;
    Tree *right_sibling;
    Tree *first_child;
    Tree(int value) : data(value), right_sibling(nullptr), first_child(nullptr) {}
};

class GeneralTree
{
private:
    Tree *root;

public:
    GeneralTree() : root(nullptr) {}
    // empty size and makenull are same with tree binary linked list

    Tree *Parent(Tree *T, Tree *Node)
    {
        if (T == nullptr || T == Node)
        {
            return nullptr;
        }
        Tree *child = T->first_child;

        while (child != nullptr)
        {
            if (child == Node)
            {
                return T;
            }
            child = child->right_sibling;
        }

        child = T->first_child;
        while (child != nullptr)
        {
            Tree *res = Parent(child, Node);
            if (res != nullptr)
            {
                return res;
            }
            child = child->right_sibling;
        }

        return nullptr;
    }
};

int main()
{
    GeneralTree gt;

    // ساخت درخت نمونه
    Tree *A = new Tree(1); // ریشه
    Tree *B = new Tree(2);
    Tree *C = new Tree(3);
    Tree *D = new Tree(4);
    Tree *E = new Tree(5);
    Tree *F = new Tree(6);
    Tree *G = new Tree(7);

    // ایجاد ارتباط‌ها
    A->first_child = B;
    B->right_sibling = C;
    C->right_sibling = D;
    B->first_child = E;
    E->right_sibling = F;
    D->first_child = G;

    /*1(A)
         /|  \
        2(B) 3(C) 4(D)
       /  \        |
      5(E) 6(F)7(G)
    */

    // تست‌های مختلف
    cout << gt.Parent(A, G)->data << endl; // باید 4چاپ کند (D)
    cout << gt.Parent(A, E)->data << endl; // باید 2 چاپ کند (B)
    cout << gt.Parent(A, C)->data << endl; // باید 1 چاپ کند (A)

    return 0;
}
