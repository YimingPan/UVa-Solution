#include <cstdio>
#include <stack>
using namespace std;

int main()
{
    int n;  //The number of coaches. n<=1000
    while(scanf("%d",&n), n)
    {
        int out[1005];  //store the order of coming out
        while(scanf("%d",&out[1]), out[1])
        {
            int A = 1, B = 1;   //A是入站的列车编号，B是out的指针
            stack<int> in;
            bool ok = 1;
            for(int i=2;i<=n;i++) scanf("%d",&out[i]);
            while(B <= n)
            {
                if(A == out[B])
                {
                    A ++;
                    B ++;
                }
                else if(!in.empty() && out[B] == in.top())
                {
                    B ++;
                    in.pop();
                }
                else if(A <= n)     //"A < out[B]" is also right
                {
                    in.push(A);
                    A ++;
                }
                else
                {
                    ok = 0;
                    break;
                }
            }
            if(ok) printf("Yes\n");
            else printf("No\n");
        }
        printf("\n");
    }
    return 0;
}
