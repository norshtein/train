#include <bits/stdc++.h>

using namespace std;

int row[60];
int col[60];
char maze[60][60];

int main()
{
    freopen("in.txt","r+",stdin);
    freopen("oout.txt","w+",stdout);
    int T;
    scanf("%d",&T);
    for(int caseNum = 1;caseNum <= T;caseNum++)
    {
        memset(row,0,sizeof(row));
        memset(col,0,sizeof(col));
        memset(maze,0,sizeof(maze));
        int N;
        scanf("%d",&N);
        for(int i = 0;i < N;i++)
        for(int j = 0;j < N;j++)
        {
            char temp;
            scanf(" %c",&temp);
            maze[i][j] = temp;
            if(temp == 'X')
                row[i]++,col[j]++;
        }

        bool vaild = true;
        bool rowOnce = false,colOnce = false;
        int rr,cc;
        for(int i = 0;i < N;i++)
        {
            if(row[i] == 1)
            {
                if(!rowOnce)
                    rowOnce = true,rr = i;
                else
                {
                    vaild = false;
                    break;
                }
            }
            else if(row[i] != 2)
            {
                vaild =false;
                break;
            }

            if(col[i] == 1)
            {
                if(!colOnce)
                    colOnce = true,cc = i;
                else
                {
                    vaild = false;
                    break;
                }
            }
            else if(col[i] != 2)
            {
                vaild = false;
                break;
            }
        }

        vaild &= rowOnce & colOnce;
        if(vaild)
            printf("Case #%d: POSSIBLE\n",caseNum);
        else
            printf("Case #%d: IMPOSSIBLE\n",caseNum);
    }
    return 0;
}
