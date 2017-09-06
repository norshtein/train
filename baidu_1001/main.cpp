#include<bits/stdc++.h>

using namespace std;

long long C[1005][1005];
const int MAXN = 1005;
const int MOD = 1e9 + 7;

void init()
{
    for(int i = 0;i < MAXN;i++)
        C[i][0] = 1,C[i][i] = 1;
    for(int i = 0;i < MAXN;i++)
        C[i][1] = i;

    for(int i = 2;i < MAXN;i++)
    {
        for(int j = 2;j < i;j++)
            C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % MOD;
    }
}


int main()
{
    init();
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int N,M;
        scanf("%d%d",&N,&M);
        int pick = min(N,M);
        long long ans = (C[N][pick] * C[M][pick]) % MOD;
        cout << ans << endl;
    }
}
