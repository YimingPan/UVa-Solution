/**UVA 10054 0KB 288MS C++ 4.8.2
 * 图可能有重边，且可能有多个连通分量
 * 一个case中可能只出现一部分颜色
 */
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
#include <stack>
#include <string>
#include <vector>
using namespace std;
#define LL long long

typedef pair<int,int> pii;

int degree[51];
int mp[51][51];

bool is_euler_graph(int n)
{
    for(int i=1; i<=n; i++)
        if(degree[i] & 1)
            return false;
    return true;
}

int cnt;//欧拉回路中边数
stack<pii> ms;
void print_path(int u)
{
    cnt++;
    for(int v=1; v<=50; v++)
        if(mp[u][v])
        {
            mp[u][v]--;
            mp[v][u]--;
            print_path(v);
            ms.push(make_pair(u,v));
        }
}

int main()
{
    freopen("in.txt","r",stdin);
    int n,cas,st;
    scanf("%d", &cas);
    for(int cc = 1; cc<=cas; cc++)
    {
        scanf("%d", &n);
        memset(mp, 0, sizeof(mp));
        memset(degree, 0, sizeof(degree));
        for(int i=0; i<n; i++)
        {
            int a,b;
            scanf("%d%d", &a,&b);
            mp[a][b]++;
            mp[b][a]++;
            degree[a]++;
            degree[b]++;
            st = a;
        }

        printf("Case #%d\n", cc);
        if(!is_euler_graph(50))
            printf("some beads may be lost\n");
        else
        {
            cnt = 0;
            print_path(st);//dfs的起点应是出现过的颜色
            if(cnt-1 < n)
                printf("some beads may be lost\n");
            else while(!ms.empty())
            {
                pii tmp = ms.top();
                ms.pop();
                printf("%d %d\n", tmp.first, tmp.second);
            }
        }
        if(cc < cas) printf("\n");
    }
    return 0;
}
