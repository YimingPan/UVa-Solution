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


int mat[11][101];
int dp[11][101];
int nextRow[11][101];

int main()
{
    int m, n;
    while (scanf("%d%d", &m, &n) == 2)
    {
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                scanf("%d", &mat[i][j]);
        for (int i = 0; i < m; i++)
        {
            dp[i][n-1] = mat[i][n-1];
            nextRow[i][n-1] = -1;
        }
        for (int j = n-2; j >= 0; j--)
        {
            for (int i = 0; i < m; i++)
            {
                int rows[3] = {(i-1+m)%m, i, (i+1)%m};
                sort(rows, rows+3);

                int tmp = dp[rows[0]][j+1];
                nextRow[i][j] = rows[0];
                for (int k = 1; k < 3; k++)
                {
                    int r = rows[k];
                    if (tmp > dp[r][j+1])
                    {
                        nextRow[i][j] = r;
                        tmp = dp[r][j+1];
                    }
                }
                dp[i][j] = tmp + mat[i][j];
            }
        }
        // print answer
        vector<int> path;
        int ans = dp[0][0];
        int firstRow = 0;
        for (int i = 1; i < m; i++)
        {
            if (ans > dp[i][0])
            {
                ans = dp[i][0];
                firstRow = i;
            }
        }
        int p = firstRow, c = 0;
        while (p != -1)
        {
            path.push_back(p+1);
            p = nextRow[p][c];
            c++;
        }
        for (int i = 0; i < (int) path.size()-1; i++)
            printf("%d ", path[i]);
        printf("%d\n%d\n", path[n-1], ans);
    }
    return 0;
}
