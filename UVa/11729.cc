#include <cstdio>
#include <cstring>
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


struct Soldier
{
    int B, J;

    bool operator < (const Soldier& rhl) const
    {
        return J > rhl.J;
    }
};

Soldier soldiers[1000];

int main()
{
    int n;
    int case_cnt = 0;
    while (cin >> n && n)
    {
        case_cnt ++;
        for (int i = 0; i < n; i++)
            cin >> soldiers[i].B >> soldiers[i].J;
        sort(soldiers, soldiers + n);

        int end_time = soldiers[0].B + soldiers[0].J;
        int total_time = end_time;
        for (int i = 1; i < n; i++)
        {
            end_time = end_time - soldiers[i-1].J + soldiers[i].B +
                soldiers[i].J;
            total_time = max(total_time, end_time);
        }
        cout << "Case " << case_cnt << ": " << total_time << endl;
    }
    return 0;
}
