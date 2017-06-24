#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e5 + 5;
int n;
int T,C;
int t[MAXN];
double c[MAXN];

int main()
{
    scanf("%d",&n);
    scanf("%d%d",&T,&C);
    bool higher = true,lower = true;
    for(int i = 0;i < n;i++)
    {
        scanf("%d%lf",&t[i],&c[i]);
        higher &= T >= t[i];
        lower &= T <= t[i];
    }
    if(!higher && !lower)
        return 0 * printf("Impossible\n");
    else if(higher && lower)
        return 0 * printf("Possible\n%.4f\n",(double)T);

    if(lower)
    {
        int minT = 99999;
        for(int i = 0;i < n;i++)
            minT = min(minT,t[i]);

        if(minT == T)
            return 0 * printf("Impossible\n");

        double need = 0;
        for(int i = 0;i < n;i++)
            need += (minT * c[i] - t[i] * c[i]) / (T - minT);

        if(need <= C)
            return 0 * printf("Possible\n%.4f\n",(double)minT);
        else
            return 0 * printf("Impossible\n");
    }
    else
    {
        int maxT = -1;
        for(int i = 0;i < n;i++)
            maxT = max(maxT,t[i]);

        if(maxT == T)
            return 0 * printf("Impossible\n");

        double need = 0;
        for(int i = 0;i < n;i++)
        {
            need += (maxT * c[i] - t[i] * c[i]) / (T - maxT);
            c[i] += (maxT * c[i] - t[i] * c[i]) / (T - maxT);
        }
        if(need > C)
            return 0 * printf("Impossible\n");
        else
        {
            double remain = C - need;
            double totalC = 0;
            for(int i = 0;i < n;i++)
                totalC += c[i];
            double per = remain / totalC;
            double cc = per * c[0];
            double ans = (maxT * c[0] + T * cc) / (c[0] + cc);
            return 0 * printf("Possible\n%.4f\n",ans);
        }
    }
    return 0;
}
