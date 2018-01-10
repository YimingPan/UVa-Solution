#include <cstdio>
#include <cstring>
#include <cmath>
#include <climits>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>

using namespace std;

typedef long long LL;


const int MAXN = 15;

int G[MAXN][MAXN];
int flip[MAXN][MAXN];

int getParity(int i, int j, int n)
{
    int parity = 0;
    if (i > 0) parity += G[i-1][j] | flip[i-1][j];
    if (i < n-1) parity += G[i+1][j] | flip[i+1][j];
    if (j > 0) parity += G[i][j-1] | flip[i][j-1];
    if (j < n-1) parity += G[i][j+1] | flip[i][j+1];
    return parity;
}

int getFlipTime(int n)
{
    for (int i = 0; i < n-1; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (getParity(i, j, n) % 2 == 1)
            {
                if (G[i+1][j] == 0)
                    flip[i+1][j] = 1;
                else
                    return -1;
            }
        }
    }
    // Check the last row
    for (int j = 0; j < n; j++)
        if (getParity(n-1, j, n) % 2 == 1)
            return -1;
    int totFlipTime = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            totFlipTime += flip[i][j];
    return totFlipTime;
}

int solve(int n)
{
    int min_ans = -1;
    for (int i = 0; i < (1<<n)-1; i++)
    {
        bool ok = true;
        for (int j = 0; j < n; j++)
            if (G[0][j] == 1 && (i & (1<<j)) > 0)
            {
                ok = false;
                break;
            }
        if (!ok) continue;
        memset(flip, 0, sizeof(flip));
        for (int j = 0; j < n; j++)
            flip[0][j] = (1 & (i>>j));
        int flipTime = getFlipTime(n);
        if (flipTime != -1)
        {
            if (min_ans == -1)
                min_ans = flipTime;
            else
                min_ans = min(min_ans, flipTime);
        }
    }
    return min_ans;
}

int main()
{
    int caseNum, n;
    scanf("%d", &caseNum);
    for (int kase = 1; kase <= caseNum; kase++)
    {
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                scanf("%d", &G[i][j]);
        printf("Case %d: %d\n", kase, solve(n));
    }
    return 0;
}
