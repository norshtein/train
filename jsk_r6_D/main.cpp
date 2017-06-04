#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2e5 + 5;
const int MAXM = 2e5 + 5;

int h[MAXN];
int n,k,m;
pair<int,int> pos[MAXM];
int prefix[MAXN][21];
pair<int,int> s[22];
int top = -1;

int main()
{
    scanf("%d%d",&n,&k);
    for(int i = 1;i <= n;i++)
        scanf("%d",&h[i]);

    scanf("%d",&m);
    for(int i = 0;i < m;i++)
        scanf("%d%d",&pos[i].first,&pos[i].second),prefix[pos[i].first][pos[i].second]++;
    sort(pos , pos + m);

    for(int i = 1;i <= pos[m - 1].first;i++)
    {
        for(int j = 1;j <= 20;j++)
            prefix[i][j] += prefix[i - 1][j];
    }

    long long ans = 0;
    for(int i = 0;i < m;i++)
    {
        int nowX = pos[i].first;
        int nowY = pos[i].second;
        for(int j = 0;j <= top;j++)
        {
            int minValue = s[j].first;
            for(int h = 1;h <= 20;h++)
            {
                int xL = nowX + nowY + h - k - 2 * min(nowY,min(h,minValue));
                xL = max(j == 0 ? 1 : s[j - 1].second + 1,xL);
                int xR = s[j].second;
                if(xL > xR)
                    continue;
                ans += prefix[xR][h] - prefix[xL - 1][h];
            }
        }

        int j = i - 1;
        while(j >= 0 && pos[j].first == pos[i].first && pos[i].second - pos[j].second <= k)
            ans++,j--;
        //cout << "At " << nowX << ' ' << nowY << ' ' << "Ans " << ans << endl;
        if(i + 1 < m && pos[i + 1].first == pos[i].first || i + 1 == m)
            continue;
        int r = pos[i + 1].first;
        for(int j = nowX;j < r;j++)
        {
            while(top >= 0 && s[top].first >= h[j])
                top--;
            s[++top] = make_pair(h[j],j);
        }

    }

    cout << ans <<endl;
    return 0;
}
