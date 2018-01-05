#include <cstdio>
#include <queue>
using namespace std;

int main()
{
    int n;  //n表示总卡片数
    while(scanf("%d",&n), n)
    {
        queue<int> q;   //开始时队列必须为空，故每次重建一个
        for(int i=1;i<=n;i++) q.push(i);
        printf("Discarded cards:");
        for(int k=0;k<n-1;k++)  //k表示丢弃的张数
        {
            if(k == n-2) printf(" %d",q.front());   //输出格式校正
            else printf(" %d,",q.front());
            q.pop();    //丢弃第一张牌，第二章牌成为队首元素
            q.push(q.front());  //第二张牌入队
            q.pop();
        }
        printf("\nRemaining card: %d\n",q.front());
    }
    return 0;
}
