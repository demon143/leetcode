#include<cstdio>
#include<cstring>
#include<vector>
#include<iostream>
using namespace std;
const int maxn=30;
const int maxm=500;
int n;//有效字母数
vector<int> vis;
vector<int> path;
vector<vector<int> > res;
int gragh[7][7] = {
		{0,1,1,0,0,0,0},
		{0,0,0,0,1,0,1},
		{0,0,0,0,0,1,0},
		{1,1,1,0,0,1,1},
		{0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0},
      	{0,0,0,0,1,1,0}};
bool ok(int i,int cnt)//如果在ans[0,cnt-1]出现了一个本应在i后面才出现的字母,那么返回false
{
    for(int j=0;j<cnt;j++)
        if(gragh[i][path[j]]) return false;
    return true;
}
void dfs(int cnt)
{
    if(cnt==n)
    {
        res.push_back(path);
        return;
    }
    else for(int i=0;i<n;i++)if(vis[i] == 0 && ok(i,cnt))
    {
        vis[i]=1;
        path[cnt]=i;
        dfs(cnt+1);
        vis[i]=0;
    }
}
int main()
{
    n=7;
    vis = vector<int> (maxn, 0);
    path = vector<int> (n, 0);
    dfs(0);//表示当前正在构造第0个位置
    for(int i = 0; i < res.size(); i++) {
        for(int j = 0; j < res[0].size(); j++) cout << res[i][j];
        cout << "\n";
    }
    return 0;
}
