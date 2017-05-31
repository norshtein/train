#include <bits/stdc++.h>

using namespace std;

struct State{
    int ii,jj,kk;
    State(int i =0,int j = 0,int k = 0):ii(i),jj(j),kk(k){}
};

int nxt[105];
int dp[105][105][105];
State pre[105][105][105];
string s1,s2,virus;

void getNext()
{
    int j = nxt[0] = -1;
    int i = 0;
    while(i < virus.size())
    {
        while(j != -1 && virus[i] != virus[j])
            j = nxt[j];
        nxt[++i] = ++j;
    }
}

void update(int i,int j,int k,int v,State s)
{
    if(dp[i][j][k] < v)
    {
        dp[i][j][k] = v;
        pre[i][j][k] = s;
    }
}

void track(int i,int j,int k)
{
    State s = pre[i][j][k];
    if(i || j)
        track(s.ii,s.jj,s.kk);
    if(s.ii == i - 1 && s.jj == j - 1)
        putchar(s1[i - 1]);
}
int main()
{
    cin >> s1 >> s2 >> virus;
    getNext();

    memset(dp,-1,sizeof(dp));
    dp[0][0][0] = 0;
    for(int i = 0;i <= s1.size();i++)
    {
        for(int j = 0;j <= s2.size();j++)
        {
            for(int k = 0;k < virus.size();k++)
            {
                if(~dp[i][j][k])
                {
                    update(i + 1,j,k,dp[i][j][k],State(i,j,k));
                    update(i,j + 1,k,dp[i][j][k],State(i,j,k));
                    if(s1[i] == s2[j])
                    {
                        int kk = k;
                        while(kk != -1 && virus[kk] != s1[i])
                            kk = nxt[kk];
                        update(i + 1,j + 1,kk + 1,dp[i][j][k] + 1,State(i,j,k));
                    }
                }

            }
        }
    }

    int ans = 0;
    for(int i = 0;i < virus.size();i++)
        ans = max(ans,dp[s1.size()][s2.size()][i]);

    if(!ans)
        cout << ans << endl;
    else
    {
        for(int i = 0;i < virus.size();i++)
            if(dp[s1.size()][s2.size()][i] == ans)
            {
                track(s1.size(),s2.size(),i);
                break;
            }
    }
    return 0;
}
