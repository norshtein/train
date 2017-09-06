#include<bits/stdc++.h>

using namespace std;

int dight[40],tmp[40];
long long dp[40][40][100][100];

long long dfs(int start,int pos,int s,bool limit,int k)
{
    if(pos<0)
        return s;
    if(!limit&&dp[k][pos][s][start]!=-1)
        return dp[k][pos][s][start];
    int end;
    long long ret=0;
    if(limit)
        end=dight[pos];
    else
        end=k - 1;
    for(int d=0; d<=end; ++d)
    {
        tmp[pos]=d;
        if(start==pos&&d==0)
            ret+=dfs(start-1,pos-1,s,limit&&d==end,k);
        else if(s&&pos<(start+1)/2)
            ret+=dfs(start,pos-1,tmp[start-pos]==d,limit&&d==end,k);
        else
            ret+=dfs(start,pos-1,s,limit&&d==end,k);
    }
    if(!limit)
        dp[k][pos][s][start]=ret;
    return ret;
}
long long solve(long long a,int k)
{
    memset(dight,0,sizeof(dight));
    int cnt=0;
    while(a!=0)
    {
        dight[cnt++]=a%k;
        a/=k;
    }
    return dfs(cnt-1,cnt-1,1,1,k);
}
int main()
{
    memset(dp,-1,sizeof(dp));
    int t,caseNum=1;
    scanf("%d",&t);
    while(t--)
    {
        int L,R,l,r;
        long long ans = 0;
        scanf("%d%d%d%d",&L,&R,&l,&r);
        for(int i = l;i <= r;i++)
        {
            int cnt = solve(R,i) - solve(L - 1,i);
            ans += R - L + 1 + (long long)cnt * (i - 1);
        }
        printf("Case #%d: %lld\n",caseNum++,ans);
    }
    return 0;
}
