#include <cstdio>
#include <cstdlib>
using namespace std;

int card[500001];

void init() //打表 答案有规律
{
    card[1] = 1;
    int i = 2, a = 1;   //a是每一循环的项数
    while(i <= 500000)
    {
        for(int k=1;k<=a;k++)
        {
            card[i ++] = 2*k;
            if(i > 500000) break;
        }
        a = a*2;
    }
}

int main()
{
    int n;
    init();
//    for(int i=1;i<=100;i++)
//        printf("%d : %d\n",i,card[i]);
    while(scanf("%d",&n) && n!=0)
    {
        printf("%d\n",card[n]);
    }
    return 0;
}
