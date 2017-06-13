#include <bits/stdc++.h>

using namespace std;

const int MAXN = 3005;
int c[MAXN][MAXN];
int dp[MAXN][MAXN];
int R,C,K;
set<pair<int,int> > s;


int get(int x1,int y1,int x2,int y2)
{
    return dp[x2][y2] - dp[x2][y1 - 1] - dp[x1 - 1][y2] + dp[x1 - 1][y1 - 1];
}

int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w+",stdout);
    int T;
    scanf("%d",&T);
    for(int caseNum = 1;caseNum <= T;caseNum++)
    {
        cerr << caseNum << endl;
        memset(c,0,sizeof(c));
        memset(dp,0,sizeof(dp));
        scanf("%d%d%d",&R,&C,&K);

        int a,b;
        for(int i = 0;i < K;i++)
        {
            scanf("%d%d",&a,&b);
            c[++a][++b] = 1;
        }

        for(int i = 1;i <= R;i++)
        {
            for(int j = 1;j <= C;j++)
            {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1] + (c[i][j] == 1);
                //cout << i << ' ' << j << ' ' << dp[i][j] << endl;
            }
        }

        long long answer = 0;

        for(int i = 1;i <= R;i++)
        {
            for(int j = 1;j <= C;j++)
            {
                //if(i % 100 == 0 && j % 100 == 0)
                    //cerr << i << ' ' << j << endl;
                if(c[i][j])
                    continue;

                int x1 = i,y1 = j;

                int l = 1,r = min(R - i + 1,C - j + 1);
                while(l < r)
                {
                    int mid = (l + r + 1) >> 1;
                    int x2 = x1 + mid - 1,y2 = y1 + mid - 1;
                    if(get(x1,y1,x2,y2))
                        r = mid - 1;
                    else
                        l = mid;
                }
                //cout << i << ' ' << j << ' ' << l << endl;
                answer += l;
            }
        }
        printf("Case #%d: %lld\n",caseNum,answer);
    }
    return 0;
}
