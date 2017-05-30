#include <bits/stdc++.h>

int nnext[155][3];
int dp[155][55][55][55];
const int mod = 51123987;

using namespace std;

void add(int& a,int b)
{
    a = (a + b) % mod;
}

int main()
{
    int n;
    string s;
    cin >> n >> s;

    for(int j = 0;j < 3;j++)
        nnext[n][j] = n;
    for(int i = s.size() - 1;~i;i--)
    {
        for(int j = 0;j < 3;j++)
            nnext[i][j] = nnext[i + 1][j];
        nnext[i][s[i] - 'a'] = i;
    }

    int ans = 0;
    dp[0][0][0][0] = 1;
    for(int i = 0;i < n;i++)
    {
        for(int a = 0;a * 3 <= n + 2;a++)
        {
            for(int b = 0;b * 3 <= n + 2;b++)
            {
                for(int c = 0;c * 3 <=n + 2 && a + b + c <= n;c++)
                {
                    if(dp[i][a][b][c])
                    {
                        if(a + b + c == n && abs(b - c) <= 1 && abs(a - b) <= 1 && abs(a - c) <= 1)
                            add(ans,dp[i][a][b][c]);
                        add(dp[nnext[i][0]][a+1][b][c],dp[i][a][b][c]);
                        add(dp[nnext[i][1]][a][b+1][c],dp[i][a][b][c]);
                        add(dp[nnext[i][2]][a][b][c+1],dp[i][a][b][c]);
                    }
                }
            }
        }
    }

    cout << ans << endl;
    return 0;
}
