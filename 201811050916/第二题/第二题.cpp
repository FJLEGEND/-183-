#include <iostream>
#include <vector>
using namespace std;
int main()
{
int m,n,i,t;
cout<<"请输入猴子个数:"<<endl;
cin>>m;
cout<<"请输入每次个数:"<<endl;
cin>>n;
vector<int>a(m);
vector<int>b(m);
for(i=0;i<m;i++)
a[i]=i+1;
while(m!=1)
{
m--;
if(m+1>=n)
{
for(i=0;i<m;i++)
if(i+n<m+1)
b[i]=a[i+n];
else
b[i]=a[i+n-m-1];
for(i=0;i<m;i++)
a[i]=b[i];
}
else
{
t=n%(m+1);
for(i=0;i<m;i++)
if(i+t<m+1)
b[i]=a[i+t];
else
b[i]=a[i+t-m-1];
for(i=0;i<m;i++)
a[i]=b[i];
}
}
cout<<"猴子大王:"<<a[0]<<endl;
return 0;
}