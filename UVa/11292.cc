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


int head[20005];
int height[20005];

int main()
{
    int n, m;
    while (cin >> n >> m && n && m)
    {
        for (int i = 0; i < n; i++)
            cin >> head[i];
        for (int i = 0; i < m; i++)
            cin >> height[i];
        sort(head, head+n);
        sort(height, height+m);

        int p = 0;
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            while (p < m && height[p] < head[i])
                p++;
            if (p < m)
                ans += height[p++];
            else
                ans = -1;
        }
        if (ans == -1)
            cout << "Loowater is doomed!\n";
        else
            cout << ans << endl;
    }
    return 0;
}
