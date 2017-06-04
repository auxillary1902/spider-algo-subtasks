//subtask 1- simulating all the 3 different proposals for curtain sizes
#include<iostream>
using namespace std;
int count=0;
void alterjasmine(int a[],int n, int p)
{
int i,b[100],j=0,large,k;
for(i=n-1;i>=0;i--)
{
if(a[i]>=p)
{
	b[j]=a[i];
	j++;count++;
}}

if(count>0)
{
large=b[0];
for(k=0;k<j;k++)
if(b[k]>large)
large=b[k];

for(i=n-1;i>=0;i--)
if(a[i]==large)
break;

a[i]=a[i]-p;

}
}

void alterkamal(int a[],int n, int p)
{
int i,b[100],j=0,small,k;
for(i=n-1;i>=0;i--)
{
if(a[i]>=p)
{
	b[j]=a[i];
	j++;
	count++;
}}

if(count>0)
{
small=b[0];
for(k=0;k<j;k++)
if(b[k]<small)
small=b[k];

for(i=n-1;i>=0;i--)
if(a[i]==small)
break;

a[i]=a[i]-p;
	
}

	
}


void altershobha(int a[], int p, int n)
 {
 	int i;
 	for(i=n-1;i>=0;i--)
 	 {
 	 	if(a[i]>=p)
 	 	break;
	  }
	  a[i]=a[i]-p;
	  if(i!=-1)
	  count++;
	  
	  
 } 
 
 
void display(int a[],int n)
{ if(count>0)
	{
			int i;
	for(i=0;i<n;i++)
	cout<<a[i]<<" ";
	cout<<endl;
	count=0;
}
else
cout<<-1<<endl;
}
 int main()
 {
 	int a[100],n,p[100],q,i,b[100],c[100];
 	
	 cin>>n;
	 
	 for(i=0;i<n;i++)
	 cin>>a[i];
	 for(i=0;i<n;i++)
	{
	  b[i]=a[i];
	  c[i]=a[i];
}
	
	 cin>>q;
	 
	 for(i=0;i<q;i++)
	 {
      cin>>p[i];
      
      
	 }
	 cout<<endl;
	 cout<<"Shobha :"<<endl;
	 for(i=0;i<q;i++)
	 {
	 	altershobha(c,p[i],n);
	 	display(c,n);
	 }
	 cout<<"Kamal :"<<endl;
	 for(i=0;i<q;i++)
	 {
	 	alterkamal(b,n,p[i]);
	 	display(b,n);
	 }
	 
	 cout<<"Jasmine :"<<endl;
	 for(i=0;i<q;i++)
	 {
	 	alterjasmine(a,n,p[i]);
	 	display(a,n);
	 }
	 
	 
	 
	 return 0;
	  }
