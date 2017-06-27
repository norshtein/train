#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,a;
    cin >> n >> a;
    double per = 180.0 / n;
    int num = a / per;
    double minDiff = fabs(num * per - a);

    if(fabs((num + 1) * per - a) < minDiff)
        num = num + 1;
    int point = n - (num - 1);
    point = min(n,point);
    point = max(3,point);
    cout << 1 << ' ' <<  2 << ' ' << point << endl;
    return 0;
}
