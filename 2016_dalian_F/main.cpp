#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

const int MAXN = 45000;
LL inv[MAXN];
LL fac[MAXN];
LL f[MAXN];
const int MOD = 1e9 + 7;

void init()
{
    fac[0] = fac[1] = inv[0] = inv[1] = f[0] = f[1] = 1;
    for(int i = 2;i < MAXN;i++)
    {
        fac[i] = fac[i - 1] * i % MOD;
        f[i] = f[MOD % i] * (MOD - MOD / i) % MOD;
        inv[i] = inv[i - 1] * f[i] % MOD;
    }
}

int main()
{
    init();
    int T,x = 0;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&x);
        //x++;
        if(x <= 4)
        {
            printf("%d\n",x);
            continue;
        }

        double delta = 8LL * x + 9;
        int n = floor((-1 + sqrt(delta)) / 2 + 1e-9);
        int cnt = (n + 2) * (n - 1) / 2;
        int remain = x - cnt;

        assert(remain >= 0);

        if(remain > n - 1)
        {
            LL ans = fac[n];
            ans = ans * inv[2] % MOD;
            ans = ans * (n + 2) % MOD;
            printf("%d\n",(int)ans);
            continue;
        }
        LL ans = fac[n - remain];
        ans = ans * fac[n + 1] % MOD;
        ans = ans * inv[n + 1 - remain] % MOD;
        printf("%d\n",(int)ans);
    }
    return 0;
}
