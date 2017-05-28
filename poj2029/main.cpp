#include <cstdio>
#include<iostream>
#include<cstring>

using namespace std;

int bt[105][105];
int N;
int W,H;

inline int lowbit(int i)
{
    return i & -i;
}
void update(int r,int c,int delta)
{
    for(int i = r;i <= H;i += lowbit(i))
    {
        for(int j = c;j <= W;j += lowbit(j))
            bt[i][j] += delta;
    }
}

int sum(int r,int c)
{
    int ans = 0;
    for(int i = r;i;i -= lowbit(i))
    {
        for(int j = c;j;j -= lowbit(j))
            ans += bt[i][j];
    }
    return ans;
}


int main()
{
    while(scanf("%d",&N) != EOF && N)
    {
        scanf("%d%d",&W,&H);
        for(int i = 0;i <= H + 1;i++)
            fill(bt[i],bt[i] + sizeof(int) * (W  + 2),0);

        int a,b;
        for(int i = 0;i < N;i++)
        {
            scanf("%d%d",&a,&b);
            update(b,a,1);
        }
        scanf("%d%d",&b,&a);

        int ans = 0;
        for(int i = 1;i + a - 1<= H;i++)
        {
            for(int j = 1;j + b -1 <= W;j++)
                ans = max(ans,sum(i + a - 1,j + b - 1) - sum(i - 1,j + b - 1) - sum(i + a - 1,j - 1) + sum(i - 1,j - 1));
        }
        printf("%d\n",ans);

    }
    return 0;
}
