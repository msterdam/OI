#include <iostream>
#include <algorithm>
using namespace std;
int map[200][200],me[200][200];
int m,n;
int dfs(int x,int y)
{
    if(x>m || y>n || x<1 || y<1)
    {
        return 0;        
    }
    if(me[x][y]!=-1)
    {
        return me[x][y];        
    }
    int a=1,b=1,c=1,d=1;
    if(map[x+1][y]<map[x][y]) a=dfs(x+1,y)+1;
    if(map[x-1][y]<map[x][y]) b=dfs(x-1,y)+1;
    if(map[x][y+1]<map[x][y]) c=dfs(x,y+1)+1;
    if(map[x][y-1]<map[x][y]) d=dfs(x,y-1)+1;
    int f;
    f=max(max(a,b),max(c,d));
    me[x][y]=f;
    return f;
}
int main()
{
    for(int i=1;i<=199;i++)
    {
        for(int j=1;j<=199;j++)
        {
            me[i][j]=-1;
		    map[i][j]=1<<31;    
        }        
    }
    cin>>m>>n;
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cin>>map[i][j];        
        }        
    }
    /*for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cout<<dfs(i,j)<<" ";       
        }        
        cout<<endl;
    }*/
    int Max=0;
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
        {
		    int t;
			t=dfs(i,j);
		    if(t>Max) Max=t;
        }
    }
    cout<<Max<<endl;;
    return 0;    
}
