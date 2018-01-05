#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <iostream>

using namespace std;

#define F(x) p*exp(-x)+q*sin(x)+r*cos(x)+s*tan(x)+t*(x)*(x)+u

typedef long long LL;
const double eps = 1e-14;

int main()
{
    freopen("in.txt", "r", stdin);
    int p,q,r,s,t,u;
    while(scanf("%d%d%d%d%d%d", &p,&q,&r,&s,&t,&u) == 6)
    {
        double f0 = F(0), f1 = F(1);
        if(f0 < -eps || f1 > eps)
            printf("No solution\n");
        else
        {
            double x = 0, y = 1, m;
            while(y - x > eps)
            {
                m = (x + y) / 2;
                if(F(m) > eps) x = m;
                else y = m;
            }
            printf("%.4lf\n", m);
        }
    }

    return 0;
}
