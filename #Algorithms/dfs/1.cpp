#include <iostream>
using  namespace std;
int num;
int n,L;
int S[100];

int dfs(int cur)   //cur ���ɴ��ĵ�ǰ����λ��
{
	int i;
	if(num==n)   //�������ɵ�n��������� 
	{
		for(i=0;i<cur;i++)   //������� 
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
		bool ok=true;  //�ٶ�curλ�÷�i�����Ƿ�ok 
		for(int j=1; j*2<=cur+1; j++)    //������֤�Ƿ�ok  j��ʾ����Ϊj�Ĵ� 
		{
			int equ=1;
			for(int k=0;k<j;k++)  //����һ���Ƿ����ǰһ��,��Ӧ����ֻҪ��һ���ַ���ͬ�������ǲ�ͬ�� 
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
