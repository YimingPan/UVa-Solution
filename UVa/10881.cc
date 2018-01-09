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


struct Ant
{
    int pos;
    int id;
    int dir; // 0: left, 1: right, 2: turning
};

const int MAXN = 10005;
const char DIR[][10] = {"L", "R", "Turning"};

Ant ants_start[MAXN], ants_end[MAXN];

bool cmp_pos(Ant& a, Ant& b)
{
    return a.pos < b.pos;
}

bool cmp_id(Ant& a, Ant& b)
{
    return a.id < b.id;
}

int main()
{
    int kase;
    int L, T, n;
    cin >> kase;
    for (int k = 1; k <= kase; k++)
    {
        cin >> L >> T >> n;
        for (int i = 0; i < n; i++)
        {
            char ch;
            cin >> ants_start[i].pos >> ch;
            ants_start[i].dir = (ch == 'L') ? 0 : 1;
            ants_start[i].id = i;
            ants_end[i] = ants_start[i];
            ants_end[i].pos += (ch == 'L') ? -T : T;
        }
        sort(ants_start, ants_start+n, cmp_pos);
        sort(ants_end, ants_end+n, cmp_pos);
        for (int i = 0; i < n; i++)
            ants_end[i].id = ants_start[i].id;
        for (int i = 0; i < n-1; i++)
        {
            if (ants_end[i].pos == ants_end[i+1].pos)
                ants_end[i].dir = ants_end[i+1].dir = 2;
        }
        sort(ants_end, ants_end+n, cmp_id);

        cout << "Case #" << k << ":\n";
        for (int i = 0; i < n; i++)
        {
            if (ants_end[i].pos < 0 || ants_end[i].pos > L)
                cout << "Fell off\n";
            else
                cout << ants_end[i].pos << " " << DIR[ants_end[i].dir] << endl;
        }
        cout << "\n";
    }
    return 0;
}
