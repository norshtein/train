#include <bits/stdc++.h>

using namespace std;

int main()
{
    int c,v0,v1,a,l;
    cin >> c >> v0 >> v1 >> a >> l;
    int nowpage = 0;
    int nowv = v0;
    int day = 0;
    bool first = true;
    while(true)
    {
        day++;
        nowpage += nowv;
        if(nowpage >= c)
            break;
        if(first)
        {
            first = false;
            nowv -= l;
        }

        nowv = min(v1 - l,nowv + a);
        //cout << day << ' ' << nowv << endl;
        //cout << nowpage << endl;
    }
    cout << day << endl;

    return 0;
}
