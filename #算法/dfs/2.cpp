#include <iostream>
#include <cstring>
using namespace std;
const int MAXN=1003;

int mat[MAXN][MAXN],vis[MAXN][MAXN];
void dfs(int x, int y)
{
	if(!mat[x][y]||vis[x][y]) return ;
	else
	{
		vis[x][y]=1;
		dfs(x-1,y-1);   dfs(x-1,y);  dfs(x-1,y+1);
		dfs(x,y-1);                  dfs(x,y+1);
		dfs(x+1,y-1);   dfs(x+1,y);  dfs(x+1,y+1);
		return ;
	}
}

int main()
{
	memset(mat,0,sizeof(int)*MAXN*MAXN);
	memset(vis,0,sizeof(int)*MAXN*MAXN);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			cin>>mat[i][j];
		}
	}
	int sum=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(mat[i][j]&&!vis[i][j])
			{
				sum++;
				dfs(i,j);
			}
		}
	}
	cout<<sum<<endl;
	system("pause");
	return 0;
}
