#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char code[500],message[500];
    while(scanf("%s",code) != EOF)
    {
        int i;
        int len = strlen(code);
        for(i=0;i<len;i++)
            message[i] = code[i] - 7;
        message[len] = '\0';
        puts(message);
    }
    return 0;
}
