#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char str[500];
    int i,counter;
    while(gets(str) != NULL)
    {
        int len;
        len = strlen(str);
        if(len == 0) break;
        counter = 0;
        for(i=0;i<len;i++)
        {
            if(isalpha(str[i]) && !isalpha(str[i+1]))
                counter ++;
        }
        printf("%d\n",counter);
    }
    return 0;
}
