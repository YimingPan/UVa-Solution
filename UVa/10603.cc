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


struct State
{
    int v[3]; // volumes of the three jugs
    int dist; // distance to the start state

    State(int va, int vb, int vc, int d)
    {
        v[0] = va; v[1] = vb; v[2] = vc;
        dist = d;
    }
    bool operator < (const State& rhs) const
    {
        return dist > rhs.dist;
    }
};

bool vis[201][201];
int ans[201];

void update_ans(State& s)
{
    for (int i = 0; i < 3; i++)
    {
        if (ans[s.v[i]] == -1 || ans[s.v[i]] > s.dist)
            ans[s.v[i]] = s.dist;
    }
}

void solve(int a, int b, int c, int d)
{
    State cur(0, 0, c, 0);
    int cap[3];
    cap[0] = a, cap[1] = b, cap[2] = c;
    memset(vis, 0, sizeof(vis));
    memset(ans, -1, sizeof(ans));

    priority_queue<State> Q;
    Q.push(cur);
    while (!Q.empty())
    {
        cur = Q.top(); Q.pop();
        if (ans[d] != -1)
            break;
        if (vis[cur.v[0]][cur.v[1]])
            continue;
        update_ans(cur);
        vis[cur.v[0]][cur.v[1]] = true;
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (i == j) continue;
                if (cur.v[i] > 0 && cur.v[j] < cap[j])
                {
                    int t = min(cur.v[i], cap[j]-cur.v[j]);
                    State newState = cur;
                    newState.v[i] -= t;
                    newState.v[j] += t;
                    newState.dist = cur.dist + t;
                    Q.push(newState);
                }
            }
        }
    }
}

int main()
{
    int nCases, a, b, c, d;
    scanf("%d", &nCases);
    while (nCases--)
    {
        scanf("%d%d%d%d", &a, &b, &c, &d);
        solve(a, b, c, d);

        int i = d;
        while (i >= 0)
        {
            if (ans[i] != -1)
            {
                printf("%d %d\n", ans[i], i);
                break;
            }
            i--;
        }
    }
    return 0;
}
