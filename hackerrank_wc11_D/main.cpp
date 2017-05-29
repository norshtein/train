#include <bits/stdc++.h>

using namespace std;

struct Edge{
    int v,next = -1;
};
const int MAXN = 5e4 + 5;
const int MAXM = MAXN + 1e5;
const int MAXQ = 1e5 + 5;

Edge edges[MAXM];
int edgeNum;
int head[MAXN];
int belong[MAXN];
int s[MAXN];
int top = 0;
int low[MAXN];
int dfn[MAXN];
bool instack[MAXN];
int seq;
int scc;
int n,m,q;
pair<int,int> query[MAXQ];
int qCnt;
vector<int> G[MAXN];
bitset<MAXN> reachable[MAXN];

void tarjan(int idx)
{
    dfn[idx] = low[idx] = ++seq;
    s[top++] = idx;
    instack[idx] = true;

    for(int i = head[idx];~i;i = edges[i].next)
    {
        int v= edges[i].v;
        if(dfn[v] == -1)
        {
            tarjan(v);
            low[idx] = min(low[idx],low[v]);
        }
        else if(instack[v])
            low[idx] = min(low[idx],dfn[v]);
    }

    if(dfn[idx] == low[idx])
    {
        scc++;
        do{
            int v = s[--top];
            belong[v] = scc;
            instack[v] = false;
        }while(s[top] != idx);
    }
}

void addedge(int u,int v)
{
    edges[edgeNum].v = v;
    edges[edgeNum].next = head[u];
    head[u] = edgeNum++;
}

void dfs(int idx)
{
    dfn[idx] = 1;
    for(auto i:G[idx])
    {
        if(dfn[i])
            continue;
        dfs(i);
    }
    s[top++] = idx;
}

int main()
{
    memset(dfn,-1,sizeof(dfn));
    memset(head,-1,sizeof(head));
    scanf("%d%d",&n,&m);
    int a,b;
    for(int i = 0;i < m;i++)
    {
        scanf("%d%d",&a,&b);
        addedge(a,b);
    }
    scanf("%d",&q);
    int t;
    for(int i = 0;i < q;i++)
    {
        scanf("%d%d%d",&t,&a,&b);
        if(t & 1)
        {
            if(b & 1)
                addedge(++n,a);
            else
                addedge(a,++n);
        }
        else
            query[qCnt++] = make_pair(a,b);
    }

    for(int i = 1;i <= n;i++)
        if(dfn[i] == -1)
            tarjan(i);

    for(int i = 1;i <= n;i++)
    {
        for(int h = head[i]; ~h;h = edges[h].next)
        {
            int v = edges[h].v;
            if(belong[i] == belong[v])
                continue;
            G[belong[i]].push_back(belong[v]);
        }
        sort(G[i].begin(),G[i].end());
        G[i].resize(unique(G[i].begin(),G[i].end()) - G[i].begin());
    }

    memset(dfn,0,sizeof(int) * (n + 2));
    top = 0;
    for(int i = 1;i <= n;i++)
        if(dfn[i] == 0)
            dfs(i);

    for(int i = 0;i < top;i++)
    {
        int v = s[i];
        reachable[v].set(v);
        for(int j = 0;j < G[v].size();j++)
            reachable[v] |= reachable[G[v][j]];
    }
    for(int i = 0;i < qCnt;i++)
    {
        int u = query[i].first;
        int v = query[i].second;
        if(reachable[belong[u]].test(belong[v]))
            puts("Yes");
        else
            puts("No");
    }
    return 0;
}
