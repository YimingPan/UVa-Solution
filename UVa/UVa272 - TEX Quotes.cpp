#include <stdio.h>
#include <string.h>

int main()
{
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    char ch;
    int flag = 1;
    while((ch = getchar()) != EOF)
    {
        if(ch != '"') putchar(ch);
        else if(flag) { printf("``"); flag = 0; }
        else { printf("''"); flag = 1; }
    }
    return 0;
}
