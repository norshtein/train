#include<bits/stdc++.h>

using namespace std;

typedef pair<int,int> PII;

struct Node{
    PII pos;
    int s;
    int step;
    Node(int _ = 0,int __ = 0,int ___ = 0,int ____ = 0):pos(_,__),s(___),step(____){}
};

map<pair<PII,int>,int> visited;
const int MAXN = 105;
char maze[MAXN][MAXN];
PII start;
PII dest;
int dX[] = {-1,1,0,0};
int dY[] = {0,0,-1,1};
int M,N;

int bfs()
{
    visited[make_pair(start,0)] = true;
    queue<Node> q;
    q.push(Node(start.first,start.second,0,0));
    while(!q.empty())
    {
        Node now = q.front();
        q.pop();
        for(int i = 0;i < 4;i++)
        {
            int nextX = now.pos.first + dX[i];
            int nextY = now.pos.second + dY[i];
            if(nextX < 0 || nextY < 0 || nextX >= M || nextY >= N || maze[nextX][nextY] == '0')
                continue;

            if(isupper(maze[nextX][nextY]) && ((now.s >> (maze[nextX][nextY] - 'A')) & 1) == 0)
                continue;

            int nextS = islower(maze[nextX][nextY]) ? (now.s | (1 << (maze[nextX][nextY] - 'a'))) : now.s;
            if(visited[make_pair(make_pair(nextX,nextY),nextS)])
                continue;

            if(nextX == dest.first && nextY == dest.second)
                return now.step + 1;

            q.push(Node(nextX,nextY,nextS,now.step + 1));
            visited[make_pair(make_pair(nextX,nextY),nextS)] = 1;
        }
    }

}
int main()
{
    scanf("%d%d",&M,&N);

    for(int i = 0;i < M;i++)
    {
        for(int j = 0;j < N;j++)
        {
            scanf(" %c",&maze[i][j]);
            if(maze[i][j] == '2')
                start = make_pair(i,j);
            if(maze[i][j] == '3')
                dest = make_pair(i,j);
        }
    }
    cout << bfs() << endl;
    return 0;
}
