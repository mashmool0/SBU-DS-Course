#include <bits/stdc++.h>
using namespace std;
#define MAX 100

class GTree
{
public:
    int elements[MAX];
    int parents[MAX];
    int NOE;

    int LMC(GTree *T, int Node)
    {
        for (int i = 0; i < NOE; i++)
        {
            if (T->parents[i] == Node)
            {
                return T->elements[i];
            }
        }

        return -1;
    }
    int Parent(GTree *T, int Node)
    {
        return T->parents[Node];
    }
    // Right Sibling
    int RS(GTree *T, int Node)
    {
        if (Node > T->NOE)
        {
            return -1;
        }
        if (T->parents[Node] == T->parents[Node + 1])
        {
            return Node + 1;
        }
        return -1;
    }
};

int main()
{

    return 0;
}