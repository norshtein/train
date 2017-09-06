#include <bits/stdc++.h>

using namespace std;

long long base[65];
long long nums[10005];
int cnt;
int N,Q;
map<int,int> dtod;
const int MAXD = 62;
bool used[10005];

long long query(long long num)
{
    if(cnt < N)
        num--;

    if(num > (1LL << cnt) - 1)
        return -1;
    if(num == 0)
        return 0;

    long long answer = 0;
    for(int i = 0;i <= 62;i++)
    {
        if(num >> i & 1)
            answer ^= base[dtod[i]];
    }
    return answer;
}
int main()
{
    int T;
    scanf("%d",&T);
    for(int caseNum = 1;caseNum <= T;caseNum++)
    {
        memset(base,0,sizeof(base));
        memset(used,0,sizeof(used));
        cnt = 0;
        dtod.clear();

        scanf("%d",&N);
        for(int i = 0;i < N;i++)
            scanf("%I64d",&nums[i]);

        for(int i = MAXD;i >= 0;i--)
        {
            int j = 0;
            while(j < N && (used[j] || !(nums[j] >> i & 1)))
                j++;
            if(j == N)
                continue;
            base[i] = nums[j];
            used[j] = true;

            for(int k = MAXD;k > i;k--)
            if(base[k] && (base[k] >> i & 1))
                base[k] ^= base[i];

            for(int k = 0;k < N;k++)
            {
                if(k == j)
                    continue;
                if(nums[k] >> i & 1)
                    nums[k] ^= base[i];
            }
        }

        for(int i = 0;i <= 62;i++)
            if(base[i])
                dtod[cnt++] = i;

        printf("Case #%d:\n",caseNum);
        scanf("%d",&Q);
        long long temp;
        for(int i = 0;i < Q;i++)
        {
            scanf("%I64d",&temp);
            printf("%I64d\n",query(temp));
        }
    }
    return 0;
}
