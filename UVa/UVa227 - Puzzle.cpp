#include <stdio.h>
#include <string.h>
#include <ctype.h>

char mat[5][9];

int main()
{
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    char steps[100];
    int len;
    int x,y;
    int ncas = 1;
    while(fgets(mat[0], 9, stdin) && mat[0][0] != 'Z')
    {
        for(int i=1; i<5; i++)
            fgets(mat[i], 9, stdin);
        for(int i=0; i<5; i++)
            for(int j=0; j<5; j++)
                if(mat[i][j] == ' ')
                {
                    x = i; y = j;
                }
        bool error = 0;
        do
        {
            scanf("%s", steps);
            len = strlen(steps);
            int n = (steps[len-1] == '0') ? len-1 : len;
            for(int i=0; i<n; i++)
            {
                if(steps[i] == 'A')
                {
                    if(x == 0) { error = 1; break; }
                    mat[x][y] = mat[x-1][y];
                    mat[x-1][y] = ' ';
                    x--;
                }
                else if(steps[i] == 'B')
                {
                    if(x == 4) { error = 1; break; }
                    mat[x][y] = mat[x+1][y];
                    mat[x+1][y] = ' ';
                    x++;
                }
                else if(steps[i] == 'L')
                {
                    if(y == 0) { error = 1; break; }
                    mat[x][y] = mat[x][y-1];
                    mat[x][y-1] = ' ';
                    y--;
                }
                else
                {
                    if(y == 4) { error = 1; break; }
                    mat[x][y] = mat[x][y+1];
                    mat[x][y+1] = ' ';
                    y++;
                }
            }
        }while(steps[len-1] != '0');
        if(ncas > 1) printf("\n");
        printf("Puzzle #%d:\n", ncas++);
        if(error) printf("This puzzle has no final configuration.\n");
        else
        {
            for(int i=0; i<5; i++)
            {
                for(int j=0; j<4; j++)
                    printf("%c ", mat[i][j]);
                printf("%c\n", mat[i][4]);
            }
        }
        getchar();
    }
    return 0;
}
