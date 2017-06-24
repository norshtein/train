#include <bits/stdc++.h>

using namespace std;

int n;
double v,u;
double c[1005];
double d[1005];

int main()
{
    cin >> n >> v >> u;
    for(int i = 1;i <= n;i++)
        cin >> c[i];
    for(int i = 1;i <= n;i++)
        cin >> d[i];

    double answer = 0;
    for(int i = 1;i <= n;i++)
    {
        for(int j = 1;j <= n;j++)
        {
            double vnow = c[i] - (j - 1) * d[i];
            answer += n * u / (vnow - v) / n;
        }
    }
    printf("%.3f\n",answer);
    return 0;
}
