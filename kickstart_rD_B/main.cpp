#include<bits/stdc++.h>

using namespace std;

const int MAXN = 205;
int x[MAXN],y[MAXN],r[MAXN],s[MAXN];
int N,K,A1,B1,C,D,E1,E2,F;
int A[MAXN],B[MAXN];
vector<int> sumA,sumB;
int prefixA[MAXN],prefixB[MAXN];
int agz,alz,bgz,blz;
const long long INF = 1e15;

void getAB()
{
    x[1] = A1,y[1] = B1,r[1] = 0,s[1] = 0;
    for(int i = 2;i <= N;i++)
    {
        x[i] = (C*x[i - 1] + D * y[i - 1] + E1) % F;
        y[i] = (D*x[i - 1] + C * y[i - 1] + E2) % F;
        r[i] = (C*r[i - 1] + D * s[i - 1] + E1) % 2;
        s[i] = (D*r[i - 1] + C * s[i - 1] + E2) % 2;
    }
    for(int i= 1;i <= N;i++)
    {
        A[i] = x[i] * (r[i] % 2 ? -1 : 1);
        B[i] = y[i] * (s[i] % 2 ? -1 : 1);
        prefixA[i] = prefixA[i - 1] + A[i];
        prefixB[i] = prefixB[i - 1] + B[i];
    }

    for(int i = 1;i <= N;i++)
    for(int j = 1;j <= i;j++)
    {
        sumA.push_back(prefixA[i] - prefixA[j - 1]);
        sumB.push_back(prefixB[i] - prefixB[j - 1]);
    }
    sort(sumA.begin(),sumA.end());
    sort(sumB.begin(),sumB.end());
}

void init()
{
    sumA.clear();
    sumB.clear();
    prefixA[0] = prefixB[0] = 0;
}

int countGreater(long long num)
{
    long long ans = 0;
    if(num <= 0)
    {
        ans += (long long)agz * bgz + (long long)alz * blz;
        for(int i = 0;i < alz;i++)
        {
            long long pivot = num / sumA[i];
            ans += upper_bound(sumB.begin() ,sumB.end(),pivot) - (sumB.begin() + blz);
        }
        for(int i = alz;i < sumA.size();i++)
        {
            if(sumA[i] == 0)
            {
                ans += blz;
                continue;
            }
            long long pivot = num / sumA[i];
            ans += (sumB.begin() + blz) - lower_bound(sumB.begin(),sumB.begin() + blz,pivot);
        }
    }
    else
    {
        for(int i = 0;i < alz;i++)
        {
            long long pivot = num / sumA[i];
            if(num % sumA[i] != 0)
                pivot--;
            ans += upper_bound(sumB.begin(),sumB.begin() + blz,pivot) - sumB.begin();
        }
        for(int i = alz;i < sumA.size();i++)
        {
            if(sumA[i] == 0)
                continue;
            long long pivot = num / sumA[i];
            if(num % sumA[i] != 0)
                pivot++;
            ans += sumB.end() - lower_bound(sumB.begin(),sumB.end(),pivot);
        }
    }
    return ans;
}
int main()
{
    freopen("in.txt","r+",stdin);
    freopen("out.txt","w+",stdout);
    int T;
    scanf("%d",&T);
    for(int caseNum = 1;caseNum <= T;caseNum++)
    {
        cerr<< caseNum << endl;
        scanf("%d%d%d%d%d%d%d%d%d",&N,&K,&A1,&B1,&C,&D,&E1,&E2,&F);
        init();
        getAB();
        alz = lower_bound(sumA.begin(),sumA.end(),0) - sumA.begin();
        blz = lower_bound(sumB.begin(),sumB.end(),0) - sumB.begin();
        agz = sumA.size() - alz;
        bgz = sumB.size() - blz;

        long long l = -INF,r = INF;
        while(l < r)
        {
            long long mid = (l + r + 1) >> 1;
            if(countGreater(mid) >= K)
                l = mid;
            else
                r = mid - 1;
        }
        printf("Case #%d: %I64d\n",caseNum,l);
    }
    return 0;
}
