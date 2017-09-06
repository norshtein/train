#include<bits/stdc++.h>

using namespace std;

const int MAXN = 1e6 + 5;

int prime[MAXN];

void init()
{
    for(int i = 2;i < MAXN;i++)
        prime[i] = 1;
    for(int i = 2;i < MAXN;i++)
    {
        if(prime[i])
            prime[++prime[0]] = i;
        for(int j = 1;j <= prime[0] && (long long)i * prime[j] < MAXN;j++)
        {
            prime[i * prime[j]] = 0;
            if(i % prime[j] == 0)
                break;
        }
    }
}

const int MAXNUM = 5e5 + 5;
int nums[MAXNUM];
//int occurTime[MAXNUM];
int n,x,y;

long long minCost = LLONG_MAX;

void calcualteCost(int p)
{
    long long cost = 0;
    for(int i = 0;i < n;i++)
    {
        long long nowCost = min((long long)x,(long long)y * ((p - nums[i] % p) % p));
        cost += nowCost;
        if(cost >= minCost)
            return;
    }
    minCost = cost;
}
int main()
{
    init();
    //printf("%d\n",prime[0]);
    scanf("%d%d%d",&n,&x,&y);

    //int special = -1;
    for(int i = 0;i < n;i++)
    {
        scanf("%d",&nums[i]);
    }

    for(int p = 1;p <= prime[0];p++)
        calcualteCost(prime[p]);
    printf("%lld\n",minCost);
    return 0;
}
