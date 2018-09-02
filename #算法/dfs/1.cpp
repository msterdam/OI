#include <iostream>
using  namespace std;
int num;
int n,L;
int S[100];

int dfs(int cur)   //cur 生成串的当前处理位置
{
	int i;
	if(num==n)   //正好生成第n个串，输出 
	{
		for(i=0;i<cur;i++)   //输出方案 
		{
			cout<<(char)(S[i]+'A');
		}
		cout<<endl; 
		return 0;
	}
	num++;
	for(i=0;i<L;i++)
	{
		S[cur]=i;
		bool ok=true;  //假定cur位置放i，看是否ok 
		for(int j=1; j*2<=cur+1; j++)    //进行验证是否ok  j表示长度为j的串 
		{
			int equ=1;
			for(int k=0;k<j;k++)  //检测后一半是否等于前一半,对应串中只要有一个字符不同，串就是不同的 
			{
				if(S[cur-k]!=S[cur-k-j])
				{
					equ=0;
					break;
				}
			}
			if(equ==1)
			{
				ok=false;
				break;
			}
		} 
		if(ok)
		{
			if(dfs(cur+1)==0)
			return 0;
		}
	}
	
	return 1;
}


int main()
{
	num=0;
	cin>>n;
	cin>>L;
	dfs(0);
	system("pause");
	return 0;
}
