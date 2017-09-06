#include <bits/stdc++.h>

using namespace std;

const int MAXN = 3005;
bitset<3005> pre[MAXN], rev[MAXN];

inline int in()
{
    int ch,ans;
    ch = getchar();
    if (-1 == ch) return -1;
    while(ch < '0' || '9' < ch) ch = getchar();
    ans = ch-'0';
    while((ch = getchar()) >= '0' && '9' >= ch) ans = (ans<<3)+(ans<<1)+ch-'0';
    return ans;
}

int main()
{
    int T;
    T = in();

    while (T--)
    {
        int n = in();
        for (int i = 1; i <= n; i++)
            pre[i] = rev[i] = 0;

        int tmp;
        for(int i = 1;i < n ;i++)
        {
            for(int j = 1;j <= n - i;j++)
            {
                tmp = in();
                if(tmp)
                {
                    pre[i][i + j] = 1;
                    pre[i + j][i] = 1;
                }
                else
                {
                    rev[i][i + j] = 1;
                    rev[i + j][i] = 1;
                }
            }
        }

        if(n >= 6)
        {
            puts("Bad Team!");
            continue;
        }

        bool good = true;
        for(int i = 1;i <= n && good;i++)
        {
            for(int j = i + 1;j <= n;j++)
            {
                if(rev[i][j] == 1)
                {
                    if((rev[i] & rev[j]) != 0)
                    {
                        good = false;
                        break;
                    }
                }
                else
                {
                    if((pre[i] & pre[j]) != 0)
                    {
                        good = false;
                        break;
                    }
                }
            }
        }

        puts(good ? "Great Team!" : "Bad Team!");
    }
    return 0;
}
