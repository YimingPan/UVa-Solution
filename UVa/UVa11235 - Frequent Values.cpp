#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

const int MAXN = 1e5+5;
int num[MAXN],left[MAXN],right[MAXN],value[MAXN],appear[MAXN];
int elem[MAXN],dp[MAXN][20];

void initRMQ(int nPart)//nPart:the number of elements in appear[]
{
    for(int i=1;i<=nPart;i++) dp[i][0] = appear[i];
    for(int j=1; (1<<j)<=nPart; j++)
        for(int i=1; i+(1<<j)-1<=nPart; i++)
            dp[i][j] = max(dp[i][j-1], dp[i + (1<<(j-1))][j-1]);
}

int RMQ_query(int l, int r)
{
    int len = 0;
    while((1<<(len+1)) <= r-l+1) len++;
    return max(dp[l][len], dp[r-(1<<len)+1][len]);
}

int main()
{
    #ifdef LOCAL
    freopen("in.txt","r",stdin);
    #endif
    int N,Q,ql,qr,nPart,ans;
    while(scanf("%d",&N), N)
    {
        scanf("%d",&Q);
        for(int i=1;i<=N;i++) scanf("%d",&elem[i]);
        num[1] = 1; left[1] = 1; right[N] = N; value[num[1]] = elem[1]; appear[1] = 1;
        nPart = 1;
        for(int i=2;i<=N;i++)
        {
            if(elem[i] == elem[i-1])
            {
                num[i] = num[i-1];
                left[i] = left[i-1];
                appear[num[i]]++;
            }
            else
            {
                nPart++;
                num[i] = num[i-1]+1;
                left[i] = i;
                value[num[i]] = elem[i];
                appear[num[i]] = 1;
            }
        }
        for(int i=N-1;i>=1;i--)
        {
            if(elem[i] == elem[i+1]) right[i] = right[i+1];
            else right[i] = i;
        }
        initRMQ(nPart);
        for(int k=1;k<=Q;k++)
        {
            scanf("%d%d",&ql,&qr);
            if(num[ql] == num[qr])//they are in the same part
                ans = qr-ql+1;
            else if(num[ql]+1 == num[qr])
                ans = max(right[ql]-ql+1, qr-left[qr]+1);
            else
                ans = max(right[ql]-ql+1, max(qr-left[qr]+1, RMQ_query(num[ql]+1, num[qr]-1)));
            printf("%d\n",ans);
        }
    }
    return 0;
}
