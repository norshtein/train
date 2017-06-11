#include <bits/stdc++.h>

using namespace std;

const int MAXN = 5e5 + 5;
int N,L1,R1,A,B,C1,C2,M;
pair<int,int> interval[MAXN];
vector<int> nums;
int numCnt;


int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w+",stdout);
    int T;
    scanf("%d",&T);
    for(int caseNum = 1;caseNum <= T;caseNum++)
    {
        scanf("%d%d%d%d%d%d%d%d",&N,&L1,&R1,&A,&B,&C1,&C2,&M);
        int prex = interval[0].first = L1;
        int prey = interval[0].second = R1;
        //nums.push_back(L1);
        //nums.push_back(R1);
        for(int i = 1;i < N;i++)
        {
            interval[i].first = ((long long)A * prex + (long long)B*prey + C1) % M;
            interval[i].second = ((long long)A * prey + (long long)B*prex + C2) % M;
            prex = interval[i].first;
            prey = interval[i].second;
            if(interval[i].first > interval[i].second)
                swap(interval[i].first,interval[i].second);
            //nums.push_back(interval[i].first);
            //nums.push_back(interval[i].second);
            //cout << interval[i].first << ' ' << interval[i].second << endl;
        }

        //sort(nums.begin(),nums.end());
        //numCnt = unique(nums.begin(),nums.end()) - nums.begin();
        sort(interval,interval + N);
        //for(int i = 0;i < N;i++)
            //cout << interval[i].first << ' ' << interval[i].second << endl;
        int ans = 2e9;
        //Ã¶¾ÙÈ¥µôµÄ
        for(int dis = 0;dis < N;dis++)
        {
            int now = 0;
            int pre = -1;
            for(int i = 0;i < N;i++)
            {
                if(i == dis)
                    continue;
                if(interval[i].first > pre)
                {
                    now += interval[i].second - interval[i].first + 1;
                    pre = interval[i].second;
                }
                else if(interval[i].second > pre)
                {
                    now += interval[i].second - pre;
                    pre = interval[i].second;
                }
            }
            ans = min(ans,now);
        }
        printf("Case #%d: %d\n",caseNum,ans);
    }
    return 0;
}
