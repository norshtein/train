#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9 + 7;
long long perm[20];
int n,k;
int nums[20];
int gcd[20][20];

int ggcd(int a,int b)
{
    return b == 0 ? a : ggcd(b,a % b);
}

int getMin(int a,int b)
{
    vector<int> can;
    int len = n - (b -a + 1);
    if(len == 0)
        return 0;
    int dp[20][20] = {{0}};
    for(int i = 0;i < len;i++)
        dp[i][i] = 1;
    for(int l = 2;l <= len;l++)
    {
        for(int i = 0;i + l - 1< len;i++)
        {
            int j = i + l - 1;
            int iHash = i >= a ? b + 1 + i - a : i;
            int jHash = j >= a ? b + 1 + j - a : j;
            if((iHash < a && jHash < a || iHash > b && jHash > b) && gcd[iHash][jHash] >= k)
            {
                dp[i][j] = 1;
                continue;
            }
            else if(iHash < a && jHash > b && ggcd(gcd[iHash][a - 1],gcd[b + 1][jHash]) >= k)
            {
                dp[i][j] = 1;
                continue;
            }

            int ans = 999;
            for(int k = i;k + 1 <= j;k++)
                ans = min(ans,dp[i][k] + dp[k + 1][j]);
            dp[i][j] = ans;
        }
    }
    return dp[0][len - 1];
}
int main()
{
    perm[0] = 1;
    for(int i = 1;i < 20;i++)
        perm[i] = (perm[i - 1] * i) % MOD;

    scanf("%d%d",&n,&k);
    for(int i = 0;i < n;i++)
        cin >> nums[i];

    for(int i = 0;i < n;i++)
        gcd[i][i] = nums[i];
    for(int i = 0;i < n;i++)
    {
        for(int j = i + 1;j < n;j++)
            gcd[i][j] = ggcd(gcd[i][j - 1],nums[j]);
    }

    long long answer = 0;
    for(int i = 0;i < n;i++)
    {
        for(int j = i;j < n;j++)
        {
            int len = j - i + 1;
            int low = getMin(i,j) + 1;
            int high = n - len + 1;
            cout << i << ' ' << j << ' ' << low << ' ' << high << endl;
            for(int k = low;k <= high;k++)
                //answer++;
                answer = (answer + perm[k]) % MOD;
        }
    }
    cout << answer << endl;
    return 0;
}
