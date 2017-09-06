#include<bits/stdc++.h>

using namespace std;

struct Point{
    int a,b,c,d,e;
    Point operator-(const Point& p) const
    {
        Point ans;
        ans.a = this->a - p.a;
        ans.b = this->b - p.b;
        ans.c = this->c - p.c;
        ans.d = this->d - p.d;
        ans.e = this->e - p.e;
        return ans;
    }
    int operator*(const Point& p) const
    {
        int ans = 0;
        ans += this->a * p.a;
        ans += this->b * p.b;
        ans += this->c * p.c;
        ans += this->d * p.d;
        ans += this->e * p.e;
        return ans;
    }
} points[20];
bool vaild[20];

int main()
{
    int k;
    scanf("%d",&k);
    if(k >= 12)
    {
        puts("0");
        return 0;
    }

    for(int i = 0;i < k;i++)
        scanf("%d%d%d%d%d",&points[i].a,&points[i].b,&points[i].c,&points[i].d,&points[i].e),vaild[i] = true;

    for(int i = 0;i < k;i++)
    {
        for(int j = 0;j < k && vaild[i];j++)
        {
            if(j == i)
                continue;
            Point ij = points[j] - points[i];
            for(int q = 0;q < k;q++)
            {
                if(q == i || q == j)
                    continue;
                Point iq = points[q] - points[i];
                if(ij * iq > 0)
                {
                    vaild[i] = false;
                    break;
                }
            }
        }
    }

    int sze = 0;
    for(int i = 0;i < k;i++)
        sze += vaild[i];
    printf("%d\n",sze);
    for(int i = 0;i < k;i++)
    {
        if(vaild[i])
            printf("%d\n",i + 1);
    }
    return 0;
}
