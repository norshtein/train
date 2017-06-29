#include<iostream>
#include<algorithm>
#include<vector>
#include<cstdio>

using namespace std;

const int MAXN = 1e4 + 5;
vector<pair<int,int> > G[MAXN];
int n,k;
int ans;
bool visited[MAXN];
int sze[MAXN];
int maxSize[MAXN];
int center;
int minVal;
vector<int> dis;

void init(int n)
{
    for(int i = 1;i <= n;i++)
    {
        G[i].clear();
        visited[i] = false;
        sze[i] = 0;
        maxSize[i] = 0;
    }
    ans = 0;
}

void dfs_size(int idx,int fa)
{
    sze[idx] = 1;
    maxSize[idx] = 0;
    for(int i = 0;i < G[idx].size();i++)
    {
        int v = G[idx][i].first;
        int w = G[idx][i].second;

        if(v == fa || visited[v])
            continue;
        dfs_size(v,idx);
        sze[idx] += sze[v];
        maxSize[idx] = max(maxSize[idx],sze[v]);
    }
}

void dfs_center(int idx,int fa,int root) //ÇóÖØÐÄ
{
    maxSize[idx] = max(maxSize[idx],sze[root] - sze[idx]);
    if(maxSize[idx] < minVal)
    {
        minVal = maxSize[idx];
        center = idx;
    }

    for(int i = 0;i < G[idx].size();i++)
    {
        int v = G[idx][i].first;
        int w = G[idx][i].second;

        if(v == fa || visited[v])
            continue;
        dfs_center(v,idx,root);
    }
}

void dfs_dis(int idx,int d,int fa)
{
    dis.push_back(d);
    for(int i = 0;i < G[idx].size();i++)
    {
        int v = G[idx][i].first;
        int w = G[idx][i].second;
        if(v == fa || visited[v])
            continue;
        dfs_dis(v,d + w,idx);
    }
}

int calc(int idx,int d)
{
    int res = 0;

    dis.clear();
    dfs_dis(idx,d,0);
    sort(dis.begin(),dis.end());
    int i = 0,j = dis.size() - 1;

    while(i < j)
    {
        while(i < j && dis[i] + dis[j] > k)
            j--;
        res += j - i;
        i++;
    }
    return res;
}

void dfs(int idx)
{
    dfs_size(idx,0);
    minVal = 9999999;
    dfs_center(idx,0,idx);
    ans += calc(center,0);

    visited[center] = true;
    int nowCenter = center;
    for(int i = 0;i < G[nowCenter].size();i++)
    {
        int v = G[nowCenter][i].first;
        int w = G[nowCenter][i].second;

        if(visited[v])
            continue;
        ans -= calc(v,w);
        dfs(v);
    }
}

int main()
{
    while(scanf("%d%d",&n,&k) != EOF && (n || k))
    {
        init(n);
        int u,v,w;
        for(int i = 0;i < n - 1;i++)
        {
            scanf("%d%d%d",&u,&v,&w);
            G[u].push_back(make_pair(v,w));
            G[v].push_back(make_pair(u,w));
        }

        dfs(1);
        printf("%d\n",ans);
    }
    return 0;
}
