#include<bits/stdc++.h>

using namespace std;

const int MAXD = 62;
const int MAXN = 10005;
long long base[65];
long long nums[MAXN];
int N;

int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        memset(base,0,sizeof(base));

        scanf("%d",&N);
        for(int i = 0;i < N;i++)
            scanf("%I64d",&nums[i]);

        for(int i = MAXD;i >= 0;i--)
        {
            int j = 0;
            while(j < N && !(nums[j] >> i & 1))
                j++;
            if(j == N)
                continue;
            base[i] = nums[j];

            for(int k = MAXD;k > i;k--)
            if(base[k] && base[k] >> i & 1)
                base[k] ^= base[i];

            for(int k = 0;k < N;k++)
            {
                if(k == j)
                    continue;
                if(nums[k] >> i & 1)
                    nums[k] ^= base[i];
            }
        }


    }

    return 0;
}
