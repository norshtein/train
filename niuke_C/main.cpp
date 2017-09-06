#include<bits/stdc++.h>

using namespace std;

const int MAXN = 1e6 + 5;
const int MOD = 1e9 + 7;
const double eps = 1e-9;
int prime[MAXN];

int main()
{
    int n;
    cin >> n;
    if(n == 1)
    {
        cout << 1 << endl;
        return 0;
    }

    prime[0] = 0;
    for(int i = 2;i <= n;i++)
        prime[i] = 1;

    for(int i = 2;i <= n;i++)
    {
        if(prime[i])
            prime[++prime[0]] = i;
        for(int j = 1;j <= prime[0] && (long long)i * prime[j] <= n;j++)
        {
            prime[i * prime[j]] = 0;
            if(i % prime[j] == 0)
                break;
        }
    }

    long long ans = 1;
    for(int i = 1;i <= prime[0];i++)
    {
        int now = prime[i];
        int cnt = log(n) / log(now) + eps;
        ans = ans * (cnt + 1) % MOD;
    }
    cout << ans << endl;
    return 0;
}
