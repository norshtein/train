#include <cstdio>
#include <cstring>
#include <queue>
#include <stack>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#define MAXN 200+10
#define MAXM 80000+100
#define INF 0x3f3f3f3f
using namespace std;
struct Edge
{
    int from, to, cap, flow, cost, next;
};
Edge edge[MAXM];
int head[MAXN], edgenum;
int pre[MAXN];//记录增广路径上 到达点i的边的编号
int dist[MAXN];
bool vis[MAXN];
int N, M;//点数 边数
int source, sink;//超级源点 超级汇点
void init()
{
    edgenum = 0;
    memset(head, -1, sizeof(head));
}
void addEdge(int u, int v, int w, int c)
{
    Edge E1 = {u, v, w, 0, c, head[u]};
    edge[edgenum] = E1;
    head[u] = edgenum++;
    Edge E2 = {v, u, 0, 0, -c, head[v]};
    edge[edgenum] = E2;
    head[v] = edgenum++;
}
bool SPFA(int s, int t)//寻找花销最少的路径
{
    //跑一遍SPFA 找s——t的最少花销路径 且该路径上每一条边不能满流
    //若存在 说明可以继续增广，反之不能
    queue<int> Q;
    memset(dist, INF, sizeof(dist));
    memset(vis, false, sizeof(vis));
    memset(pre, -1, sizeof(pre));
    dist[s] = 0;
    vis[s] = true;
    Q.push(s);
    while(!Q.empty())
    {
        int u = Q.front();
        Q.pop();
        vis[u] = false;
        for(int i = head[u]; i != -1; i = edge[i].next)
        {
            Edge E = edge[i];
            if(dist[E.to] > dist[u] + E.cost && E.cap > E.flow)//可以松弛 且 没有满流
            {
                dist[E.to] = dist[u] + E.cost;
                pre[E.to] = i;//记录前驱边 的编号
                if(!vis[E.to])
                {
                    vis[E.to] = true;
                    Q.push(E.to);
                }
            }
        }
    }
    return pre[t] != -1;//可达返回true
}
void MCMF(int s, int t, int &cost, int &flow)
{
    flow = 0;//总流量
    cost = 0;//总费用
    while(SPFA(s, t))//每次寻找花销最小的路径
    {
        int Min = INF;
        //通过反向弧 在源点到汇点的最少花费路径 找最小增广流
        for(int i = pre[t]; i != -1; i = pre[edge[i^1].to])
        {
            Edge E = edge[i];
            Min = min(Min, E.cap - E.flow);
        }
        //增广
        for(int i = pre[t]; i != -1; i = pre[edge[i^1].to])
        {
            edge[i].flow += Min;
            edge[i^1].flow -= Min;
            cost += edge[i].cost * Min;//增广流的花销
        }
        flow += Min;//总流量累加
    }
}

void getMap()
{

}
int main()
{
    while(scanf("%d%d", &N, &M) != EOF)
    {
        init();
        getMap();//建图
        int cost, flow;//最小费用 最大流
        MCMF(source, sink, cost, flow);
        printf("%d", -cost);//最小费用 最大流
    }
    return 0;
}
