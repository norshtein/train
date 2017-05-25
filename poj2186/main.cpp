#include <vector>
#include<iostream>
#include<stack>
#include<algorithm>
#include<cstdio>

using namespace std;

const int MAXN = 1e4 + 5;
vector<int> G[MAXN];
int dfn[MAXN];
int low[MAXN];
stack<int> s;
bool instack[MAXN];
int N,M;
int scc;
int belong[MAXN];
int cnt;
int degree[MAXN];
int num[MAXN];

void process()
{
    int idx = s.top();
    s.pop();
    belong[idx] = scc;
    num[scc]++;
    instack[idx] = false;
}
void tarjan(int idx)
{
    dfn[idx] = ++cnt;
    low[idx] = dfn[idx];
    s.push(idx);
    instack[idx] = true;

    for(int i = 0;i < G[idx].size();i++)
    {
        if(!dfn[G[idx][i]])
        {
            tarjan(G[idx][i]);
            low[idx] = min(low[idx],low[G[idx][i]]);
        }
        else if(instack[G[idx][i]])
            low[idx] = min(low[idx],dfn[G[idx][i]]);
    }

    if(low[idx] == dfn[idx])
    {
        scc++;
        while(s.top() != idx)
            process();
        process();
    }
}
int main()
{
    scanf("%d%d",&N,&M);
    int a,b;
    for(int i = 0;i < M;i++)
    {
        scanf("%d%d",&a,&b);
        G[a].push_back(b);
    }

    for(int i = 1;i <= N;i++)
        if(!dfn[i])
            tarjan(i);

    for(int i = 1;i <= N;i++)
    {
        for(int j = 0;j < G[i].size();j++)
        {
            int v = G[i][j];
            if(belong[i] == belong[v])
                continue;
            degree[belong[i]]++;
        }
    }

    int zeroNum = 0,candidate = -1;
    for(int i = 1;i <= scc;i++)
    {
        if(!degree[i])
            zeroNum++,candidate = i;
    }
    if(zeroNum != 1)
        cout << 0 << endl;
    else
        cout << num[candidate] << endl;

    return 0;
}
