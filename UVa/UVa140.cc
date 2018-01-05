#include <cstdio>
#include <cstring>
#include <climits>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>

using namespace std;

const int MAX_NODES = 26;

int G[MAX_NODES][MAX_NODES];
vector<int> nodeList;

int read_input()
{
    string buff;
    cin >> buff;
    if (buff == "#") return 1;

    memset(G, 0, sizeof(G));
    nodeList.clear();

    unordered_set<int> nodes;
    int p = 0;
    int q = buff.find_first_of(";", 0);
    while (p < (int)buff.size())
    {
        int from = buff[p] - 'A';
        nodes.insert(from);
        for (int i = p+2; i < q; i++)
        {
            int to = buff[i] - 'A';
            G[from][to] = G[to][from] = 1;
            nodes.insert(to);
        }
        p = q+1;
        q = buff.find_first_of(";", p);
        if (q == (int)string::npos)
            q = buff.size();
    }
    for (int x : nodes)
        nodeList.push_back(x);
    sort(nodeList.begin(), nodeList.end());

    return 0;
}

int cal_bandwidth(vector<int>& ordering)
{
    int bw = -1;
    int N = ordering.size();
    for (int i = 0; i < N; i++)
    {
        int u = ordering[i];
        int max_dist = -1;
        for (int j = 0; j < N; j++)
        {
            int v = ordering[j];
            if (G[u][v] == 1)
                max_dist = max(max_dist, abs(i-j));
        }
        bw = max(bw, max_dist);
    }
    return bw;
}

int unusedNeighbor(int u, vector<bool> vis)
{
    int cnt = 0;
    for (int to : nodeList)
    {
        if (G[u][to] == 1 && !vis[to])
            cnt++;
    }
    return cnt;
}

// int node_counter;

void dfs(int cur, vector<int>& tmp_order, vector<int>& min_order,
         int& min_bw, vector<bool>& vis)
{
    // node_counter ++;
    if (cur == (int) nodeList.size())
    {
        int bw = cal_bandwidth(tmp_order);
        if (bw < min_bw)
        {
            min_bw = bw;
            min_order = tmp_order;
        }
        return;
    }
    for (int i = 0; i < (int) nodeList.size(); i++)
    {
        if (!vis[i])
        {
            // Prune #1
            if (cal_bandwidth(tmp_order) > min_bw)
                continue;
            // Prune #2
            if (unusedNeighbor(nodeList[i], vis) >= min_bw)
                break;
            tmp_order.push_back(nodeList[i]);
            vis[i] = true;
            dfs(cur+1, tmp_order, min_order, min_bw, vis);
            tmp_order.pop_back();
            vis[i] = false;
        }
    }
}

int main()
{
    while (!read_input())
    {
        int min_bw = INT_MAX;
        vector<int> tmp, ans;
        vector<bool> vis(8, false);
        // node_counter = 0;
        dfs(0, tmp, ans, min_bw, vis);
        // cout << "#node: " << node_counter << endl;

        for (int x : ans)
            cout << (char) (x+'A') << " ";
        cout << "-> " << min_bw << endl;
    }
    return 0;
}
