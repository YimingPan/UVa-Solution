#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int sticksNum;
int lenSum;
int singleLen;
int sticks[200];
bool vis[200];

bool testLen(int len, int num, int cur)
{
    printf("%d %d %d\n", len, num, cur);
    if (num == lenSum / singleLen)
        return true;
    for (int i = cur; i < sticksNum; i++)
    {
        if (!vis[i] && sticks[i] <= len)
        {
            vis[i] = true;
            int lenLeft = len - sticks[i];
            bool ok;
            if (lenLeft == 0)
                ok = testLen(singleLen, num+1, 0);
            else
                ok = testLen(lenLeft, num, i+1);

            if (ok)
                return true;
            else
            {
                vis[i] = false;
                if (len == singleLen && cur == 0)
                    break;
                if (len == sticks[i])
                    break;
                while (i+1 < sticksNum && sticks[i+1] == sticks[i])
                    i ++;
            }
        }
    }
    return false;
}

int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    while (scanf("%d", &sticksNum) == 1 && sticksNum)
    {
        lenSum = 0;
        for (int i = 0; i < sticksNum; i++)
        {
            scanf("%d", &sticks[i]);
            lenSum += sticks[i];
        }
        sort(sticks, sticks + sticksNum, greater<int>());
        int maxlen = sticks[0];

        for (int L = maxlen; L <= lenSum; L++)
        {
            if (lenSum % L == 0)
            {
                singleLen = L;
                for (int i = 0; i < sticksNum; i++)
                    vis[i] = false;
                if (testLen(L, 0, 0))
                {
                    printf("%d\n", L);
                    break;
                }
            }
        }
    }
    return 0;
}

