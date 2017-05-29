#include <cstdio>
#include<cmath>

using namespace std;

long long gcd(long long a,long long b)
{
    return b == 0 ? a : gcd(b,a % b);
}
int main()
{
    int n;
    while(scanf("%d",&n) && ~n)
    {
        if(!n)
        {
            puts("0");
            continue;
        }

        long long answer = 0;
        for(int i = 1;i <= n;i++)
            answer += pow(3LL,gcd(i,n));
        if(n & 1)
            answer += n * pow(3LL,(n + 1) / 2);
        else
            answer += n / 2 * (pow(3LL,n / 2) + pow(3LL,n / 2 + 1));
        answer /= 2 * n;
        printf("%lld\n",answer);
    }
    return 0;
}
