#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e6 + 5;
int n;
char t[MAXN];
int len;

void myitoa(int num,char* dest,int k)
{
    if(num == 0)
    {
        dest[0] = '0',dest[1] = 0;
        return;
    }

    int cursor = 0;
    while(num)
    {
        int now = num % k;
        dest[cursor++] = now <= 9 ? now + '0' : now - 10 + 'A';
        num /= k;
    }

    for(int i = 0;i < cursor / 2;i++)
        swap(dest[i],dest[cursor - 1 - i]);
    dest[cursor] = 0;
}

bool judge(int beginPos,int num,int k)
{
    if(beginPos >= len)
        return true;
    int now = 0;
    for(int i = beginPos;i < len;i++)
    {
        int digit = isalpha(t[i]) ? t[i] - 'A' + 10 : t[i] - '0';
        now = now * k + digit;
        if(now > num || num > n)
            return false;
        else if(now == num)
        {
            if(i == len - 1)
                return true;
            num++;
            now = 0;
        }
    }

    if(num > n)
        return false;

    char temp[20],temp1[20];
    myitoa(now,temp,k);
    myitoa(num,temp1,k);
    int nowLen = strlen(temp);
    for(int i = 0;i < nowLen;i++)
    if(temp[i] != temp1[i])
        return false;
    return true;
}

int main()
{
    scanf("%d",&n);
    scanf("%s",t);
    len = strlen(t);
    int m = 0;
    for(int i = 0;i < len;i++)
    {
        if(isalpha(t[i]))
            t[i] = toupper(t[i]);
        m = max(m,(int)t[i]);
    }

    char temp[20];
    int minK = m > '9' ? (m - 'A') + 11 : (m - '0') + 1;
    for(int i = 1;i <= n;i++)
    {
        for(int k = minK;k <= 16;k++)
        {
            myitoa(i,temp,k);
            int numLen = strlen(temp);
            for(int suffixLen = 1;suffixLen <= numLen;suffixLen++)
            {
                bool vaild = true;
                for(int j = 0;j < suffixLen;j++)
                {
                    if(temp[numLen - suffixLen + j] != t[j])
                    {
                        vaild = false;
                        break;
                    }
                }
                if(!vaild)
                    continue;
                if(judge(suffixLen,i + 1,k))
                    return 0 * printf("yes\n");
            }
        }
    }

    return 0 * printf("no\n");
}
