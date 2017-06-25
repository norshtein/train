#include <iostream>
#include<bits/stdc++.h>

using namespace std;

const int MAXN = 1e5 + 5;
vector<int> G[MAXN];
int k[MAXN];

int ans = 0;
int dfs(int idx)
{
    int up = 0;
    for(int i = 0;i < G[idx].size();i++)
    {
        up = max(dfs(G[idx][i]),up);
    }
    if(up == 0)
        up = k[idx],ans++;
    cout << idx << ' ' << up << ' ' << ans << endl;
    return up - 1;
}

int n;
int main()
{
    scanf("%d",&n);
    int fa;
    for(int i = 2;i <= n;i++)
    {
        scanf("%d",&fa);
        G[fa].push_back(i);
    }
    for(int i = 1;i <= n;i++)
        scanf("%d",&k[i]);
    dfs(1);
    cout << ans << endl;
    return 0;
}
