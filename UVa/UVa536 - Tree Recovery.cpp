#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <stack>

using namespace std;

struct Tree
{
    int lc, rc;
    char v;

    void init(char val = 0)
    {
        lc = rc = 0;
        v = val;
    }
};
Tree tree[27];
int tp;

char preord[30], inord[30];

int reconstruct(int L1, int R1, int L2, int R2)
{
    if(L1 > R1) return 0;
    int x, root;
    tree[++tp].init(preord[L1]);
    root = tp;
    for(x=L2; inord[x]!=preord[L1]; x++);
    int l = x-L2;
    tree[root].lc = reconstruct(L1+1, L1+l, L2, x-1);
    tree[root].rc = reconstruct(L1+l+1, R1, x+1, R2);
    return root;
}

void traverse(int u)
{
    if(u == 0) return;
    traverse(tree[u].lc);
    traverse(tree[u].rc);
    putchar(tree[u].v);
}

int main()
{
    int N;
    while(scanf("%s%s", preord, inord) == 2)
    {
        tp = 0;
        N = strlen(preord);
        reconstruct(0, N-1, 0, N-1);
        traverse(1);
        printf("\n");
    }

    return 0;
}
