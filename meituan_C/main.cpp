#include <bits/stdc++.h>

using namespace std;

int times[100005];

int main()
{
    int m;
    while(scanf("%d",&m) != EOF)
    {
        memset(times,0,sizeof(times));
        char c;
        int temp,buffer = 0,answer = -1;

        for(int i = 1;i <= m;i++)
        {
            scanf(" %c",&c);
            if(c == 'I')
            {
                scanf("%d",&temp);
                if(++times[temp] != 1 && answer == -1)
                    answer = i;
            }
            else if(c == '?')
                buffer++;
            else
            {
                scanf("%d",&temp);
                if(answer == -1)
                {
                    if(times[temp] == 1)
                        --times[temp],times[temp] = -1;
                    else if(buffer && times[temp] == 0)
                        --buffer,times[temp] = -1;
                    else
                        answer = i;
                }
            }
        }
        printf("%d\n",answer);

    }
    return 0;
}
