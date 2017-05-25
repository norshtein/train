#include <iostream>
#include<set>
#include<string>
#include<algorithm>
#include<vector>

using namespace std;

vector<string> se;
int m;
string s;

int main()
{
    cin.tie(0);
    cin.sync_with_stdio(false);
    cin >> m;
    for(int i = 0;i < m;i++)
    {
        se.clear();
        cin >> s;
        string a,b;
        for(int len = 1;len < s.size() ;len++)
        {
            a = s.substr(0,len);
            b = s.substr(len,string::npos);
            se.push_back(a + b);
            se.push_back(b + a);

            reverse(b.begin(),b.end());
            se.push_back(a + b);
            se.push_back(b + a);

            reverse(a.begin(),a.end());
            se.push_back(a + b);
            se.push_back(b + a);

            reverse(b.begin(),b.end());
            se.push_back(a + b);
            se.push_back(b + a);
        }
        sort(se.begin(),se.end());
        cout << unique(se.begin(),se.end()) - se.begin() <<endl;
    }
    return 0;
}
