#include <iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cstring>
#include<cstdio>
using namespace std;

char s[100];
char temp[3];

int main()
{
    temp[2] = 0;
    while(scanf(" %s",s) != EOF && s[0] != '*')
    {
        int len = strlen(s);
        bool flag = true;
        for(int it = 1;it < len;it++)
        {
            vector<string> v;
            for(int i = 0;i + it < len;i++)
            {
                temp[0] = s[i];
                temp[1] = s[i + it];
                v.push_back(string(temp));
            }
            int vSize = v.size();
            sort(v.begin(),v.end());
            if(v.size() != unique(v.begin(),v.end()) - v.begin())
            {
                flag = false;
                break;
            }
        }
        if(flag)
            printf("%s is surprising.\n",s);
        else
            printf("%s is NOT surprising.\n",s);
    }

    return 0;
}
