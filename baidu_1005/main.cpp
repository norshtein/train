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
int pre[MAXN];//��¼����·���� �����i�ıߵı��
int dist[MAXN];
bool vis[MAXN];
int N, M;//���� ����
int source, sink;//����Դ�� �������
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
bool SPFA(int s, int t)//Ѱ�һ������ٵ�·��
{
    //��һ��SPFA ��s����t�����ٻ���·�� �Ҹ�·����ÿһ���߲�������
    //������ ˵�����Լ������㣬��֮����
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
            if(dist[E.to] > dist[u] + E.cost && E.cap > E.flow)//�����ɳ� �� û������
            {
                dist[E.to] = dist[u] + E.cost;
                pre[E.to] = i;//��¼ǰ���� �ı��
                if(!vis[E.to])
                {
                    vis[E.to] = true;
                    Q.push(E.to);
                }
            }
        }
    }
    return pre[t] != -1;//�ɴﷵ��true
}
void MCMF(int s, int t, int &cost, int &flow)
{
    flow = 0;//������
    cost = 0;//�ܷ���
    while(SPFA(s, t))//ÿ��Ѱ�һ�����С��·��
    {
        int Min = INF;
        //ͨ������ ��Դ�㵽�������ٻ���·�� ����С������
        for(int i = pre[t]; i != -1; i = pre[edge[i^1].to])
        {
            Edge E = edge[i];
            Min = min(Min, E.cap - E.flow);
        }
        //����
        for(int i = pre[t]; i != -1; i = pre[edge[i^1].to])
        {
            edge[i].flow += Min;
            edge[i^1].flow -= Min;
            cost += edge[i].cost * Min;//�������Ļ���
        }
        flow += Min;//�������ۼ�
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
        getMap();//��ͼ
        int cost, flow;//��С���� �����
        MCMF(source, sink, cost, flow);
        printf("%d", -cost);//��С���� �����
    }
    return 0;
}
