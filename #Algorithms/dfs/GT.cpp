//ZOJ 1008 Gnome Tetravex 搜索(DFS)
/*
数据:

每个小square里面有4个小triangle.用一个iSquare[25][4]的数组存放最多25种可能的小square。

如果有重复的，可以用iCount[25]数组记录。每添加一个不同的iSquare，iCount++。

用一个iTable[25]数组，记录n*n个位置，能放置的小quare。

算法：

搜索的话用DFS，对每个位置测试。

测试能否放置需要再添加一个函数 ， Place(int iPos).根据iPos的值，判断小triangle里面的数字是否匹配。
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
    for(i=0;i<q;i++)   //放置q个卡片
    {
        if(iCount[i]==0) continue;
        if(iPos%n!=0)  //当前是否为第一列
        {
           if(iSquare[iTable[iPos-1]][1]!=iSquare[i][3])  //当前的左侧（当前不是第一列）是否等于前一个的右侧
           continue;
        }
        if(iPos>=n) //当前是否为第一行
        {
           if(iSquare[iTable[iPos-n]][2]!=iSquare[i][0])  //当前的上部（当前不是第一行）是否等于上一个的下部
           continue;
        }
        iTable[iPos]=i;  //第i个卡片放置iPos位置
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
           for(j=0;j<q;j++)//将方格判重，相同的归为一类，这样在搜索时相同的方格不会搜索多次。
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
       //DFS从第一个位置搜索
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
