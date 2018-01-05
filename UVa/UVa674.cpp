#include <cstdio>
#include <cstring>

int dp[7500][6];
int m[6] = {0,1,5,10,25,50};

int dfs_dp(int n, int k)
{
    if(dp[n][k]>0)
        return dp[n][k];
    if(k == 0 && n == 0)
        return dp[n][k] = 1;
    if(k == 1 || n == 1)
        return dp[n][k] = 1;
    if(n < m[k])
        return dp[n][k] = dfs_dp(n,k-1);
    return dp[n][k] = dfs_dp(n-m[k], k)+dfs_dp(n, k-1);
}

int main()
{
    #ifdef LOCAL
    freopen("in.txt","r",stdin);
    #endif
    int money;
    for(int i=1;i<=7489;i++)
        for(int j=1;j<=5;j++)
            dfs_dp(i,j);
    while(scanf("%d",&money)!=EOF)
    {
        if(money == 0) printf("1\n");
        else printf("%d\n",dp[money][5]);
    }
    return 0;
}
