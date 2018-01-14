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


const double eps = 1e-8;

vector<double> x;
vector<double> y;

double euclideanDist(int p1, int p2)
{
    return sqrt((x[p1] - x[p2])*(x[p1] - x[p2]) +
        (y[p1] - y[p2])*(y[p1] - y[p2]));
}

double solve(int n)
{
    vector<vector<double> > dp(n+1, vector<double>(n+1, -1.0));
    dp[1][1] = 0.0;
    for (int i = 1; i <= n-1; i++)
    {
        for (int j = 1; j <= n-1; j++)
        {
            if (fabs(dp[i][j]+1.0) < eps) continue;
            int m = max(i, j);
            double d = euclideanDist(i, m+1);
            if (fabs(dp[m+1][j]+1.0) < eps || dp[m+1][j] > dp[i][j] + d)
                dp[m+1][j] = dp[i][j] + d;
            d = euclideanDist(j, m+1);
            if (fabs(dp[i][m+1]+1.0) < eps || dp[i][m+1] > dp[i][j] + d)
                dp[i][m+1] = dp[i][j] + d;
        }
    }
    double &ans = dp[n][n];
    dp[n][n] = dp[1][n] + euclideanDist(1, n);
    for (int i = 2; i <= n-1; i++)
        dp[n][n] = min(dp[n][n], dp[i][n]+euclideanDist(i, n));
    for (int j = 1; j <= n-1; j++)
        ans = min(ans, dp[n][j]+euclideanDist(j, n));
    return ans;
}

int main()
{
    int n;
    while (scanf("%d", &n) != EOF)
    {
        x.resize(n+1, 0.0);
        y.resize(n+1, 0.0);
        for (int i = 1; i <= n; i++)
            scanf("%lf%lf", &x[i], &y[i]);

        printf("%.2f\n", solve(n));
    }
    return 0;
}
