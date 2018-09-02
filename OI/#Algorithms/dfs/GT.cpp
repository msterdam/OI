//ZOJ 1008 Gnome Tetravex ����(DFS)
/*
����:

ÿ��Сsquare������4��Сtriangle.��һ��iSquare[25][4]�����������25�ֿ��ܵ�Сsquare��

������ظ��ģ�������iCount[25]�����¼��ÿ���һ����ͬ��iSquare��iCount++��

��һ��iTable[25]���飬��¼n*n��λ�ã��ܷ��õ�Сquare��

�㷨��

�����Ļ���DFS����ÿ��λ�ò��ԡ�

�����ܷ������Ҫ�����һ������ �� Place(int iPos).����iPos��ֵ���ж�Сtriangle����������Ƿ�ƥ�䡣
*/

#include <stdio.h>
#include <iostream>
using namespace std;
int n;
int q;
int iSquare[25][4];
int iCount [25];
int iTable[25];

int Place(int iPos)
{
    int i;
    if(iPos==n*n) return 1;
    for(i=0;i<q;i++)   //����q����Ƭ
    {
        if(iCount[i]==0) continue;
        if(iPos%n!=0)  //��ǰ�Ƿ�Ϊ��һ��
        {
           if(iSquare[iTable[iPos-1]][1]!=iSquare[i][3])  //��ǰ����ࣨ��ǰ���ǵ�һ�У��Ƿ����ǰһ�����Ҳ�
           continue;
        }
        if(iPos>=n) //��ǰ�Ƿ�Ϊ��һ��
        {
           if(iSquare[iTable[iPos-n]][2]!=iSquare[i][0])  //��ǰ���ϲ�����ǰ���ǵ�һ�У��Ƿ������һ�����²�
           continue;
        }
        iTable[iPos]=i;  //��i����Ƭ����iPosλ��
        iCount[i]--;
        if(Place(iPos+1)==1) return 1;
        iCount[i]++;
    }
    return 0;
}
int main()
{
    int i,j;
    int iCase=0;
    int top,right,bottom,left;
    while(scanf("%d",&n)&&n)
    {
       iCase++;
       q=0;
       for(i=0;i<n*n;i++)
       {
           cin>>top;
           cin>>right;
           cin>>bottom;
           cin>>left;
           for(j=0;j<q;j++)//���������أ���ͬ�Ĺ�Ϊһ�࣬����������ʱ��ͬ�ķ��񲻻�������Ρ�
           {
               if(iSquare[j][0]==top&&iSquare[j][1]==right&&
               iSquare[j][2]==bottom&&iSquare[j][3]==left)
               {
                   iCount[j]++;
                   break;
               }
           }
           if(j==q)
           {
                   iSquare[j][0]=top;
                   iSquare[j][1]=right;
                   iSquare[j][2]=bottom;
                   iSquare[j][3]=left;
                   iCount[j]=1;
                   q++;
           }
       }
       if(iCase>1) cout<<endl;
       //DFS�ӵ�һ��λ������
       if(Place(0)==1)
       {
           cout<<"Game "<<iCase<<":"<<"YES"<<endl;
       }
       else
       {
           cout<<"Game "<<iCase<<":"<<"NO"<<endl;
       }
    }
    return 0;
}
