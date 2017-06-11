#include <bits/stdc++.h>

using namespace std;

const int MAXN = 3005;
int c[MAXN][MAXN];
int R,C,K;
set<pair<int,int> > s;

int lowbit(int x)
{
    return x & -x;
}

void update(int x,int y,int delta)
{
    for(int i = x;i <= R;i += lowbit(i))
        for(int j = y;j <= C;j += lowbit(j))
            c[i][j] += delta;
}

int getSum(int x,int y)
{
    int ans = 0;
    for(int i = x;i;i -= lowbit(i))
        for(int j = y;j;j -= lowbit(j))
            ans += c[i][j];
    return ans;
}

int get(int x1,int y1,int x2,int y2)
{
    return getSum(x2,y2) - getSum(x2,y1 - 1) - getSum(x1 - 1,y2) + getSum(x1 - 1,y1 - 1);
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
        s.clear();
        scanf("%d%d%d",&R,&C,&K);

        int a,b;
        for(int i = 0;i < K;i++)
        {
            scanf("%d%d",&a,&b);
            update(++a,++b,1);
            s.insert(make_pair(a,b));
        }

        long long answer = 0;

        for(int i = 1;i <= R;i++)
        {
            for(int j = 1;j <= C;j++)
            {
                if(i % 100 == 0 && j % 100 == 0)
                    cerr << i << ' ' << j << endl;
                if(s.count(make_pair(i,j)))
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
