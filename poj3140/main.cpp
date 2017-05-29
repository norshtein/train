#include <iostream>
#include<algorithm>
#include<cstring>
#include<vector>
#include<cstdio>

using namespace std;

const int MAXN = 1e5 + 5;
const long long INF = (unsigned long long)-1LL >> 1;
vector<int> G[MAXN];
bool visited[MAXN];
int weight[MAXN];
long long sum;
int N,M;
long long answer;

long long dfs(int now)
{
    visited[now] = true;

    long long w = weight[now];
    for(int i = 0;i < G[now].size();i++)
    {
        int v = G[now][i];
        if(visited[v])
            continue;
        w += dfs(v);
    }
    answer = min(answer,max(sum - w,w) - min(sum - w,w));
    return w;
}
int main()
{
    int caseNum = 0;
    while(scanf("%d%d",&N,&M) && N)
    {
        answer = INF;
        sum = 0;
        for(int i = 1;i <= N;i++)
            G[i].clear();
        fill(visited,visited + N + 2,0);

        for(int i = 1;i <= N;i++)
        {
            scanf("%d",weight + i);
            sum += weight[i];
        }

        int a,b;
        for(int i = 0;i < M;i++)
        {
            scanf("%d%d",&a,&b);
            G[a].push_back(b);
            G[b].push_back(a);
        }

        dfs(1);
        printf("Case %d: %lld\n",++caseNum,answer);
    }
    return 0;
}
