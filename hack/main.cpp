#include <bits/stdc++.h>

using namespace std;

int main()
{
    srand(time(2333));
    int n = 1000;
    cout << n << endl;
    for(int i = 0;i < n;i++)
    {
        for(int j = 0;j < 5;j++)
            cout << rand() % 999 << " \n"[j == 4];
    }
    return 0;
}
