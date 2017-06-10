#include <bits/stdc++.h>

using namespace std;

struct Node{
    int to;
    long long cost;
    Node(int t = 0, long long c = 0) :to(t), cost(c){}
    bool operator<(const Node& n) const
    {
        return this->cost > n.cost;
    }
};

const int MAXN = 20005;
const int MAXM = 20005;
int n,m;
vector<int> gToC[MAXM];
vector<int> cToG[MAXN];
vector<pair<int,int> > G1[MAXN]; //city to city;
vector<pair<int,int> > G2[MAXM]; //group to group
int s,t;

priority_queue<Node> q;
long long d[MAXN];
const long long INF = 1e18;
bool visited[MAXN];
set<pair<int,int> > useless;

void dijkstra(int s)
{
    for (int i = 1; i <= n; i++)
        d[i] = INF;
    d[s] = 0;
    memset(visited, 0, sizeof(visited));

    q.push(Node(s, 0));
    while (!q.empty())
    {
        int nowIdx = q.top().to;
        q.pop();

        if (visited[nowIdx])
            continue;
        if(nowIdx == t)
            break;
        visited[nowIdx] = true;
        for (int i = 0; i < G1[nowIdx].size(); i++)
        {
            int v = G1[nowIdx][i].first;
            if (visited[v])
                continue;
            if (d[v] > d[nowIdx] + G1[nowIdx][i].second)
            {
                d[v] = d[nowIdx] + G1[nowIdx][i].second;
                q.push(Node(v,d[v]));
            }
        }

        for(int i = 0;i < cToG[nowIdx].size();i++)
        {
            int nowG = cToG[nowIdx][i];
            for(int j = 0;j < G2[nowG].size();j++)
            {
                int otherG = G2[nowG][j].first;
                int c = G2[nowG][j].second;
                if(useless.count(make_pair(nowG,otherG)))
                    continue;

                bool flag = true;
                for(auto v:gToC[otherG])
                {
                    if (d[v] > d[nowIdx] + c)
                    {
                        d[v] = d[nowIdx] + c;
                        q.push(Node(v,d[v]));
                        flag = false;
                    }
                }
                if(flag)
                    useless.insert(make_pair(nowG,otherG));
            }
        }

        for (int i = 0; i < G1[nowIdx].size(); i++)
        {
            int v = G1[nowIdx][i].first;
            if (visited[v])
                continue;
            if (d[v] > d[nowIdx] + G1[nowIdx][i].second)
            {
                d[v] = d[nowIdx] + G1[nowIdx][i].second;
                q.push(Node(v,d[v]));
            }
        }
    }
}

int main()
{
    scanf("%d%d",&n,&m);
    int k,kk;
    for(int i = 1;i <= m;i++)
    {
        scanf("%d",&k);
        for(int j = 0;j < k;j++)
        {
            scanf("%d",&kk);
            cToG[kk].push_back(i);
            gToC[i].push_back(kk);
        }
    }

    scanf("%d",&k);
    int u,v,c;
    for(int i = 0;i < k;i++)
    {
        scanf("%d%d%d",&u,&v,&c);
        G1[u].push_back(make_pair(v,c));
        G1[v].push_back(make_pair(u,c));
    }
    scanf("%d",&k);
    for(int i = 0;i < k;i++)
    {
        scanf("%d%d%d",&u,&v,&c);
        G2[u].push_back(make_pair(v,c));
        G2[v].push_back(make_pair(u,c));
    }

    scanf("%d%d",&s,&t);
    dijkstra(s);
    printf("%lld\n",d[t] == INF ? (long long)(-1) : d[t]);
    return 0;
}
