#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

int main()
{
    freopen("input.txt","r",stdin);
    char c[] = "`1234567890-=QWERTYUIOP[]\\ASDFGHJKL;'ZXCVBNM,./";
    char ch;
    int i;
    while((ch = getchar()) != EOF)
    {
        for(i=1; c[i] && c[i] != ch; i++);
        if(c[i]) putchar(c[i-1]);
        else putchar(ch);
    }
    return 0;
}
