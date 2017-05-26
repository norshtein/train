#include <iostream>
#include<algorithm>
#include<vector>
#include<set>
#include<string>
#include<cmath>
#include<cstdio>

using namespace std;

const char* prefix[] = {"","Probability of covering 1 tile  = ","Probability of covering 2 tiles = ","Probability of covering 3 tiles = ","Probability of covering 4 tiles = "};
const double PI = acos(-1.0);

int main()
{
    int T;
    int m,n;
    double t,c;
    scanf("%d",&T);
    for(int caseNum = 1;caseNum <= T;caseNum++)
    {
        double area[5] = {0};
        scanf("%d%d%lf%lf",&m,&n,&t,&c);
        printf("Case %d:\n",caseNum);

        double totalArea = m * n * t * t;
        if(m < n)
            swap(m,n);
        if(m == 1 && n == 1)
        {
            printf("%s%.4f%%\n",prefix[1],100.0);
            for(int i = 2;i <= 4;i++)
                printf("%s%.4f%%\n",prefix[i],0.0);
            putchar('\n');
            continue;
        }
        else if(n == 1)
        {
            area[1] = (m - 2) * (t - c) * t + 2 * (t - c / 2) * t;
            area[2] = (m - 2) * c * t + 2 * c * t / 2;
        }
        else
        {
            int inner = (m - 2) * (n - 2);
            int border = (2 * m + 2 * n - 8);
            int corner = 4;

            area[1] += inner * (t - c) * (t - c);
            area[1] += border * (t - c) * (t - c / 2);
            area[1] += corner * (t - c / 2) * (t - c / 2);
            area[2] += inner * 2 * c * (t - c);
            area[2] += border * (3 * c * t / 2 - c * c);
            area[2] += corner * (c * t - c * c / 2);
            area[4] += inner * PI * c * c / 4;
            area[4] += border * PI * c * c / 8;
            area[4] += corner * PI * c * c / 16;
            area[3] = totalArea - area[1] - area[2] - area[4];
        }
        for(int i = 1;i <= 4;i++)
            printf("%s%.4f%%\n",prefix[i],area[i] / totalArea * 100);
        putchar('\n');
    }
    return 0;
}
