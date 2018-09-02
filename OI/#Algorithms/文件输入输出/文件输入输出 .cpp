#include <iostream>
#include <cstdlib>
#include <cstdio>
using namespace std;
int main()
{
    int m,n; 
    FILE *fin=freopen("a.in","r",stdin);//FILE *fin=fopen("a.in","r"); 
    FILE *fout=freopen("a.out","w",stdout);//FILE *fout=fopen("a.out","w"); 
    fscanf(fin,"%d",&n);
    fscanf(fin,"%d",&m);
    fprintf(fout,"%d%d1",m,n);//Êä³ö m,nºÍ1 
    return 0;    
}
//http://www.cnblogs.com/Yogurshine/p/3677201.html
