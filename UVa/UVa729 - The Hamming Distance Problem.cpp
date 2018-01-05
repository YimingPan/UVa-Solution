//还是简单全排列，调用STL即可
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main()
{
    int cas,N,H;
    char num[20];
    scanf("%d",&cas);
    while(cas--)
    {
        scanf("%d%d",&N,&H);
        for(int i=1;i<=N-H;i++) num[i] = '0';
        for(int i=N-H+1;i<=N;i++) num[i] = '1';
        num[N+1] = '\0';
        do
        {
            puts(num+1);
        }while(next_permutation(num+1,num+1+N));
        if(cas>0) printf("\n");//最后一组数据后不输出
    }
    return 0;
}
