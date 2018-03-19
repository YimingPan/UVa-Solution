/*
 * UVA 11584
 * A second thought: why the following greedy algorithm does not work?
 *
 * Say the string is "aaadbccb". Each time we cut a palindrome as long as
 * possible. The first time we cut "aaa", followed by "d", and finally
 * "bccb". The number of groups got in this way is also 3.
 *
 * A contradictory example is "aaaabaaa". Using the method above we get 3
 * groups. But the minimum number is actually 2, i.e., "a" + "aaabaaa".
 */

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

int mingp[1001];
bool is_palind[1001][1001];

void init_is_palind(string &s) {
    for (int i = 0; i < s.size(); i++)
        for (int j = 0; j < s.size(); j++)
            is_palind[i][j] = true;
    for (int l = 2; l <= s.size(); l++) {
        for (int i = 0; i <= s.size() - l; i++) {
            int j = i + l - 1;
            if (s[i] != s[j])
                is_palind[i][j] = false;
            else
                is_palind[i][j] = is_palind[i+1][j-1];
        }
    }
}

int cal_mingp(string& s, int i) {
    if (is_palind[0][i])
        return 1;
    if (mingp[i] != 0)
        return mingp[i];
    int minv = 2000;
    for (int j = 0; j < i; j++) {
        if (is_palind[j+1][i]) {
            minv = min(cal_mingp(s, j), minv);
        }
    }
    return mingp[i] = minv + 1;
}

int main()
{
    string s;
    int n;
    cin >> n;
    while (n--) {
        cin >> s;
        init_is_palind(s);
        for (int i = 0; i < s.size(); i++)
            mingp[i] = 0;
        cout << cal_mingp(s, s.size()-1) << endl;
    }
    return 0;
}

