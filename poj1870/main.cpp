#include <iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<cstring>
#include<cstdio>

using namespace std;

int pivot[100][7];
int border[100];
int layer = 1;

struct Point{
    int x,y,z;
    Point(int xx = 0,int yy = 0,int zz = 0):x(xx),y(yy),z(zz){}
    Point operator-(const Point& p) const
    {
        return Point(x - p.x,y - p.y,z - p.z);
    }
    Point operator+(const Point& p) const
    {
        return Point(x + p.x,y + p.y,z + p.z);
    }
    Point operator*(int times) const
    {
        return Point(x * times,y * times,z * times);
    }
};

Point line[] = {Point(),Point(0,0,-1),Point(0,-1,0),Point(-1,0,0),Point(0,0,1),Point(0,1,0),Point(1,0,0)};
Point direction[] = {Point(),Point(0,1,0),Point(1,0,0),Point(0,0,-1),Point(0,-1,0),Point(-1,0,0),Point(0,0,1)};

Point getCor(int a)
{
    int al = lower_bound(border,border + layer,a) - border;
    int ap = lower_bound(pivot[al] + 1,pivot[al] + 7,a) - pivot[al];
    int p = pivot[al][ap];

    Point ans = line[ap] * al;
    while(a < p)
    {
        p--;
        ans = ans + direction[ap];
    }
    return ans;
}
int main()
{
    border[0] = 1;
    int now = 1;
    while(now <= 10000)
    {
        now += layer * 6;
        border[layer] = now;
        for(int i = 6;i >= 1;i--)
            pivot[layer][i] = now - (6 - i) * layer;
        layer++;
    }

    int a,b;
    while(scanf("%d%d",&a,&b) != EOF && a)
    {
        Point pa = getCor(a);
        Point pb = getCor(b);
        Point v = pa - pb;

        bool changed = false;
        do
        {
            changed = false;
            if(v.x * v.z > 0)
            {
                int shift = min(v.x,v.z);
                v.y += shift;
                v.x -= shift;
                v.z -= shift;
                changed = true;
            }
            if(v.x * v.y < 0)
            {
                int sign = v.y > 0 ? 1 : -1;
                int shift = min(abs(v.y),abs(v.x));
                v.y -= shift * sign;
                v.x += shift * sign;
                v.z += shift * sign;
                changed = true;
            }
            if(v.y * v.z < 0)
            {
                int sign = v.y > 0 ? 1 : -1;
                int shift = min(abs(v.y),abs(v.z));
                v.y -= shift * sign;
                v.z += shift * sign;
                v.x += shift * sign;
                changed = true;
            }
        }while(changed);

        printf("The distance between cells %d and %d is %d.\n",a,b,abs(v.x) + abs(v.y) + abs(v.z));
    }
    return 0;
}
