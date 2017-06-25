#include <bits/stdc++.h>

using namespace std;

int maze[55][55];

int main()
{
    int n;
    scanf("%d",&n);
    for(int i = 0;i < n;i++)
        for(int j = 0;j < n;j++)
            scanf("%d",&maze[i][j]);

    for(int i = 0;i < n;i++)
    for(int j = 0;j < n;j++)
    {
        if(maze[i][j] == 1)
            continue;
        bool haveAnswer = false;
        for(int r = 0;r < n;r++)
        {
            for(int c = 0;c < n;c++)
            {
                if(r == i && c == j)
                    continue;
                if(maze[r][j] + maze[i][c] == maze[i][j])
                    haveAnswer = true;
            }
        }
        if(!haveAnswer)
            return 0 * printf("No\n");
    }
    return 0 * printf("Yes\n");
}
