#include <bits/stdc++.h>

using namespace std;

int gcd(int a,int b)
{
    return b == 0 ? a : gcd(b,a % b);
}

bool isNum(double num)
{
    return fabs(num - round(num)) < 1e-6;
}

int main()
{
    int a,b;
    while(scanf("%d%d",&a,&b) != EOF)
    {
        int l = gcd(a,b);
        long long bb = b * l;
        long long delta = a * a - 4 * bb;
        if(delta < 0 || !isNum(sqrt(delta)))
        {
            puts("No Solution");
            continue;
        }
        int num1 = ( a + sqrt(delta)) / 2;
        int num2 = (a - sqrt(delta)) / 2;
        printf("%d %d\n",num2,num1);

    }
    return 0;
}
