#include <iostream>
using namespace std;
int n,m;
int pre[10001];
int find(int r)
{
	if(pre[r]!=r) 
	{
		int a=find(pre[r]);
		pre[r]=a;
	    return a;
	}
}
void join(int x,int target)
{
	pre[find(x)]=find(target);//important
}
void start()
{
    for(int i=0;i<10001;i++)
    {
	    pre[i]=i;
    }
}
int main()
{
	start();
	scanf("%d %d",&n,&m);
	for(int i=1;i<=m;i++)
	{
        int type,x,y;
        scanf("%d %d %d",&type,&x,&y); 
        if(type==2)
        {
		    if(find(x)==find(y)) printf("Y\n");
		    else printf("N\n");
		}
		if(type==1)
		{
		    join(x,y);
		}
    }
    return 0;	
} 
