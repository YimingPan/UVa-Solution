#include <stdio.h>
#include <string.h>

int main()
{
    char str[100][101];
    int n = 0, maxLen = -1, len;
    int i,j;
    memset(str,0,sizeof(str));
    while(gets(str[n]) != NULL)
    {
        len = strlen(str[n]);
        if(len > maxLen) maxLen = len;
        n ++;
    }
    for(i=0;i<maxLen;i++)
    {
        for(j=n-1;j>=0;j--)
        {
            if(str[j][i] == '\0')
                printf(" ");
            else
                printf("%c",str[j][i]);
        }
        printf("\n");
    }
    return 0;
}

