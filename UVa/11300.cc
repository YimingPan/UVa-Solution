#include <cstdio>
#include <cstring>
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


const int MAXN = 1000001;

LL coins[MAXN];
LL C[MAXN];

int main()
{
    int n;
    while (scanf("%d", &n) != EOF)
    {
        LL sum = 0;
        for (int i = 0; i < n; i++)
        {
            scanf("%lld", &coins[i]);
            sum += coins[i];
        }
        LL ave = sum / n;
        C[0] = 0;
        for (int i = 1; i < n; i++)
            C[i] = C[i-1] + coins[i-1] - ave;
        sort(C, C+n);

        LL x0 = C[n/2];
        LL ans = 0;
        for (int i = 0; i < n; i++)
            ans += abs(x0 - C[i]);
        printf("%lld\n", ans);
    }
    return 0;
}
