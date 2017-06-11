#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e5 + 5;
int a[MAXN],b[MAXN];
int pre[MAXN];
bool visited[MAXN];
char choice[MAXN];
int n;
bool inf = false;

void dfs(int now,bool allA)
{
    visited[now] = true;
    int ca = now + a[now];
    if(ca >= 1 && ca <= n)
    {
        if(!visited[ca])
        {
            pre[ca] = now;
            choice[ca] = 'a';
            dfs(ca,true);
        }
        else if(visited[ca] && allA)
            inf =  true;
    }

    int cb = now + b[now];
    if(cb >= 1 && cb <= n && !visited[cb])
    {
        pre[cb] = now;
        choice[cb] = 'b';
        dfs(cb);
    }
}

vector<char> ans;
void print(int idx)
{
    if(pre[idx] == 0)
        return;
    print(pre[idx]);
    ans.push_back(choice[idx]);
}

int main()
{
    scanf("%d",&n);
    for(int i = 1; i <= n;i++)
        scanf("%d",a + i);
    for(int i = 1;i <= n;i++)
        scanf("%d",b + i);

    dfs(1,true);
    if(!visited[n])
        puts("No solution!");
    else
    {
        print(n);
        if(inf)
            puts("Infinity!");
        else
        {
            for(auto cc:ans)
                putchar(cc);
        }
    }

    return 0;
}

#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e5 + 5;
int a[MAXN],b[MAXN];
int pre[MAXN];
bool visited[MAXN];
char choice[MAXN];
int n;

void dfs(int now)
{
    visited[now] = true;
    int ca = now + a[now];
    if(ca >= 1 && ca <= n && !visited[ca])
    {
        pre[ca] = now;
        choice[ca] = 'a';
        dfs(ca);
    }
    int cb = now + b[now];
    if(cb >= 1 && cb <= n && !visited[cb])
    {
        pre[cb] = now;
        choice[cb] = 'b';
        dfs(cb);
    }
}

vector<char> ans;
bool inf = false;
void print(int idx)
{
    if(pre[idx] == 0)
        return;
    print(pre[idx]);
    ans.push_back(choice[idx]);
    if(choice[idx] == 'b' && a[idx] == 0)
        inf = true;
}

int main()
{
    scanf("%d",&n);
    for(int i = 1; i <= n;i++)
        scanf("%d",a + i);
    for(int i = 1;i <= n;i++)
        scanf("%d",b + i);

    dfs(1);
    if(!visited[n])
        puts("No solution!");
    else
    {
        print(n);
        if(inf)
            puts("Infinity!");
        else
        {
            for(auto cc:ans)
                putchar(cc);
        }
    }

    return 0;
}

