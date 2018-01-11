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


int f(int n)
{
    return n == 1 ? 1 : f(n/2) + 1;
}

int main()
{
    int N;
    while (cin >> N)
    {
        cout << f(N) << endl;
    }
    return 0;
}
