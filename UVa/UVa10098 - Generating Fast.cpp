//考察枚举全排列的技巧
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main()
{
    freopen("in.txt","r",stdin);
    char str[11];
    int len,n;
    scanf("%d",&n);
    getchar();
    while(n--)
    {
        gets(str);
        len = strlen(str);
        sort(str,str+len);
        do
        {
            puts(str);
        }while(next_permutation(str,str+len));
        printf("\n");
    }
    return 0;
}
