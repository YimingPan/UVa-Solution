// 矩阵快速幂
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long LL;

const int MAXN = 17;

int mod, dimension, n;

struct Matrix
{
    LL mat[MAXN][MAXN];

    Matrix() { memset(mat, 0, sizeof(mat)); }

    Matrix(LL m[MAXN][MAXN])
    {
        for(int i=0; i<dimension; i++)
            for(int j=0; j<dimension; j++)
                mat[i][j] = m[i][j];
    }

    Matrix operator * (const Matrix& b)
    {
        Matrix ans;
        for(int i=0; i<dimension; i++)
            for(int j=0; j<dimension; j++)
                for(int k=0; k<dimension; k++)
                    ans.mat[i][j] = (ans.mat[i][j] + mat[i][k] * b.mat[k][j] % mod) % mod;
        return ans;
    }
};

Matrix quick_pow(Matrix& a, int N)
{
    Matrix ans;
    for(int i=0; i<dimension; i++)
        ans.mat[i][i] = 1;
    while(N)
    {
        if(N & 1) ans = ans * a;
        a = a * a;
        N >>= 1;
    }
    return ans;
}

int main()
{
    freopen("in.txt", "r", stdin);
    while(scanf("%d%d%d", &dimension, &n, &mod) != EOF)
    {
        if(!dimension && !n && !mod) break;

        LL A[MAXN][MAXN], F[MAXN];
        memset(A, 0, sizeof(A));
        for(int j=dimension-1; j>=0; j--)
            scanf("%lld", &A[dimension-1][j]);
        for(int i=0; i<dimension-1; i++)
            A[i][i+1] = 1;
        for(int i=0; i<dimension; i++)
            scanf("%lld", &F[i]);
        Matrix matA(A);

        matA = quick_pow(matA, n-dimension);
        LL fn = 0;
        for(int j=0; j<dimension; j++)
            fn = (fn + matA.mat[dimension-1][j] * F[j] % mod) % mod;
        printf("%lld\n", fn);
    }

    return 0;
}
