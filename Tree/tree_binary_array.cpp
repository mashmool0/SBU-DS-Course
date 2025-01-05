#include <bits/stdc++.h>
using namespace std;
#define MAX 100

class Tree
{
public:
    int Elements[MAX];
    int NOE;

    int LC(int pos)
    {
        return pos * 2;
    }
    int RC(int pos)
    {
        return pos * 2 + 1;
    }
};

int main()
{

    return 0;
}