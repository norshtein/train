#include<bits/stdc++.h>

using namespace std;

int N,M;

const int MAXN = 1e5 + 5;
vector<pair<int,int> > e[MAXN];
vector<int> company[MAXN];
int dp[MAXN][20];
int dis[MAXN][20];
int depth[MAXN];

void addedge(int u,int v,int w)
{
    e[u].push_back(make_pair(v,w));
    e[v].push_back(make_pair(u,w));
}

void dfs(int idx,int fa)
{
    depth[idx] = depth[fa] + 1;
    for(auto p:e[idx])
    {
        int v = p.first;
        int c = p.second;
        if(v == fa)
            continue;
        dp[v][1] = idx;
        dis[v][1] = c;
        dfs(v,idx);
    }
}
void init()
{
    int num = 0;
    while((1 << num) <= N)
        num++;
    num--;
    for(int i = 0;i <= N;i++)
    {
        for(int j = 0;j <= num;j++)
            dp[i][j] = dis[i][j] = 0;
        depth[i] = 0;
    }

    for(int i = 1;i <= N;i++)
        dp[i][0] = i,dis[i][0] = 0;
    dfs(1,0);
    for(int j = 2;j <= num;j++)
    {
        for(int i = 1;i <= N;i++)
            dp[i][j] = dp[dp[i][j - 1]][j - 1],dis[i][j] = dis[i][j - 1] + dis[dp[i][j - 1]][j - 1];
    }
}

int lca(int a,int b)
{
    if(depth[a] < depth[b])
        swap(a,b);
    int ans = 0;
    while(depth[a] > depth[b])
    {

    }
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&N,&M);
        for(int i = 0;i < N;i++)
            e[i].clear();
        for(int i = 0;i < M;i++)
            company[i].clear();

        int u,v,w;
        for(int i = 0;i < N - 1;i++)
        {
            scanf("%d%d%d",&u,&v,&w);
            addedge(u,v,w);
        }
        for(int i = 1;i <= M;i++)
        {
            int cnt,tmp;
            scanf("%d",&cnt);
            for(int j = 0;j < cnt;j++)
                scanf("%d",&tmp),company[i].push_back(j);
        }

        int Q;
        scanf("%d",&Q);
        for(int i = 0;i < Q;i++)
        {
            int ans = INT_MAX;
            scanf("%d%d",&u,&v);
            for(int a = 0;a < company[u].size();a++)
            {
                for(int b = 0;b < company[v].size();b++)
                    ans = min(ans,lca(a,b));
            }
            printf("%d\n",ans);
        }
    }
    return 0;
}
