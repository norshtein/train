#include <bits/stdc++.h>

using namespace std;

const double PI = acos(-1.0);

int main()
{
    int N,D;
    //cout << sin(0.5 * PI);
    while(cin >> N >> D)
    {
        double ans = 0;
        double ang;
        for(int i = 0;i < N;i++)
        {
            cin >> ang;
            ang = ang / 180.0 * PI;
            //cout << ang << ' ' << sin(ang) << endl;
            ans += 0.5 * D * D * sin(ang);
            //cout << ans << endl;
        }
        printf("%.3f\n",ans);
    }
    return 0;
}
