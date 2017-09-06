#include<bits/stdc++.h>

using namespace std;

int oddCnt = 0,odd = false;

int main()
{
    int n;
    scanf("%d",&n);
    int tmp;
    for(int i = 0;i < n;i++)
    {
        scanf("%d",&tmp);
        if(tmp % 2)
            oddCnt++,odd = !odd;
    }

    if(odd || oddCnt >= 1)
        cout << "First" << endl;
    else
        cout << "Second" << endl;
    return 0;
}
