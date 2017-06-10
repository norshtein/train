#include <cstdio>
#include<cstring>
#include<iostream>

using namespace std;

const int MAXN = 40000 + 5;
int c[MAXN];
int n;
inline int lowbit(int x)
{
    return x & -x;
}
void update(int idx,int val)
{
    for(int i = idx;i <= n;i+=lowbit(i))
        c[i] = max(c[i],val);
}
int getMax(int idx)
{
    int ans = 0;
    for(int i = idx;i;i -= lowbit(i))
        ans = max(c[i],ans);
    return ans;
}

int a[MAXN];

int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        memset(c,0,sizeof(int) * (n + 1));
        for(int i = 0;i < n;i++)
            scanf("%d",a + i);
        int ans = 0;
        for(int i = 0;i < n;i++)
        {
            int now = getMax(a[i]);
            ans = max(ans,++now);
            update(a[i],now);
        }
        cout << ans << endl;
    }

    return 0;
}
