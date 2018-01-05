#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <iostream>

using namespace std;

typedef long long LL;
const double eps = 1e-10;
const int MAXN = 10010;

int n, a[MAXN], b[MAXN], c[MAXN];

double F(double x)
{
    double ans = a[0]*x*x+b[0]*x+c[0];
    for(int i=1; i<n; i++)
        ans = max(ans, a[i]*x*x+b[i]*x+c[i]);
    return ans;
}

int main()
{
    freopen("in.txt", "r", stdin);
    int T;
    scanf("%d", &T);
    while(T--)
    {
        scanf("%d", &n);
        for(int i=0; i<n; i++)
            scanf("%d%d%d", &a[i], &b[i], &c[i]);
        double L = 0.0, R = 1000.0, m1, m2;
        while(R - L > eps)
        {
            m1 = L + (R-L)/3;
            m2 = R - (R-L)/3;
            if(F(m1) < F(m2)) R = m2;
            else L = m1;
        }
        printf("%.4f\n", F(L));
    }

    return 0;
}
