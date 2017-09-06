#include<bits/stdc++.h>

using namespace std;

const int MOD = 1e9 + 7;
long long dp[2][305][305];

int main()
{
    int n,k;
    scanf("%d%d",&n,&k);

    int cur = 0,nxt = 1;
    dp[cur][0][0] = 1;
    for(int i = 0;i < 2 * n;i++)
    {
        for(int j = 0;j <= i && j <= n;j++)
        {
            for(int k = 0;k <= j;k++)
            {
                //cout << i << ' ' << j << ' ' << k << ' ' << dp[cur][j][k] << endl;
                dp[nxt][j + 1][k + 1] = (dp[nxt][j + 1][k + 1] + dp[cur][j][k]) % MOD;
                dp[nxt][j][max(0,k - 1)] = (dp[nxt][j][max(0,k - 1)] + dp[cur][j][k]) % MOD;
            }
        }
        swap(cur,nxt);
        memset(dp[nxt],0,sizeof(dp[nxt]));
    }
    dp[cur][n][k] %= MOD;
    cout << dp[cur][n][k] << endl;
    return 0;
}
