#include<bits/stdc++.h>

using namespace std;

const int MAXQ = 160000 + 10000 + 5;
const int MAXW = 2e6 + 5;
int w;
int cnt,qcnt;

int c[MAXW];
inline int lowbit(int x)
{
    return x & -x;
}
void update(int x,int delta)
{
    for(int i = x;i <= w;i += lowbit(i))
        c[i] += delta;
}
int sum(int x)
{
    int ans = 0;
    for(int i = x;i;i -= lowbit(i))
        ans += c[i];
    return ans;
}

struct Query
{
    int op,x,y,val,id,q;
} query[MAXQ << 2];

Query temp[MAXQ << 2];
int answer[10005];

void cdq(int l,int r)
{
    if(l >= r)
        return;
    int mid = (l + r) >> 1;
    for(int i = l;i <= r;i++)
    {
        if(query[i].id <= mid && query[i].op == 1)
            update(query[i].y,query[i].val);
        else if(query[i].id > mid && query[i].op == 2)
            answer[query[i].q] += sum(query[i].y) * query[i].val;
    }

    for(int i = l;i <= r;i++)
        if(query[i].id <= mid && query[i].op == 1)
            update(query[i].y,-query[i].val);

    int p = l,q = mid + 1;
    for(int i = l;i <= r;i++)
    {
        if(query[i].id <= mid)
            temp[p++] = query[i];
        else
            temp[q++] = query[i];
    }
    for(int i = l;i <= r;i++)
        query[i] = temp[i];
    cdq(l,mid);
    cdq(mid + 1,r);

}

bool cmp(const Query& q1,const Query& q2)
{
    return q1.x < q2.x || q1.x == q2.x && q1.y < q2.y || q1.x == q2.x && q1.y == q2.y && q1.op < q2.op;
}
int main()
{
    scanf("%*d%d",&w);
    while(true)
    {
        int c;
        scanf("%d",&c);
        if(c == 1)
        {
            scanf("%d%d%d",&query[cnt].x,&query[cnt].y,&query[cnt].val);
            query[cnt].id = cnt;
            query[cnt++].op = c;
        }
        else if(c == 2)
        {
            int x1,x2,y1,y2;
            scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
            query[cnt].op = c,query[cnt].x = x1 - 1,query[cnt].y = y1 - 1,query[cnt].id = cnt,query[cnt].val = 1,query[cnt++].q = qcnt;
            query[cnt].op = c,query[cnt].x = x1 - 1,query[cnt].y = y2,query[cnt].id = cnt,query[cnt].val = -1,query[cnt++].q = qcnt;
            query[cnt].op = c,query[cnt].x = x2,query[cnt].y = y1 - 1,query[cnt].id = cnt,query[cnt].val = -1,query[cnt++].q = qcnt;
            query[cnt].op = c,query[cnt].x = x2,query[cnt].y = y2,query[cnt].id = cnt,query[cnt].val = 1,query[cnt++].q = qcnt++;
        }
        else
            break;
    }
    sort(query,query + cnt,cmp);

    //for(int i = 0;i < cnt;i++)
    //    cout << query[i].op << ' ' << query[i].x << ' ' << query[i].y << ' ' << query[i].id << ' ' << query[i].val << endl;
    cdq(0,cnt - 1);
    for(int i = 0;i < qcnt;i++)
        printf("%d\n",answer[i]);
    return 0;
}
