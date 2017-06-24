#include<bits/stdc++.h>

using namespace std;

const int MAXN = 5e4 + 5;
int n,m;
int a[MAXN];
int times[MAXN];
set<int> tToid[MAXN];
int ans[MAXN];
int numCnt = 0;

struct Query
{
    int l,r,k;
    int idx;
}q[MAXN];

void add(int x)
{
    int nowTimes = times[a[x]];
    if(nowTimes != 0)
        tToid[nowTimes].erase(a[x]);
    else
        numCnt++;

    times[a[x]]++;
    tToid[nowTimes + 1].insert(a[x]);
}
void del(int x)
{
    int nowTimes = times[a[x]];
    if(nowTimes != 0)
        tToid[nowTimes].erase(a[x]);

    times[a[x]]--;
    if(--nowTimes)
        tToid[nowTimes].insert(a[x]);
    else
        numCnt--;
}

int main()
{
    scanf("%d%d",&n,&m);
    for(int i = 1;i <= n;i++)
        scanf("%d",&a[i]);
    for(int i = 0;i < m;i++)
        scanf("%d%d%d",&q[i].l,&q[i].r,&q[i].k),q[i].idx = i;

    sort(q,q + m,[](Query q1,Query q2){
            if(q1.l != q2.l)
                return q1.l < q2.l;
            return q1.r < q2.r;
        });


    int L = 1,R = 0;
    for(int i = 0;i < m;i++)
    {
        int nowL = q[i].l;
        int nowR = q[i].r;
        while(R < nowR)
        {
            R++;
            add(R);
        }
        while(R > nowR && R >= L)
        {
            del(R);
            R--;
        }
        while(L < nowL)
        {
            del(L);
            L++;
        }
        while(L > nowL)
        {
            L--;
            add(L);
        }
        while(R > nowR && R >= L)
        {
            del(R);
            R--;
        }
        int k = q[i].k;
        vector<int> fs;
        for(int factor = 2;factor <= sqrt(k);factor++)
        {
            if(k % factor == 0)
                fs.push_back(factor);
            while(k % factor == 0)
                k /= factor;
        }
        if(k != 1)
            fs.push_back(k);
        ans[q[i].idx] = numCnt;
        for(auto factor:fs)
            ans[q[i].idx] -= tToid[factor].size();
    }

    for(int i = 0;i < m;i++)
        printf("%d\n",ans[i]);
    return 0;
}
