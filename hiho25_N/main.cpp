#include<bits/stdc++.h>

using namespace std;

const int MAXN = 1e5 + 5;

int sze[MAXN];
int lft[MAXN];
vector<int> e[MAXN];
int ans;

void dfs(int u,int fa)
{
    sze[u] = lft[u] = 1;
    for(auto v:e[u])
    {
        if(v == fa)
            continue;
        dfs(v,u);
        sze[u] += sze[u];

        if(lft[v] % 2 == 0)
            ans++;
        else
            lft[u] += lft[v];
    }
}
int main()
{
    int N;
    scanf("%d",&N);
    int u,v;
    for(int i = 0;i < N - 1;i++)
    {
        scanf("%d%d",&u,&v);
        e[u].push_back(v);
        e[v].push_back(u);
    }

    dfs(1,0);
    printf("%d\n",ans);
    return 0;
}
