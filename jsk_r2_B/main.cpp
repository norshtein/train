#include <bits/stdc++.h>

using namespace std;

const int MAXM = 255;
int dp[MAXM][MAXM];
int n,m;

const double eps = 1e-6;
void work(int x1,int y1,int x2,int y2,int idx)
{
    if(x1 == x2)
    {
        for(int i = y1;i <= y2;i++)
            dp[x1][i] = idx;
        return;
    }
    if(x1 > x2)
    {
        swap(x1,x2);
        swap(y1,y2);
    }
    double k = (double)(y2 - y1) / (x2 - x1);
    //cout << idx << ' ' << k << endl;
    dp[x1][y1] = dp[x2][y2] = idx;
    for(int i = x1 + 1;i < x2;i++)
    {
        double y = k * (i - x1) + y1;
        //cout << idx << ' '  << i << ' ' << y << endl;
        if(fabs(y - round(y)) < eps)
            dp[i][(int)round(y)] = idx;
    }
}
int main()
{
    scanf("%d%d",&n,&m);
    int x1,x2,y1,y2;
    for(int i = 1;i <= n;i++)
    {
        scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
        work(x1,y1,x2,y2,i);
    }
    int q;
    scanf("%d",&q);
    for(int i = 0;i < q;i++)
    {
        scanf("%d%d",&x1,&x2);
        printf("%d\n",dp[x1][x2]);
    }
    return 0;
}
