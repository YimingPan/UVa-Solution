#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <functional>
#include <queue>
#define MAX(x,y) (x)>(y)?(x):(y)
#define MIN(x,y) (x)<(y)?(x):(y)
using namespace std;

int w,h;//width<=>y,height<=>x
int dirx[4] = {1,-1,0,0};
int diry[4] = {0,0,1,-1};
char map[51][51];
bool vst[51][51];

int cnt;
void dfs2(int x1,int y1)//second dfs
{
    int x2,y2;
    vst[x1][y1] = 1;
    for(int i=0;i<4;i++)
    {
        x2 = x1 + dirx[i];
        y2 = y1 + diry[i];
        if(x2 >= 0 && x2 < h && y2 >= 0 && y2 < w
           && !vst[x2][y2] && map[x2][y2] == 'X')
        {
            dfs2(x2,y2);
        }
    }
}

void dfs1(int x,int y)//first dfs
{
    int x1,y1;
    vst[x][y] = 1;
    for(int i=0;i<4;i++)
    {
        x1 = x + dirx[i];
        y1 = y + diry[i];
        if(x1 >= 0 && x1 < h && y1 >= 0 && y1 < w && map[x1][y1] != '.'
           && !vst[x1][y1])
        {
            if(map[x1][y1] == 'X')
            {
                dfs2(x1,y1);
                cnt ++;
            }
            dfs1(x1,y1);
        }
    }
}

int main()
{
    freopen("in.txt","r",stdin);
    int k = 1;
    priority_queue<int,vector<int>,greater<int> > pq;
    while(scanf("%d%d",&w,&h) == 2)
    {
        if(w == 0 && h == 0) break;
        getchar();
        memset(vst,0,sizeof(vst));
        for(int i=0;i<h;i++)
            gets(map[i]);
        for(int i=0;i<h;i++)
        {
            for(int j=0;j<w;j++)
            {
                if(map[i][j] != '.' && !vst[i][j])
                {
                    cnt = 0;
                    dfs1(i,j);
                    if(cnt >= 1 && cnt <=6)
                        pq.push(cnt);
                }
                else vst[i][j] = 1;
            }
        }
        printf("Throw %d\n",k ++);
        while(!pq.empty())
        {
            if(pq.size() == 1) printf("%d\n\n",pq.top());
            else printf("%d ",pq.top());
            pq.pop();
        }
    }
    return 0;
}
