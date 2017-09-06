#include<bits/stdc++.h>

using namespace std;

int T;
long long biao[40005];

int main()
{
    for(int i = 1;i < 40000;i++)
        biao[i] = 2LL * i * i;

    scanf("%d",&T);
    while(T--)
    {
        int n;
        scanf("%d",&n);

        int idx = upper_bound(biao,biao + 40000,n) - biao;
        if(n <= biao[idx - 1])
            printf("%d\n",4 * (idx - 1));
        else if(n <= biao[idx - 1] + (2 * idx - 3) / 2.0)
            printf("%d\n",4 * (idx - 1) + 1);
        else if(n <= biao[idx] - 2 * idx)
            printf("%d\n",4 * (idx - 1) + 2);
        else if(n <= biao[idx] - (2 * idx - (2 * idx - 1) / 2.0))
            printf("%d\n",4 * (idx - 1) + 3);
        else
            printf("%d\n",4 * idx);

    }
    return 0;
}
