#include <iostream>
#include <algorithm>
using namespace std;
int n,a[100],Max;
int main()
{
    Max=0;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        if(a[i]>Max)
        {
            Max=a[i];            
        }        
    }
    sort(a,a+n);
    for(int i=1;i<=n;i++)
    {
        cout<<a[i]; 
    }
    system("pause");
    return 0;    
}
