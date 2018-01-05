#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cstring>
using namespace std;

int main()
{
//    freopen("input.txt","r",stdin);
    char str[100][101];
    int n = 0, maxLen = -1, len;
    memset(str,0,sizeof(str));
    while(gets(str[n]) != NULL)
    {
        n ++;
        len = strlen(str[n]);
        if(len > maxLen) maxLen = len;
    }
    for(int i=0;i<maxLen;i++)
    {
        for(int j=n;j>=0;j--)
        {
            if(str[j][i] == '\0')
                cout << " ";
            else
                cout << str[j][i];
        }
        cout << endl;
    }
    return 0;
}
