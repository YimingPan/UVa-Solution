//调用STL“求下一个排列”的next_permutation函数即可
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int main()
{
    freopen("in.txt","r",stdin);
    char str[55];
    int len;
    while(gets(str)!=NULL)
    {
        if(str[0] == '#') break;
        len = strlen(str);
        if(next_permutation(str,str+len)) puts(str);
        else puts("No Successor");
    }
    return 0;
}
