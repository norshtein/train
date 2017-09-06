#include <bits/stdc++.h>

using namespace std;

int main()
{
    string s;
    cin >> s;

    for(int len = s.length() - 2;len >= 0;len -= 2)
    {
        bool vaild = true;
        for(int i = 0;i < len / 2;i++)
        {
            if(s[i] != s[i + len / 2])
            {
                vaild =false;
                break;
            }
        }
        if(vaild)
        {
            cout << len << endl;
            return 0;
        }
    }
    return 0;
}
