#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1005;
int a[MAXN];
int b[MAXN];
int n;
bool visited[MAXN];
int p[MAXN];
int main()
{
    cin >> n;
    for(int i = 1;i <= n;i++)
        cin >> a[i];
    for(int i = 1;i <= n;i++)
        cin >> b[i];
    int aa = 0,bb = 0;
    for(int i = 1;i <= n;i++)
    {
        if(a[i] != b[i])
        {
            if(!aa)
                aa = i;
            else
                bb = i;
        }
        else
            visited[a[i]] = true,p[i] = a[i];
    }

    //cout << aa << ' ' << bb <<endl;
    if(bb == 0)
    {
        for(int i = 1;i <= n;i++)
        {
            if(!visited[i])
            {
                p[aa] = i;
                break;
            }
        }
    }
    else
    {
        if(!visited[a[aa]] && !visited[b[bb]] && a[aa] != b[bb])
            p[aa] = a[aa],p[bb] = b[bb];
        else
            p[aa] = b[aa],p[bb] = a[bb];
    }

    for(int i = 1;i <= n;i++)
        cout << p[i] << " \n"[i == n];
    return 0;
}
