#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1505;
int dp[MAXN][MAXN];
int dp1[26][MAXN];
char s[MAXN];
int n,q;

void getDp(int desired)
{
    char d = desired + 'a';
    for(int i = 0;i <= n;i++)
        for(int j = 0;j <= n;j++)
            dp[i][j] = 0;

    for(int i = 1;i <= n;i++)
        dp[i][0] = (s[i] == d ? dp[i - 1][0] + 1 : 0);
    for(int i = 1;i <= n;i++)
    {
        for(int j = 1;j <= i;j++)
        {
            if(s[i] == d)
            {
                dp[i][j] = (i - 1 >= j ? dp[i - 1][j] : i - 1) + 1;
            }
            else
                dp[i][j] = dp[i - 1][j - 1] + 1;
        }
    }

    for(int i = 1;i <= n;i++)
    {
        int maxVal = 0;
        for(int j = 1;j <= n;j++)
            maxVal = max(maxVal,dp[j][i]);
        dp1[desired][i] = maxVal;
    }
}
int main()
{
    scanf("%d",&n);
    scanf("%s",s + 1);
    for(int i = 0;i < 26;i++)
        getDp(i);
    scanf("%d",&q);
    int m;
    char c;
    for(int i = 0;i < q;i++)
    {
        scanf("%d %c",&m,&c);
        printf("%d\n",dp1[c - 'a'][m]);
    }
    return 0;
}
