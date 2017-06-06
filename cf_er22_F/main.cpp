#include<bits/stdc++.h>
using namespace std;
const int N = 500100;
const int M = 500100;
struct edge{
    int x,y;
    int st,ed;
    edge() {}
    edge(int _,int __,int ___,int ____):
    x(_),y(__),st(___),ed(____) {}
}a[N];

int tot;
int n,m,T;
int sta[M<<2],top;


namespace Union_Find_Set{
    int fa[M],rank[M],a[M];
    int Find(int x)
    {
        while(fa[x]!=x)
            x=fa[x];
        return fa[x]=x;
    }
    int Distance(int x)
    {
        int re=0;
        while(fa[x]!=x&&fa[x])
            re^=a[x],x=fa[x];
        return re;
    }
    void Union(int x,int y,int z)
    {
        x=Find(x);y=Find(y);
        if(x==y) return ;
        if(rank[x]>rank[y])
            swap(x,y);
        if(rank[x]==rank[y])
            rank[y]++,sta[++top]=-y;
        fa[x]=y;a[x]=z;sta[++top]=x;
    }
    void Restore(int bottom)
    {
        while(top>bottom)
        {
            if(sta[top]<0)
                rank[-sta[top]]--;
            else
                fa[sta[top]]=sta[top],a[sta[top]]=0;
            top--;
        }
    }
}

void Divid_And_Conquer(int x,int y,vector<edge> &e)
{
    using namespace Union_Find_Set;
    vector<edge>::iterator it;
    int i,mid=(x+y)>>1,bottom=top;
    vector<edge> l,r;
    for(it=e.begin();it!=e.end();it++)
    {
        if(it->st==x&&it->ed==y)
        {
            int _x=Find(it->x);
            int _y=Find(it->y);
            int _z=Distance(it->x)^Distance(it->y)^1;
            if(_x!=_y)
                Union(_x,_y,_z);
            else if(_z&1)
            {
                for(i=x;i<=y;i++)
                    puts("NO");
                Restore(bottom);
                return ;
            }
        }
        else if(it->ed<=mid)
            l.push_back(*it);
        else if(it->st>mid)
            r.push_back(*it);
        else
            l.push_back(edge(it->x,it->y,it->st,mid)),r.push_back(edge(it->x,it->y,mid+1,it->ed));
    }
    if(x==y)
        puts("YES");
    else
        Divid_And_Conquer(x,mid,l),Divid_And_Conquer(mid+1,y,r);
    Restore(bottom);
}
#define pii pair<int,int>
#define MP make_pair
map< pii, int > mm;

int main()
{
    int i;
    edge e;
    vector<edge> v;
    cin>>n>>m;
    for(i=1;i<=n;i++)
        Union_Find_Set::fa[i]=i;
    tot = 0;
    for(i=1;i<=m;i++)
    {
        scanf("%d%d",&e.x,&e.y);
        if(mm[MP(e.x,e.y)] != 0)
        {
            a[mm[MP(e.x, e.y)]].ed = i - 1;
            mm[MP(e.x, e.y)] = 0;
            mm[MP(e.y, e.x)] = 0;
        }
        else
        {
            e.st = i;
            a[++tot] = e;
            a[tot].ed = m;
            mm[MP(e.x, e.y)] = tot;
            mm[MP(e.y, e.x)] = tot;
        }
    }
    for(int i = 1; i <= tot; i++)
        v.push_back(a[i]);
    Divid_And_Conquer(1,m,v);
    return 0;
}
