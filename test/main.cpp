#include<bits/stdc++.h>

using namespace std;

const int MAXN = 100005;
const int MAXM = 2005;
long long dp[11][MAXM];
int n,m;
int a[MAXN],b[MAXN];
int k[MAXM],p[MAXM];
long long INF;

int main()
{
    memset(&INF,0x3f,sizeof(INF));
    while(scanf("%d%d",&n,&m) != EOF)
    {
        for(int i = 0;i < n;i++)
            scanf("%d%d",&a[i],&b[i]);
        for(int i = 0;i < m;i++)
            scanf("%d%d",&k[i],&p[i]);

        memset(dp,0x3f,sizeof(dp));
        for(int defence = 0;defence <= 10;defence++)
        {
            dp[defence][0] = 0;
            for(int i = 0;i < m;i++)
            {
                if(p[i] <= defence)
                    continue;

                for(int j = 0;j < MAXM;j++)
                    dp[defence][j] = j - (p[i] - defence) >= 0 ? min(dp[defence][j],dp[defence][j - (p[i] - defence)] + k[i]) :dp[defence][j];
            }
            for(int j = MAXM - 2;j >= 0;j--)
                dp[defence][j] = min(dp[defence][j],dp[defence][j + 1]);
        }

        bool haveAnswer = true;
        long long ans = 0;
        for(int i = 0;i < n;i++)
        {
            if(dp[b[i]][a[i]] == INF)
            {
                haveAnswer = false;
                break;
            }
            else
                ans += dp[b[i]][a[i]];
        }
        cout << (haveAnswer ? ans : -1) << endl;
    }
    return 0;
}
