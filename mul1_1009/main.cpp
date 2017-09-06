#include<bits/stdc++.h>

using namespace std;

const int MAXN = 1005;
const int MAXK = 1e5 + 5;
int n;
vector<pair<int,int> > e[MAXN];

bool instack[MAXN];
int dfn[MAXN],cnt;
stack<int> st;
unsigned res[MAXK];
unsigned tmp[MAXK];

void mmerge(unsigned* A,unsigned* B)
{

}

void tarjan(int u,int fa)
{
    dfn[u] = ++cnt;
    st.push(u);
    instack[u] = true;
    for(auto p:e[u])
    {
        int v = p.first;
        if(v == fa)
            continue;

        if(!dfn[v])
            tarjan(v,u);
        else if(instack[v])
        {
            tmp[0] = 0;
            while(!st.empty() && st.top() != v)
            {
                tmp[++tmp[0]] = st.top();
                instack[st.top()] = false;
                st.pop();
            }
            mmerge(res,tmp);
        }
    }
}
int main()
{
    int caseNum = 0;
    while(scanf("%d",&n) != EOF)
    {
        while(!st.empty())
            st.pop();
    }
    return 0;
}
