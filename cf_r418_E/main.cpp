#include <bits/stdc++.h>

using namespace std;

const int MAXN = 51;
int dp[2][MAXN][MAXN][MAXN][MAXN];
const int MOD = 1e9 + 7;
int d[MAXN];
int n;

int add(int& a,long long b)
{
    b %= MOD;
    return (a = (a + b) % MOD);
}

int main()
{
    cin >> n;
    for(int i = 0;i < n;i++)
        cin >> d[i];

    int nxt = 1,cur = 0;
    dp[cur][d[0] == 2][d[0] == 3][d[1] == 2][d[1] == 3] = 1;

    int now;
    for(int i = 2;i < n;i++)
    {
        memset(dp[nxt],0,sizeof(dp[nxt]));
        for(int p1 = 0;p1 <= n;p1++)
        {
            for(int p2 = 0;p1 + p2 <= n;p2++)
            {
                for(int q1 = 0;p1 + p2 + q1 <= n;q1++)
                {
                    for(int q2 = 0;p1 + p2 + q1 + q2 <= n;q2++)
                    {
                        if(!(now = dp[cur][p1][p2][q1][q2]))
                            continue;

                        if(!p1 && !p2)
                        {
                            add(dp[cur][q1][q2][0][0],now);
                            continue;
                        }

                        if(p1)
                        {
                            add(dp[nxt][p1 - 1][p2][q1 + (d[i] == 2)][q2 + (d[i] == 3)],1LL * p1 * now);
                            if(d[i] == 2)
                            {
                                q1 != 0 ? add(dp[nxt][p1 - 1][p2][q1 - 1][q2],1LL * q1 * p1 * now) : 0;
                                q2 != 0 ? add(dp[nxt][p1 - 1][p2][q1 + 1][q2 - 1],1LL * q2 * p1 * now) : 0;
                            }
                            else
                            {
                                q1 >= 1 ? add(dp[nxt][p1 - 1][p2][q1][q2],1LL * q1 * p1 * now) : 0;
                                q2 >= 1 ? add(dp[nxt][p1 - 1][p2][q1 + 2][q2 - 1],1LL * q2 * p1 * now) : 0;
                                q1 >= 2 ? add(dp[nxt][p1 - 1][p2][q1 - 2][q2],1LL * q1 * (q1 - 1) / 2 * p1 * now) : 0;
                                q2 >= 2 ? add(dp[nxt][p1 - 1][p2][q1 + 2][q2 - 2],1LL * q2 * (q2 - 1) / 2 * p1 * now) : 0;
                                q1 >= 1 && q2 >= 1 ? add(dp[nxt][p1 - 1][p2][q1][q2 - 1],1LL * q1 * q2 * p1 * now) : 0;
                            }
                        }
                        if(p2)
                        {
                            add(dp[nxt][p1 + 1][p2 - 1][q1 + (d[i] == 2)][q2 + (d[i] == 3)],1LL * p2 * now);
                            if(d[i] == 2)
                            {
                                q1 != 0 ? add(dp[nxt][p1 + 1][p2 - 1][q1 - 1][q2],1LL * q1 * p2 * now) : 0;
                                q2 != 0 ? add(dp[nxt][p1 + 1][p2 - 1][q1 + 1][q2 - 1],1LL * q2 * p2 * now) : 0;
                            }
                            else
                            {
                                q1 >= 1 ? add(dp[nxt][p1 + 1][p2 - 1][q1][q2],1LL * q1 * p2 * now) : 0;
                                q2 >= 1 ? add(dp[nxt][p1 + 1][p2 - 1][q1 + 2][q2 - 1],1LL * q2 * p2 * now) : 0;
                                q1 >= 2 ? add(dp[nxt][p1 + 1][p2 - 1][q1 - 2][q2],1LL * q1 * (q1 - 1) / 2 * p2 * now) : 0;
                                q2 >= 2 ? add(dp[nxt][p1 + 1][p2 - 1][q1 + 2][q2 - 2],1LL * q2 * (q2 - 1) / 2 * p2 * now) : 0;
                                q1 >= 1 && q2 >= 1 ? add(dp[nxt][p1 + 1][p2 - 1][q1][q2 - 1],1LL * q1 * q2 * p2 * now) : 0;
                            }
                        }
                    }
                }
            }
        }
        swap(cur,nxt);
    }
    printf("%d\n",dp[cur][0][0][0][0]);
    return 0;
}
