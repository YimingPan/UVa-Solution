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


const int MAX_BLOCKS_NUM = 30+5;

vector<vector<int> > blocks(MAX_BLOCKS_NUM, vector<int>(3, 0));
int dp[MAX_BLOCKS_NUM][3];

bool smaller(int b1, int h1, int b2, int h2)
{
    vector<int> e1, e2;
    for (int i = 0; i < 3; i++)
        if (i != h1)
            e1.push_back(blocks[b1][i]);
    for (int i = 0; i < 3; i++)
        if (i != h2)
            e2.push_back(blocks[b2][i]);
    if ((e1[0] < e2[0] && e1[1] < e2[1]) || (e1[0] < e2[1] && e1[1] < e2[0]))
        return true;
    return false;
}

int max_height(int a, int b, int n)
{
    if (dp[a][b] != -1) return dp[a][b];
    int tmp = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (!smaller(i, j, a, b)) continue;
            tmp = max(tmp, max_height(i, j, n));
        }
    }
    dp[a][b] = tmp+blocks[a][b];
    return dp[a][b];
}

int main()
{
    int n, kase = 1;
    while (cin >> n && n)
    {
        for (int i = 0; i < n; i++)
            cin >> blocks[i][0] >> blocks[i][1] >> blocks[i][2];
        memset(dp, -1, sizeof(dp));
        int maxh = 0;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < 3; j++)
            {
                int h = max_height(i, j, n);
                maxh = max(maxh, h);
            }
        cout << "Case " << kase++ << ": maximum height = ";
        cout << maxh << endl;
    }
    return 0;
}
