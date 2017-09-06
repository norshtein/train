#include<bits/stdc++.h>

using namespace std;

string a,b;

//get digit
int d(char c)
{
    return c - '0';
}

void add(string& a,string& b)
{
    //cout << a << ' ' << b << endl;
    int len = max(a.length(),b.length());
    a.resize(len + 1,'0');
    b.resize(len + 1,'0');
    //cout << a << ' ' << b << endl;
    for(int i = 0;i < len;i++)
    {
        a[i] += d(b[i]);
        a[i + 1] += d(a[i]) / 10;
        a[i] = d(a[i]) % 10 + '0';
    }
}


int main()
{
    cin >> a >> b;
    string ans(a.length(),'0');

    for(int i = b.length() - 1;i >= 0;i--)
    {
        int now = d(b[i]);
        string tmp(a.length() + 2 + b.length() - 1 - i,'0');
        int cursor = b.length() - 1 - i;
        //cout << cursor << endl;
        for(int j = a.length() - 1;j >= 0;j--)
        {
            tmp[cursor] += now * d(a[j]);
            tmp[cursor + 1] += d(tmp[cursor]) / 10;
            tmp[cursor] = d(tmp[cursor]) % 10 + '0';
            cursor++;
        }

        add(ans,tmp);
        //cout << ans << '    ' << tmp << endl;
    }
    bool zero = true;
    for(int i = ans.length() - 1;i >= 0;i--)
    {
        if(ans[i] == '0' && zero)
            continue;
        zero = false;
        putchar(ans[i]);
    }
    putchar('\n');
    return 0;
}
