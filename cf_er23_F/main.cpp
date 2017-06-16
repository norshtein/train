#include <bits/stdc++.h>

using namespace std;

int n;
const int MAXN = 1e5 + 5;
long long pivot[MAXN << 1];
int pCnt;

struct Query
{
    int t;
    long long l,r;
} q[MAXN];

const int BLOCK = 450;
int one[MAXN * 2 / BLOCK + 5];
int zero[MAXN * 2 / BLOCK + 5];
int rev[MAXN * 2 / BLOCK + 5];
int itv[MAXN * 2];
int blockNum;

int getId(long long num)
{
    return lower_bound(pivot,pivot + pCnt,num) - pivot;
}

void pushdown(int block)
{
    int l = block * BLOCK;
    int r = min((block + 1) * BLOCK,pCnt - 1);
    if(zero[block] || one[block])
    {
        for(int i = l;i < r;i++)
            itv[i] = zero[block] ? 0 : 1;
        rev[block] = 0;
    }

    if(rev[block])
    {
        for(int i = l;i < r;i++)
            itv[i] ^= 1;
        rev[block] = false;
    }
}

void update(int block)
{
    int l = block * BLOCK;
    int r = min((block + 1) * BLOCK,pCnt - 1);
    bool o = false,z = false;
    for(int i = l;i < r;i++)
    {
        if(itv[i])
            o = true;
        else
            z = true;
    }
    zero[block] = z && !o;
    one[block] = o && !z;
}

int query()
{
    for(int i = 0;i < blockNum;i++)
    {
        if(!one[i])
        {
            pushdown(i);
            int l = i * BLOCK;
            int r = (i + 1) * BLOCK;

            for(int j = l;j < r;j++)
            if(!itv[j])
                return j;
        }
    }
    int a = 0;
    return 1 / a;
}

int main()
{
    scanf("%d",&n);
    for(int i = 0;i < n;i++)
    {
        scanf("%d%I64d%I64d",&q[i].t,&q[i].l,&q[i].r);
        pivot[pCnt++] = q[i].l;
        pivot[pCnt++] = ++q[i].r;
    }
    pivot[pCnt++] = 1;
    sort(pivot,pivot + pCnt);
    pCnt = unique(pivot,pivot + pCnt) - pivot;
    pivot[pCnt] = pivot[pCnt - 1] + 1;
    pCnt++;

    blockNum = (pCnt - 2) / BLOCK + 1;
    for(int i = 0;i < blockNum;i++)
        zero[i] = true;

    for(int i = 0;i < n;i++)
    {
        int l = getId(q[i].l);
        int r = getId(q[i].r) - 1;
        int lBlock = l / BLOCK;
        int rBlock = r / BLOCK;
        if(q[i].t == 1 || q[i].t == 2)
        {
            int choice = q[i].t & 1 ? 1 : 0;
            if(lBlock == rBlock)
            {
                pushdown(lBlock);
                for(int i = l;i <= r;i++)
                    itv[i] = choice;
                update(lBlock);
            }
            else
            {
                pushdown(lBlock);
                for(int i = l;i < (lBlock + 1) * BLOCK;i++)
                    itv[i] = choice;
                update(lBlock);

                pushdown(rBlock);
                for(int i = rBlock * BLOCK;i <= r;i++)
                    itv[i] = choice;
                update(rBlock);

                for(int i = lBlock + 1;i < rBlock;i++)
                    rev[i] = 0,one[i] = choice,zero[i] = !choice;
            }
        }
        else
        {
            if(lBlock == rBlock)
            {
                pushdown(lBlock);
                for(int i = l;i <= r;i++)
                    itv[i] ^= 1;
                update(lBlock);
            }
            else
            {
                pushdown(lBlock);
                for(int i = l;i < (lBlock + 1) * BLOCK;i++)
                    itv[i] ^= 1;
                update(lBlock);

                pushdown(rBlock);
                for(int i = rBlock * BLOCK;i <= r;i++)
                    itv[i] ^= 1;
                update(rBlock);

                for(int i = lBlock + 1;i < rBlock;i++)
                {
                    if(one[i] || zero[i])
                        swap(one[i],zero[i]);
                    else
                        rev[i] ^= 1;
                }
            }
        }

        printf("%I64d\n",pivot[query()]);
    }
    return 0;
}
