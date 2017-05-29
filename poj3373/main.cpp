#include <iostream>
#include<cstdio>
#include<algorithm>
#include<string>
#include<vector>
#include<cstring>

using namespace std;

int n,k;
char sequence[105];
int nums[105];
int len;

/*
bool dfs(int remain,int now)
{
    if(!remain)
    {
        int mod = 0;
        for(int i = 0;i < len;i++)
            mod = (mod * 10 + nums[i]) % k;
        if(!mod)
            return true;
        else
            return false;
    }
    if(now + remain > len)
        return false;

    int temp = nums[now];
    bool flag = true;
    for(int i = (now == 0 ? 1 : 0);i <= 9;i++)
    {
        if(i >= temp && flag)
        {
            if(dfs(remain,now + 1))
                    return true;
            flag = false;
        }
        if(i == temp)
            continue;

        nums[now] = i;
        if(dfs(remain - 1,now + 1))
            return true;
        nums[now] = temp;
    }
    return false;
}

void ids()
{
    for(int i = 0;i <= 5;i++)
    {
        if(dfs(i,0))
            break;
    }
}

int main()
{
    while(scanf("%s %d",sequence,&k) != EOF)
    {
        len = strlen(sequence);
        for(int i = 0;i < len;i++)
            nums[i] = sequence[i] - '0';

        ids();
        for(int i = 0;i < len;i++)
            printf("%d",nums[i]);
        putchar('\n');
    }
    return 0;
}*/

