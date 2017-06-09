#include <bits/stdc++.h>

using namespace std;

const int MAXN =1e5 + 5;
const int MAXM = 1e5 + 5;
int fa[MAXN];
int rnk[MAXN];
int relation[MAXN];
int total;
int cnt[MAXN];
int n,m;

int getFa(int idx)
{
    if(fa[idx] == idx)
        return idx;
    int r = relation[idx];
    int root = getFa(fa[idx]);
    int rf = relation[fa[idx]];
    relation[idx] = r ^ rf;
    return root;
}

void mergeDSU(int a,int b)
{
    int ra = getFa(a);
    int rb = getFa(b);

    if(ra == rb)
    {
        if(relation[a] != relation[b])
            return;
        else
        {
            total++;
            cnt[a]++;
            cnt[b]++;
            cout << "AT " << a << ' ' << b << endl;
        }

    }
    else
    {
        if(rnk[ra] < rnk[rb])
        {
            swap(ra,rb);
            swap(a,b);
        }
        fa[rb] = ra;
        rnk[rb] += rnk[ra];
        relation[ra] = 1;
    }
}


int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&n,&m);
        for(int i = 0;i <= n;i++)
        {
            fa[i] = i;
            rnk[i] = 1;
            relation[i] = 0;
            cnt[i] = 0;
        }
        total = 0;
        int a,b;
        for(int i = 0;i < m;i++)
        {
            scanf("%d%d",&a,&b);
            mergeDSU(a,b);
        }
        cout << total << endl;
        for(int i = 1;i <= n;i++)
            cout << cnt[i] << ' ';
        cout << endl;
        for(int i = 1;i <= n;i++)
        {
            if(cnt[i] != total)
                putchar('0');
            else
                putchar('1');
        }
        putchar('\n');
    }
    return 0;
}
