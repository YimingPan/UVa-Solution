#include <cstdio>
#include <cstring>

int main()
{
    char str[150];
    int num, i;
    while(gets(str) != NULL)
    {
        int len = strlen(str);
        if(len == 0)
            printf("\n");
        else
        {
            for(i=0;i<len;i++)
            {
                num = 0;
                while(str[i]>='0' && str[i]<='9')
                    num += str[i ++] - '0';
                if(str[i] == '!')
                    printf("\n");
                else if(str[i] != 'b')
                    while(num --) printf("%c",str[i]);
                else
                    while(num --) printf(" ");
            }
            printf("\n");
        }
    }
    return 0;
}
