#include <bits/stdc++.h>

using namespace std;

int main()
{
    int a,b,l,r;
    cin >> a >> b >> l >> r;
    int lBlock = (l - 1) / (a + b);
    int rBlock = (r - 1) / (a + b);
    cout << lBlock << ' ' << rBlock << endl;
    cout << (l - 1) % (a + b) << ' ' << (r - 1) % (a + b) << endl;
    if((l - 1) % (a + b) < a) //落在a 内
    {
        if(lBlock == rBlock && (r - 1) % (a + b) < a)
            return 0 * printf("%d\n",r - l + 1);
        else if(lBlock == rBlock && (r - 1) % (a + b) >= a)
            return 0 * printf("%d\n",a - (l - 1) % (a + b));
        else
        {
            if(lBlock + 1 < rBlock)
                return 0 * printf("%d\n",a + 1);
            else
            {
                if(a - (l - 1) % (a + b) + (r - 1) % (a + b) + 1 < a)
                    return 0 * printf("%d\n",a - (l - 1) % (a + b) + (r - 1) % (a + b) + 1);
                else
                    return 0 * printf("%d\n",a + 1);
                /*
                if((r - 1) % (a + b) < a)
                {
                    if((r - 1) % (a + b) < a - 1)
                        return 0 * printf("%d\n",min(a,a - (l - 1) % (a + b) + (r - 1) % (a + b) + 1));
                    else
                        return 0 * printf("%d\n",a + 1);
                }
                else
                    return 0 * printf("%d\n",a + 1);
                    */
            }
        }
    }
    else //落在b内
    {
        if(lBlock == rBlock)
            return 0 * puts("1");
        else if(lBlock + 1 == rBlock && (r - 1) % (a + b) < a)
            return 0 * printf("%d\n",1 + (r - 1) % (a + b) + 1);
        else
            return 0 * printf("%d\n",a + 1);
    }
    return 0;
}
