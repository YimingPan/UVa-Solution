#include <stdio.h>
#include <stdlib.h>

int main()
{
    int size,ani,degree,sum;
    int nCase,nFarmer;
    int i;
    scanf("%d",&nCase);
    while(nCase --)
    {
        scanf("%d",&nFarmer);
        sum = 0;
        for(i=0;i<nFarmer;i++)
        {
            scanf("%d %d %d",&size,&ani,&degree);
            sum += size * degree;
        }
        printf("%d\n",sum);
    }
    return 0;
}
