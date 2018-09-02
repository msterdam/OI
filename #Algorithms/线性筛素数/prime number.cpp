#include <iostream>
#include <memory.h>
using namespace std;
int n,m;
bool vis[10000000];
int pri[10000000];
int top=0;
int main()
{
    memset(vis,false,sizeof(vis));
    cin>>n>>m;
    for(int i=2;i<=n;i++)
    {
        if(vis[i]==false)
        {
            top++;
            pri[top]=i;
            for(int j=1;pri[j]*i<=n && j<=top;j++)
                vis[pri[j]*i]=true;
        }
        else
        {
            for(int j=1;pri[j]*i<=n && j<=top;j++)
                vis[pri[j]*i]=true;
        }        
    }
    for(int i=1;i<=m;i++)
    {
        int t;
        cin>>t;
        if(t==1)
            cout<<"No"<<endl;
        else if(vis[t]==true)
            cout<<"No"<<endl;                
        else
            cout<<"Yes"<<endl;    
    }
    system("pause");
    return 0;    
}
