#include<bits/stdc++.h>

using namespace std;

int n,k;
const int MAXN = 1e6 + 5;
int f[MAXN][21];
const int MOD = 1e9 + 7;

inline int getDigit(int num)
{
    int ans = 0;
    while(num)
    {
        if(num & 1)
            ans++;
        num >>= 1;
    }
    return ans;
}

inline int test(int num,int digit)
{
    return (num & (1 << digit)) != 0;
}

inline void getF()
{
    for(int i = 1000000;i >= 0;i--)
    {
        for(int k = 19;k >= 0;k--)
        {
            if(test(i,k))
                f[i][k] = f[i][k + 1];
            else
                f[i][k] = f[i][k + 1] + (i + (1 << k) <= 1000000 ? f[i + (1 << k)][k + 1] : 0);
        }
    }
}

int qpow(int a,int t)
{
    long long ans = 1;
    long long temp = a;
    while(t)
    {
        if(t & 1)
            ans  = ans * temp % MOD;
        temp = temp * temp % MOD;
        t >>= 1;
    }
    return ans;
}

int main()
{
    scanf("%d",&n);
    for(int i = 0;i < n;i++)
    {
        scanf("%d",&k);
        f[k][20]++;
    }

    getF();

    long long ans = 0;
    for(int i = 0;i <= 1000000;i++)
    {
        int d = getDigit(i);
        ans =  (ans + (qpow(2,f[i][0]) - 1) * (d % 2 ? -1 : 1)) % MOD;
    }
    ans = (ans + MOD) % MOD;
    printf("%I64d\n",ans);
    return 0;
}
