#include<bits/stdc++.h>

using namespace std;

const int MAXN =1005;
int fa[MAXN];
int cnt[MAXN];
int rel[MAXN];
int type[MAXN];
int N,M,X,Y;

int getFa(int idx)
{
    if(fa[idx] == idx)
        return idx;
    int nowfa = fa[idx];
    int root = getFa(fa[idx]);
    rel[idx] = rel[idx] ^ rel[nowfa];
    fa[idx] = root;
    return root;
}

int main()
{
    while(scanf("%d%d%d%d",&N,&M,&X,&Y) != EOF)
    {
        for(int i = 0;i <= N;i++)
        {
            fa[i] = i;
            cnt[i] = 1;
            rel[i] = 0;
            type[i] = -1;
        }

        bool vaild = true;
        int a,b;
        for(int i = 0;i < M;i++)
        {
            scanf("%d%d",&a,&b);
            int ra = getFa(a);
            int rb = getFa(b);
            if(ra == rb)
            {
                vaild &= rel[a] != rel[b];
                continue;
            }

            int r = rel[a] ^ rel[b] ^ 1;
            fa[ra] = rb;
            cnt[rb] += cnt[ra];
            rel[ra] = r;
        }

        for(int i = 0;i < X;i++)
        {
            scanf("%d",&a);
            type[a] = 1;
        }
        for(int i = 0;i < Y;i++)
        {
            scanf("%d",&a);
            type[a] = 0;
        }

        for(int i = 1;i <= N;i++)
        {
            if(type[i] == -1 && getFa(i) == i && cnt[i] == 1)
                vaild = false;
            if(type[i] != -1)
            {
                int r = getFa(i);
                if(type[r] == -1)
                    type[r] = type[i] ^ rel[i];
                else
                    vaild &= (type[r] == (type[i] ^ rel[i]));
            }
        }
        if(vaild)
            puts("YES");
        else
            puts("NO");

    }

    return 0;
}
