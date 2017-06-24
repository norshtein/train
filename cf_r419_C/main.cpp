#include <bits/stdc++.h>

using namespace std;

int maze[105][105];
int r[105],c[105];

int main()
{
    int n,m;
    scanf("%d%d",&n,&m);

    bool rev = false;
    if(n <= m)
    {
        for(int i = 0;i < n;i++)
            for(int j = 0;j < m;j++)
                scanf("%d",&maze[i][j]);
    }
    else
    {
        rev = true;
        for(int i = 0;i < n;i++)
            for(int j = 0;j < m;j++)
                scanf("%d",&maze[j][i]);
        swap(n,m);
    }

    for(int i = 0;i < n;i++)
    {
        int minValue = 555;
        for(int j = 0;j < m;j++)
            minValue = min(minValue,maze[i][j]);
        if(minValue)
        {
            r[i] = minValue;
            for(int j = 0;j < m;j++)
                maze[i][j] -= minValue;
        }
    }

    for(int j = 0;j < m;j++)
    {
        int minValue = 555;
        for(int i = 0;i < n;i++)
            minValue = min(minValue,maze[i][j]);
        if(minValue)
        {
            c[j] = minValue;
            for(int i = 0;i < n;i++)
                maze[i][j] -= minValue;
        }
    }

    for(int i = 0;i < n;i++)
        for(int j = 0;j < m;j++)
            if(maze[i][j])
                return 0 * printf("-1\n");

    int total = 0;
    for(int i = 0;i < n;i++)
        total += r[i];
    for(int j = 0;j < m;j++)
        total += c[j];
    printf("%d\n",total);
    for(int i = 0;i < n;i++)
    {
        for(int j = 0;j < r[i];j++)
            printf("%s %d\n",rev ? "col": "row" ,i + 1);
    }
    for(int j = 0;j < m;j++)
    {
        for(int i = 0;i < c[j];i++)
            printf("%s %d\n",rev ? "row":"col" , j + 1);
    }
    return 0;
}
