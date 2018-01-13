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


const int MAXT = 200 + 5;
const int MAXN = 50 + 5;

int N, T, M1, M2;
int depart_1[55], depart_N[55];
int travel_time[MAXN];
int tsum_l[MAXN], tsum_r[MAXN];
int dp[MAXT][MAXN];

bool hasTrain(int t, int s, string dir)
{
    if (dir == "L")
    {
        int departTime = t - tsum_l[s];
        return binary_search(depart_1+1, depart_1+M1+1, departTime);
    }
    else
    {
        int departTime = t - tsum_r[s];
        return binary_search(depart_N+1, depart_N+M2+1, departTime);
    }
}

int solve()
{
    tsum_l[1] = 0;
    for (int i = 2; i <= N; i++)
        tsum_l[i] = tsum_l[i-1]+travel_time[i-1];
    tsum_r[N] = 0;
    for (int i = N-1; i >= 1; i--)
        tsum_r[i] = tsum_r[i+1]+travel_time[i];

    for (int t = 0; t <= T; t++)
        for (int s = 1; s <= N; s++)
            dp[t][s] = INT_MAX;
    dp[0][1] = 0;
    for (int t = 0; t < T; t++)
    {
        for (int s = 1; s <= N; s++)
        {
            if (dp[t][s] == INT_MAX) continue;
            dp[t+1][s] = min(dp[t+1][s], dp[t][s]+1);
            if (hasTrain(t, s, "L") && s < N && t + travel_time[s] <= T)
            {
                int &res = dp[ t + travel_time[s] ][s+1];
                res = min(res, dp[t][s]);
            }
            if (hasTrain(t, s, "R") && s > 1 && t + travel_time[s-1] <= T)
            {
                int &res = dp[ t + travel_time[s-1] ][s-1];
                res = min(res, dp[t][s]);
            }
        }
    }
    return dp[T][N] < INT_MAX ? dp[T][N] : -1;
}

int main()
{
    int kase = 1;
    while (scanf("%d", &N) && N)
    {
        scanf("%d", &T);
        for (int i = 1; i <= N-1; i++)
            scanf("%d", &travel_time[i]);
        scanf("%d", &M1);
        for (int i = 1; i <= M1; i++)
            scanf("%d", &depart_1[i]);
        scanf("%d", &M2);
        for (int i = 1; i <= M2; i++)
            scanf("%d", &depart_N[i]);

        int ans = solve();
        printf("Case Number %d: ", kase++);
        if (ans != -1) printf("%d\n", ans);
        else printf("impossible\n");
    }
    return 0;
}
