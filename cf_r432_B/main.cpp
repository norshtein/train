#include<bits/stdc++.h>

using namespace std;

int main()
{
    long long ax,ay,bx,by,cx,cy;
    cin >> ax >> ay >> bx >> by >> cx >> cy;
    long long ab = (bx - ax) * (bx - ax) + (by - ay) * (by - ay);
    long long bc = (bx - cx) * (bx - cx) + (by - cy) * (by - cy);
    long long ac = (ax - cx) * (ax - cx) + (ay - cy) * (ay - cy);

    if(ab == bc && (by - ay) * (cx - bx) - (cy - by) * (bx - ax) != 0)
        puts("Yes");
    else
        puts("No");
    return 0;
}
