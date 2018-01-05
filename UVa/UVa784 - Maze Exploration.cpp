#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <iostream>
#define MAX(x,y) (x)>(y)?(x):(y)
#define MIN(x,y) (x)<(y)?(x):(y)
using namespace std;

char map[35][85];
int nCol[35],nRow;
int dirx[4] = {1,-1,0,0};
int diry[4] = {0,0,1,-1};

void dfs(int x,int y)//x is row
{
    int x1,y1;
    map[x][y] = '#';
    for(int i=0;i<4;i++)
    {
        x1 = x + dirx[i];
        y1 = y + diry[i];
        if(x1 >= 0 && x1 <= nRow && y1 >= 0 && y1 <= nCol[x1]
           && map[x1][y1] == ' ')
        {
            dfs(x1,y1);
        }
    }
}

int main()
{
    freopen("in.txt","r",stdin);
    int nCase;
    int sx,sy;
    scanf("%d",&nCase);
    getchar();
    while(nCase --)
    {
        memset(map,0,sizeof(map));
        memset(nCol,0,sizeof(nCol));
        nRow = 0;
        while(gets(map[nRow]))
        {
            nCol[nRow] = strlen(map[nRow])-1;
            if(map[nRow][0] == '_') break;
            nRow ++;
        }
        //find start point
        bool flag = 0;
        for(int i=0;i<=nRow;i++)
        {
            for(int j=0;j<=nCol[i];j++)
            {
                if(map[i][j] == '*')
                {
                    sx = i; sy = j;
                    flag = 1;
                    break;
                }
            }
            if(flag) break;
        }
        dfs(sx,sy);
        for(int i=0;i<=nRow;i++)
        {
            for(int j=0;j<=nCol[i];j++)
            {
                printf("%c",map[i][j]);
            }
            printf("\n");
        }
    }
    return 0;
}
