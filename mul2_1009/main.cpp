#include<bits/stdc++.h>

using namespace std;

const int MAXN = 1e5 + 5;
int bucket[MAXN];
int miu[MAXN];
int prime[MAXN];
const int MOD = 1e9 + 7;
int N;

void mobius()
{
    for(int i = 2;i < MAXN;i++)
        prime[i] = true;
    for(int i = 2;i < MAXN;i++)
    {
        if(prime[i])
        {
            prime[++prime[0]] = i;
            miu[i] = -1;
        }
        for(int j = 1;j <= prime[0] && (long long)i * prime[j] < MAXN;j++)
        {
            prime[i * prime[j]] = 0;
            if(i % prime[j] == 0)
            {
                miu[i * prime[j]] = 0;
                break;
            }
            miu[i * prime[j]] = -miu[i];
        }
    }
}

int qpow(int a,int b)
{
    long long ans = 1;
    long long now = a;
    while(b)
    {
        if(b & 1)
            ans = ans * now % MOD;
        b >>= 1;
        now = now * now % MOD;
    }
    //cout << "qpow" << a << ' ' << b << ' ' << ans << endl;
    return ans;
}

int main()
{
    mobius();
    int T;
    int caseNum = 0;
    scanf("%d",&T);
    while(T--)
    {
        memset(bucket,0,sizeof(bucket));
        scanf("%d",&N);
        int tmp,mi = MAXN,mx = 0;
        for(int i = 0;i < N;i++)
        {
            scanf("%d",&tmp);
            bucket[tmp]++;
            mi = min(mi,tmp);
            mx = max(mx,tmp);
        }
        for(int i = 1;i < MAXN;i++)
            bucket[i] += bucket[i - 1];

        long long ans = 0;
        for(int i = 2;i <= mi;i++)
        {
            long long tmp = 1;
            for(int j = 1;j * i <= mx;j++)
            {
                tmp = tmp * qpow(j,bucket[min((j + 1) * i - 1,MAXN - 1)] - bucket[j * i - 1]) % MOD;
                //printf("%d %d %d\n",i,j,bucket[min((j + 1) * i - 1,MAXN - 1)] - bucket[j * i - 1]);
            }
            //cout << tmp << endl;
            ans = ((ans - tmp * miu[i]) % MOD + MOD) % MOD;
        }
        printf("Case #%d: %d\n",++caseNum,(int)ans);
    }
    return 0;
}
