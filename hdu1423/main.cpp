#include<bits/stdc++.h>

using namespace std;

const int MAXN = 505;
int a[MAXN],b[MAXN];
int dp[MAXN][MAXN];
pair<int,int> pre[MAXN][MAXN];

int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        memset(dp,0,sizeof(dp));
        memset(pre,0,sizeof(pre));
        int n,m;
        scanf("%d",&n);
        for(int i = 1;i <= n;i++)
            scanf("%d",&a[i]);
        scanf("%d",&m);
        for(int i = 1;i <= m;i++)
            scanf("%d",&b[i]);

        for(int i = 1;i <= n;i++)
        {
            int maxVal = 0;
            pair<int,int> maxStatus;
            for(int j = 1;j <= m;j++)
            {
                if(a[i] > b[j] && dp[i - 1][j] > maxVal)
                    maxVal = dp[i - 1][j],maxStatus = make_pair(i - 1,j);

                if(a[i] != b[j])
                    dp[i][j] = dp[i - 1][j],pre[i][j] = make_pair(i - 1,j);
                else
                    dp[i][j] = maxVal + 1,pre[i][j] = maxStatus;
            }
        }

        int ans = 0,choice = 0;
        for(int i = 1;i <= m;i++)
        {
            if(dp[n][i] > ans)
                ans = dp[n][i],choice = i;
        }

        printf("%d\n",ans);
        stack<int> trace;
        pair<int,int> now = make_pair(n,choice);
        while(now != make_pair(0,0))
        {
            if(a[now.first] == b[now.second])
                trace.push(a[now.first]);
            now = pre[now.first][now.second];
        }
        while(!trace.empty())
        {
            printf("%d%c",trace.top()," \n"[trace.size() == 1]);
            trace.pop();
        }
    }
    return 0;
}
