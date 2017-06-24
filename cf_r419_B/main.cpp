#include <bits/stdc++.h>

using namespace std;

const int MAXN = 200000 + 5;
int pivot[MAXN];
int prefix[MAXN];

int main()
{
    int n,k,q;
    scanf("%d%d%d",&n,&k,&q);
    int l,r;
    for(int i = 0;i < n;i++)
    {
        scanf("%d%d",&l,&r);
        pivot[l]++;
        pivot[++r]--;
    }

    int now = 0;
    for(int i = 1;i <= 200000;i++)
    {
        now += pivot[i];
        prefix[i] = prefix[i - 1] + (now >= k);
    }


    for(int i = 0;i < q;i++)
    {
        scanf("%d%d",&l,&r);
        printf("%d\n",prefix[r] - prefix[l - 1]);
    }
    return 0;
}
