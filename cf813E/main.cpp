#include <bits/stdc++.h>

using namespace std;

struct Node{
    int lc,rc;
    int lCon,rCon,con;
};
const int MAXN = 1e5 + 5;
int n,m;
Node nodes[MAXN << 5];
int cnt;
int root[MAXN];
struct Pos{
    int h,idx;
} wall[MAXN];

void update(int l,int r,int& root,int pre,int pos)
{
    nodes[++cnt] = nodes[pre];
    root = cnt;

    if(l == r)
    {
        nodes[root].con = nodes[root].lCon = nodes[root].rCon = 1;
        return;
    }

    int mid = (l + r) >> 1;
    if(pos <= mid)
        update(l,mid,nodes[root].lc,nodes[pre].lc,pos);
    else
        update(mid + 1,r,nodes[root].rc,nodes[pre].rc,pos);

    //pushup
    int lc = nodes[root].lc;
    int rc = nodes[root].rc;
    nodes[root].con = max(nodes[lc].con,nodes[rc].con);
    nodes[root].lCon = nodes[lc].lCon;
    nodes[root].rCon = nodes[rc].rCon;
    if(nodes[lc].rCon == mid - l + 1)
        nodes[root].lCon += nodes[rc].lCon;
    if(nodes[rc].lCon == r - mid)
        nodes[root].rCon += nodes[lc].rCon;
    nodes[root].con = max(nodes[lc].rCon + nodes[rc].lCon,max(nodes[root].con,max(nodes[root].lCon,nodes[root].rCon)));
}

//Caution:本题不满足区间减法，之所以可做是因为左端点恒定为0
int query(int l,int r,int root,int b,int e)
{
    if(b == l && e == r)
        return nodes[root].con;
    int mid = (l + r) >> 1;
    if(e <= mid)
        return query(l,mid,nodes[root].lc,b,e);
    else if(b > mid)
        return query(mid + 1,r,nodes[root].rc,b,e);
    else
    {
        int lMax = query(l,mid,nodes[root].lc,b,mid);
        int rMax = query(mid + 1,r,nodes[root].rc,mid + 1,e);
        int lCon = min(nodes[nodes[root].lc].rCon,mid - b + 1);
        int rCon = min(nodes[nodes[root].rc].lCon,e - mid);
        return max(max(lMax,rMax),lCon + rCon);
    }
}

int main()
{
    scanf("%d",&n);
    for(int i = 1;i <= n;i++)
        scanf("%d",&wall[i].h),wall[i].idx = i;
    sort(wall + 1,wall + 1 + n,[](Pos a,Pos b){
            return a.h > b.h;
        });
    for(int i = 1;i <= n;i++)
        update(1,n,root[i],root[i - 1],wall[i].idx);

    scanf("%d",&m);
    int l,r,w;
    for(int i = 0;i < m;i++)
    {
        scanf("%d%d%d",&l,&r,&w);
        int bl = 1,br = n;
        while(bl < br)
        {
            int mid = (bl + br) >> 1;
            if(query(1,n,root[mid],l,r) >= w)
                br = mid;
            else
                bl = mid + 1;
        }
        printf("%d\n",wall[bl].h);
    }
    return 0;
}
