#include<bits/stdc++.h>

using namespace std;

const int MAXN = 3e5 + 5;
int d[MAXN];
vector<pair<int,int> > e[MAXN];
int n,m;
vector<int> ans;
stack<pair<int,int> > s;
bool visited[MAXN];

int dfs(int u)
{
    visited[u] = true;
    int now = d[u] == 1;

    for(auto p:e[u])
    {
        int v = p.first;
        int idx = p.second;
        if(visited[v])
            continue;
        s.push(p);
        if(dfs(v) == 1)
        {
            now ^= 1;
            while(s.top() != p)
            {
                ans.push_back(s.top().second);
                s.pop();
            }
            ans.push_back(s.top().second);
            s.pop();
        }
        else
        {
            while(s.top() != p)
                s.pop();
            s.pop();
        }
    }
    return now;
}
int main()
{
    scanf("%d%d",&n,&m);
    int tmp;
    int occur = 0,even = true;
    for(int i = 1;i <= n;i++)
    {
        scanf("%d",&tmp);
        d[i] = tmp;
        if(tmp == -1)
            occur = i;
        else if(tmp == 1)
            even = !even;
    }

    int u,v;
    for(int i = 1;i <= m;i++)
    {
        scanf("%d%d",&u,&v);
        e[u].push_back(make_pair(v,i));
        e[v].push_back(make_pair(u,i));
    }

    if(!occur && !even)
    {
        puts("-1");
        return 0;
    }

    if(!even)
        d[occur] = 1;

    dfs(1);
    printf("%d\n",ans.size());
    for(auto idx:ans)
        printf("%d\n",idx);
    return 0;
}
