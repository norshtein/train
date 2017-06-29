#include <bits/stdc++.h>

using namespace std;

bool isNum(double a)
{
    return fabs(a - round(a)) < 1e-6;
}
int mygcd(int a,int b)
{
    return b == 0 ? a : mygcd(b,a % b);
}
int main()
{
    int a,b;
    vector<int> factor;
    while(scanf("%d%d",&a,&b) != EOF)
    {
        factor.clear();
        int bound = sqrt(a);
        for(int i = bound;i >= 2;i--)
        {
            if(a % i == 0)
                factor.push_back(a / i);
        }

        bool f = false;
        for(int gcd = 1;gcd <= bound;gcd++)
        {
            long long mul = (long long)b * gcd;
            long long delta = a * a - 4 * mul;
            if(delta < 0 || !isNum(sqrt(delta)))
                continue;
            int num1 = (a + sqrt(delta)) / 2;
            int num2 = (a - sqrt(delta)) / 2;
            int ggcd = mygcd(num1,num2);
            if(ggcd != gcd)
                continue;
            printf("%d %d\n",num2,num1);
            f = true;
            break;
        }

        if(!f)
        {
            for(int i = 0;i < factor.size();i++)
            {
                int num1 = factor[i];
                int num2 = a - num1;
                //cout << num1 << ' ' << num2 << endl;
                if((long long)num1 / mygcd(num1,num2) * num2 != b)
                    continue;
                printf("%d %d\n",num1,num2);
                f = true;
                break;
            }
        }
        if(!f)
            puts("No Solution");
    }
    return 0;
}
