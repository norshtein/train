#include <bits/stdc++.h>

using namespace std;

int n;
const int MAXN = 3005;
short dp[MAXN][MAXN];
vector<int> G[MAXN];
bool visited[MAXN];
const int INF = MAXN;

int dfs(int idx)
{
    visited[idx] = true;
    dp[idx][1] = 0;
    int totalSize = 1;
    int childNum = 0;
    for(int i = 0;i < G[idx].size();i++)
    {
        int child = G[idx][i];
        if(visited[child])
            continue;
        int childSize = dfs(child);
        childNum++;
        for(int sum = totalSize + childSize;sum >= 1;sum--)
        {
            int minValue = INF;
            for(int a = 1;a < sum;a++)
            {
                int b = sum - a;
                minValue = min(minValue,int(dp[idx][a] + dp[child][b]));
            }
            dp[idx][sum] = min(dp[idx][sum] + 1,minValue);
        }
        totalSize += childSize;
    }
    dp[idx][1] = childNum;
    dp[idx][totalSize] = 0;
    //for(int i = 0;i <= totalSize;i++)
        //printf("dp[%d][%d] = %d\n",idx,i,dp[idx][i]);
    return totalSize;
}


int main()
{
    memset(dp,0x3f,sizeof(dp));
    int n,m;
    scanf("%d",&n);
    int a,b;
    for(int i = 0;i < n - 1;i++)
    {
        scanf("%d%d",&a,&b);
        G[a].push_back(b);
        G[b].push_back(a);
    }
    dfs(1);
    scanf("%d",&m);
    for(int i = 0;i < m;i++)
    {
        scanf("%d",&a);
        int ans = dp[1][a];
        for(int idx = 2;idx <= n;idx++)
            ans = min(ans,dp[idx][a] + 1);
        printf("%d\n",ans);
    }
    return 0;
}
