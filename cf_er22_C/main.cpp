#include <iostream>
#include<bits/stdc++.h>

using namespace std;

const int MAXN = 2e5 + 5;
vector<int> G[MAXN];
bool visited[MAXN];
int fa[MAXN];
int depth[MAXN];
int maxDepth[MAXN];
int n,x;

void dfs(int now,int d)
{
    visited[now] = true;
    maxDepth[now] = depth[now] = d;

    for(auto v:G[now])
    {
        if(visited[v])
            continue;
        fa[v] = now;
        dfs(v,d + 1);
        maxDepth[now] = max(maxDepth[now],maxDepth[v]);
    }
}

int main()
{
    scanf("%d%d",&n,&x);
    int u,v;
    for(int i = 0;i < n - 1;i++)
    {
        scanf("%d%d",&u,&v);
        G[u].push_back(v);
        G[v].push_back(u);
    }

    dfs(1,0);
    int answer = 2;
    int now = x,step = 0;
    while(now != 1)
    {
        if(step >= depth[now])
            break;
        answer = max(answer,maxDepth[now] * 2);
        now = fa[now];
        step++;
    }
    cout << answer <<endl;
    return 0;
}
