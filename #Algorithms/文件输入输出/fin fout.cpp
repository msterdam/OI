#include <iostream>
#include <fstream>
using namespace std;
int main()
{
    ifstream fin("input.txt");
    ofstream fout("output.txt");
    int a;
    fin>>a;
    fout<<a;   
    char b[10];
    fin>>b;
    fout<<b;
    return 0;
}
//http://www.cnblogs.com/xingma0910/archive/2012/11/18/2775496.html
