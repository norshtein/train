#include<bits/stdc++.h>

using namespace std;

const int MAXN = 2005;
const long long INF = 1e18;
long long dp[MAXN][MAXN];
int s[MAXN],f[MAXN],d[MAXN];
int N,ts,tf;

int getInterval(long long time,int start,int frequency)
{
    long long temp = (time - start) % frequency;
    if(temp == 0)
        return 0;
    else
        return frequency - temp;
}

long long getStartTime(long long time,int start,int frequency)
{
    if(time <= start)
        return start;
    long long temp = (time - start) % frequency;
    if(temp == 0)
        return time;
    else
        return time + frequency - temp;
}
void init()
{
    for(int i = 0;i <= N;i++)
        for(int j = 0;j <= N;j++)
            dp[i][j] = INF;
    dp[0][0] = 0;
}
int main()
{
    freopen("in.txt","r+",stdin);
    freopen("out.txt","w+",stdout);
    int T;
    scanf("%d",&T);
    for(int caseNum = 1;caseNum <= T;caseNum++)
    {
        scanf("%d%d%d",&N,&ts,&tf);
        init();
        for(int i = 1;i <= N - 1;i++)
            scanf("%d%d%d",&s[i],&f[i],&d[i]);

        for(int i = 1;i <= N - 1;i++)
        {
            for(int j = 0;j <= i;j++)
            {
                long long minCost = INF;
                if(j - 1 >= 0 && dp[i - 1][j - 1] != INF)
                    minCost = min(minCost,getStartTime(dp[i - 1][j - 1] + ts,s[i],f[i]) + d[i]);
                if(i - 1 >= j && dp[i - 1][j] != INF)
                    minCost = min(minCost,getStartTime(dp[i - 1][j],s[i],f[i]) + d[i]);
                dp[i][j] = minCost;
                //cout << i << ' ' << j << ' ' <<  dp[i][j] << endl;
            }
        }

        for(int j = N - 1;j >= 0;j--)
        {
            if(dp[N - 1][j] <= tf)
            {
                printf("Case #%d: %d\n",caseNum,j);
                break;
            }
            else if(j == 0)
            {
                printf("Case #%d: IMPOSSIBLE\n",caseNum);
                break;
            }
        }
    }
    return 0;
}
