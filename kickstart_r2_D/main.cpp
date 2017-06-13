#include <bits/stdc++.h>

using namespace std;

const int MAXN = 5e5 + 5;
int N,L1,R1,A,B,C1,C2,M;
pair<int,int> interval[MAXN];
vector<int> nums;
int numCnt;
int prefix[MAXN * 2 + 5];
int len[MAXN * 2 + 5];
int pre[MAXN * 2 + 5];

int getId(int num)
{
    return lower_bound(nums.begin(),nums.end(),num) - nums.begin();
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
        nums.clear();
        memset(prefix,0,sizeof(prefix));
        memset(len,0,sizeof(len));
        memset(pre,0,sizeof(pre));

        scanf("%d%d%d%d%d%d%d%d",&N,&L1,&R1,&A,&B,&C1,&C2,&M);
        int prex = interval[0].first = L1;
        int prey = interval[0].second = R1;
        interval[0].second++;
        nums.push_back(L1);
        nums.push_back(R1 + 1);
        for(int i = 1;i < N;i++)
        {
            interval[i].first = ((long long)A * prex + (long long)B*prey + C1) % M;
            interval[i].second = ((long long)A * prey + (long long)B*prex + C2) % M;
            prex = interval[i].first;
            prey = interval[i].second;
            if(interval[i].first > interval[i].second)
                swap(interval[i].first,interval[i].second);
            nums.push_back(interval[i].first);
            nums.push_back(++interval[i].second);
            //cout << interval[i].first << ' ' << interval[i].second << endl;
        }
        nums.push_back(0);

        sort(nums.begin(),nums.end());
        numCnt = unique(nums.begin(),nums.end()) - nums.begin();
        nums.resize(numCnt);
        sort(interval,interval + N);

        //for(int i = 0;i < N;i++)
            //cout << interval[i].first << ' ' << interval[i].second << endl;
        for(int i = 0;i < numCnt - 1;i++)
        {
            len[i] = nums[i + 1] - nums[i];
            //cout << nums[i] << ' ' << nums[i + 1] << ' '  << len[i] << endl;
        }

        for(int i = 0;i < N;i++)
        {
            prefix[getId(interval[i].first)] += 1;
            prefix[getId(interval[i].second)] -= 1;
        }

        int now = prefix[0];
        pre[0] = 0;
        for(int i = 1;i < numCnt;i++)
        {
            pre[i] += pre[i - 1];
            if(now == 1)
                pre[i] += len[i - 1];
            now += prefix[i];
            //cout << i << ' ' << pre[i] << endl;
        }

        int totalLen = 0;
        int justNow = -1;
        for(int i = 0;i < N;i++)
        {
            if(interval[i].first >= justNow)
            {
                totalLen += interval[i].second - interval[i].first;
                justNow = interval[i].second;
            }
            else if(interval[i].second > justNow)
            {
                totalLen += interval[i].second - justNow;
                justNow = interval[i].second;
            }
        }
        //cout << totalLen << endl;

        int ans = 2e9;
        //Ã¶¾ÙÈ¥µôµÄ
        for(int dis = 0;dis < N;dis++)
        {
            int l = getId(interval[dis].first);
            int r = getId(interval[dis].second);
            ans = min(ans,totalLen - pre[r] + pre[l]);
        }
        printf("Case #%d: %d\n",caseNum,ans);
    }
    return 0;
}
