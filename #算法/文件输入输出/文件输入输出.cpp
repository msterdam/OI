#include <iostream>
using namespace std;
int main()
{
	int a;
	FILE *fin=fopen("in.txt","r");
	FILE *fout=fopen("out.txt","w");
	fscanf(fin,"%d",&a);
	fprintf(fout,"%d",a);
	system("pause");
	return 0;
}

