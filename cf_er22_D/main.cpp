#include <bits/stdc++.h>

using namespace std;

const int MAXN = 5005;
const int RANGE = 1e5 + 5;
int dp[MAXN][MAXN];
int nums[MAXN];
int n;
int mod[7];
int d[RANGE];

int main()
{
    scanf("%d",&n);
    for(int i = 0;i < n;i++)
        scanf("%d",nums + i);

    int ans = 2;
    for(int j = 0;j < n;j++)
    {
        memset(mod,0,sizeof(mod));
        memset(d,0,sizeof(d));
        for(int i = 0;i < j;i++)
        {
            mod[nums[i] % 7] = max(mod[nums[i] % 7],dp[i][j]);
            d[nums[i]] = max(d[nums[i]],dp[i][j]);
        }
        for(int i = j + 1;i < n;i++)
        {
            dp[i][j] = max(dp[i][j],dp[0][j] + 1);
            dp[i][j] = max(dp[i][j],mod[nums[i] % 7] + 1);
            dp[i][j] = max(dp[i][j],d[nums[i] - 1] + 1);
            dp[i][j] = max(dp[i][j],d[nums[i] + 1] + 1);

            ans = max(ans,dp[i][j]);
            dp[j][i] = dp[i][j];
            mod[nums[i] % 7] = max(mod[nums[i] % 7],dp[i][j]);
            d[nums[i]] = max(d[nums[i]],dp[i][j]);
            cout << i << ' ' << j << ' ' << dp[i][j] << endl;
        }
    }
    cout << ans << endl;
    return 0;
}
