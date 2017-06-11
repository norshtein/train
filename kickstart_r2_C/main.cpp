#include <bits/stdc++.h>

using namespace std;

bool check(int n,int base)
{
    int now = 0;
    int pre = 1;
    while(now < n)
    {
        now += pre;
        pre *= base;
    }
    if(now == n)
        return true;
    else
        return false;

}

int check(long long num,int times,long long N)
{
    long long now = 1;
    long long temp = num;
    for(int i = 1;i <= times;i++)
    {
        if(now >= N)
            return 0;
        now += temp;
        temp *= num;
    }

    if(now == N)
        return 1;
    else if(now < N)
        return -1;
    return 0;
}
int main()
{
    freopen("in1.txt","r",stdin);
    freopen("out11.txt","w+",stdout);
    int T;
    cin >> T;
    for(int caseNum = 1;caseNum <= T;caseNum++)
    {
        long long N;
        cin >> N;
        long long answer = 0;
        for(int times = 63;times >= 1 && answer == 0;times--)
        {
            double r = pow(N,1.0 / times);
            for(long long num = floor(r);num > 1;num--)
            {
                int temp;
                if((temp = check(num,times,N)) == 1)
                {
                    answer = num;
                    //cout << times << endl;
                    break;
                }
                else if(temp == -1)
                    break;
            }
        }

        if(answer == 0)
            answer = N - 1;
        printf("Case #%d: %lld\n",caseNum,answer);

    }

    return 0;
}
