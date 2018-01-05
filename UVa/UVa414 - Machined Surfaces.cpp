#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    freopen("input.txt","r",stdin);
    int N, min, ans, nVoid[13];
    char surface[26];
    while(cin >> N, N)
    {
        getchar();
        min = 30;
        ans = 0;
        for(int i=0;i<N;i++) nVoid[i] = 0;
        for(int i=0;i<N;i++)
        {
            gets(surface);
            for(int j=0;j<25;j++)
                if(surface[j] != 'X')
                    nVoid[i] ++;
            if(nVoid[i] < min) min = nVoid[i];
        }
        for(int i=0;i<N;i++)
            ans += nVoid[i] - min;
        cout << ans << endl;
    }
    return 0;
}
