#include <bits/stdc++.h>

using namespace std;

int n;

int main()
{
    scanf("%d",&n);
    char command[10];
    int num,head,total = 0;
    int required = 1;
    for(int i = 0;i < 2 * n;i++)
    {
        scanf("%s",command);
        if(command[0] == 'a')
            scanf("%d",&num),head = num,total++;
        else
        {
            if(head != required)
            {

            }
        }

    }
    return 0;
}
