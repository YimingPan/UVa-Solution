#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <cctype>
#include <iostream>
#include <map>
#include <string>

using namespace std;

const int MAX_DEPTH = 16;

typedef long long LL;

int main()
{
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
#endif
    int cas;
    string str; // describe tree structure
    map<LL, int> vCnt;
    cin >> cas;
    while(cas--)
    {
        int depth = 0, maxv = 0, leafnum = 0;
        cin >> str;
        vCnt.clear();
        for(int i=0; i<(int)str.size(); i++)
        {
            if(str[i] == '[') depth++;
            else if(str[i] == ']') depth--;
            else if(isdigit(str[i]))
            {
                LL x = str[i] - '0';
                while(isdigit(str[i+1]))
                {
                    x = x*10 + (str[i+1] - '0');
                    i++;
                }
                LL w = x*(1<<depth);
                vCnt[w] = vCnt[w] + 1;
                leafnum++;
                if(vCnt[w] > maxv) maxv = vCnt[w];
            }
        }
        cout << leafnum - maxv << endl;
    }

    return 0;
}
