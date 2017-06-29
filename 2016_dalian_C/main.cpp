#include <bits/stdc++.h>

using namespace std;

const int MAXN = 50;
int sg[100][100];
bool visited[100][100];

int dfs(int a,int b)
{
    if(visited[a][b])
        return sg[a][b];

    visited[a][b] = true;
    bool occur[100] = {0};
    for(int i = 1;i <= a;i++)
        occur[dfs(max(a - i,b),min(a - i,b))] = true;
    for(int i = 1;i <= b;i++)
        occur[dfs(a,b - 1)]  = true;
    for(int i = 1;i <= b;i++)
        occur[dfs(a - i,b - i)] = true;

    int now = 0;
    while(true)
    {
        if(occur[now])
        {
            now++;
            continue;
        }
        sg[a][b] = now;
        break;
    }
}
int main()
{
    memset(sg,-1,sizeof(sg));
    sg[0][0] = 0;
    visited[0][0] = true;

    for(int i = 1;i <= MAXN;i++)
        for(int j = 0;j <= i;j++)
            if(!visited[i][j])
                dfs(i,j);
    for(int i = 0;i <= MAXN;i++)
    {
        for(int j = 0;j <= MAXN;j++)
            if(sg[i][j] == 0)
                cout << i << ' ' << j << endl;
    }
    return 0;
}
