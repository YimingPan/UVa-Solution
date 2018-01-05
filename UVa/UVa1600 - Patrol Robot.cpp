#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <cctype>
#include <iostream>
#include <queue>

using namespace std;

const int MAXN = 25;
const int dx[4] = {1, -1, 0, 0};
const int dy[4] = {0, 0, 1, -1};

int G[MAXN][MAXN];
int vis[MAXN][MAXN];
int obs[MAXN][MAXN];

struct Point
{
    int x,y;
    int ob;

    Point(int x, int y, int ob=0):x(x),y(y),ob(ob) {}
};

bool isValid(Point &p, int r, int c)
{
    if( p.x >= 1 && p.x <= r && p.y >= 1 && p.y <= c )
        return true;
    else
        return false;
}

int bfs(int r, int c, int k)
{
    memset(vis, -1, sizeof(vis));
    memset(obs, 0, sizeof(obs));
    queue<Point> mq;
    mq.push(Point(1, 1));
    vis[1][1] = 0;
    while(!mq.empty())
    {
        Point f = mq.front(); mq.pop();
        if(vis[r][c] >= 0) return vis[r][c];
        for(int i=0; i<4; i++)
        {
            Point np(f.x+dx[i], f.y+dy[i]);
            if(G[np.x][np.y])
                np.ob = f.ob+1;
            else np.ob = 0;
            if(isValid(np, r, c))
            {
                if( (vis[np.x][np.y] == -1 && np.ob <= k) ||
                    (vis[np.x][np.y] > -1 && np.ob < obs[np.x][np.y]) )
                {
                    mq.push(np);
                    vis[np.x][np.y] = vis[f.x][f.y]+1;
                    obs[np.x][np.y] = np.ob;
                }
            }
        }
    }
    return -1;
}

int main()
{
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int cas, n, m, k;
    scanf("%d", &cas);
    while(cas--)
    {
        scanf("%d%d%d", &m ,&n, &k);
        for(int i=1; i<=m; i++)
            for(int j=1; j<=n; j++)
                scanf("%d", &G[i][j]);
        printf("%d\n", bfs(m, n, k));
//        for(int i=1; i<=m; i++)
//        {
//            for(int j=1; j<=n; j++)
//                printf("%d ", vis[i][j]);
//            printf("\n");
//        }
    }

    return 0;
}
