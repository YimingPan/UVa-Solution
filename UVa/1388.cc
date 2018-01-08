#include <cstdio>
#include <cstring>
#include <cmath>
#include <climits>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>

using namespace std;

typedef long long LL;


int main()
{
    int n, m;
    const double perimeter = 10000.0;
    while (scanf("%d%d", &n, &m) == 2)
    {
        double tot = 0.0;
        for (int i = 1; i < n; i++)
        {
            double c = perimeter / n * i;
            double min_dist = 10000.0;
            for (int j = 1; j < m+n; j++)
            {
                double c2 = perimeter / (m+n) * j;
                min_dist = min(min_dist, fabs(c - c2));
            }
            tot += min_dist;
        }
        printf("%.4f\n", tot);
    }
    return 0;
}
