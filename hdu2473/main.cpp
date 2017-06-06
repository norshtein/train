#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e5 + 5;
const int MAXM = 1e6 + 5;
int idx[MAXN];
int rnk[MAXM + MAXN];
int fa[MAXM + MAXN];
int N,M;
int cnt;

int getFa(int i)
{
    return fa[i] == i ? i : fa[i] = getFa(fa[i]);
}

int main()
{
    int caseNum = 0;
    while(scanf("%d%d",&N,&M) != EOF && N)
    {
        for(int i = 0;i < N;i++)
            idx[i] = i;
        for(int i = 0;i <= N + M;i++)
            fa[i] = i,rnk[i] = 1;
        cnt = N;
        int ans = N;

        char op;
        int a,b;
        for(int i = 0;i < M;i++)
        {
            scanf(" %c",&op);
            if(op == 'M')
            {
                scanf("%d%d",&a,&b);
                int ra = getFa(idx[a]);
                int rb = getFa(idx[b]);
                if(ra == rb)
                    continue;
                else
                {
                    rnk[ra] += rnk[rb];
                    fa[rb] = ra;
                    ans--;
                }
            }
            else
            {
                scanf("%d",&a);
                int ra = getFa(idx[a]);
                if(rnk[ra] == 1)
                    continue;
                rnk[ra]--;
                idx[a] = cnt++;
                ans++;
            }
        }

        printf("Case #%d: %d\n",++caseNum,ans);
    }

    return 0;
}
