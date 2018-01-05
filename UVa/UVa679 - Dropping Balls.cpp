#include <cstdio>
int main()
{
    int D, I;   //FBT最大深度，第I只球
    int nCase;
    while(scanf("%d",&nCase), nCase != -1)
    {
        while(nCase --)
        {
            int k = 1;  //最后一个小球依次经过的节点编号
            scanf("%d%d",&D,&I);
            for(int i=0;i<D-1;i++)
            {
                //分奇偶两种情况讨论
                k = k*2-I%2+1;
                I = (I+I%2)/2;
            }
            printf("%d\n",k);
        }
    }
    return 0;
}
