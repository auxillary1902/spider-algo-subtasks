#include<iostream>
using namespace std;
struct customer
{
	int id,at,t,pr,et;
	
};
int count=0,prev=0;
void fcfs(customer s[], int n)
{
	customer temp,small;
	int i,pos,j,sum=0;
	for(i=0;i<n;i++)
	{
		small=s[i];pos=i;
		for(j=i+1;j<n;j++)
		if(s[j].at<small.at)
		{
		small=s[j];
		pos=j;
	}
	temp=s[i];
	s[i]=small;
	s[pos]=temp;
		
	}
	cout<<endl;
	cout<<"The turnaround time for all customers is :"<<endl;
	
	cout<<"customer     Time"<<endl;
	int m=0,z=0;
	
for(i=0;i<n;i++)
{
	while(s[i].et>m)
	{
		cout<<"   "<<s[i].id<<"         "<<z<<"-"<<z+1<<endl;
		m++;z++;
	}
	m=0;
}
	
	for(i=0;i<n;i++)
	{
		cout<<"Turnaround time for person No. "<<i+1<<" :";
		for(j=0;j<=i;j++)
		sum+=s[j].et;
		cout<<sum-s[i].at;
		cout<<endl;
		sum=0;
	}
}

void roundrobin(customer s[], int n)
{
	customer b[100];
	int i,j,k,m,l,time=0,maxat,out[100],sum=0;
	for(i=0;i<n;i++)
	b[i]=s[i];
	for(i=0;i<n;i++)
	sum+=s[i].et;
	
	customer working;
	working=s[0];
	cout<<"customer      Time"<<endl;
	for(i=s[0].at,j=0;i<=sum;i++,j++)
	{
		
		maxat=s[0].at;
	for(m=0;m<n-count;m++)
	if(s[m].at>maxat)
	maxat=s[m].at;

	if((working.t==i)||(working.t==i-prev))	
	{
		s[working.id-1].at=maxat+1;
		prev+=working.t;
		s[working.id-1].et-=working.t;
			if(s[working.id-1].et==0)
	{
		out[working.id]=time;
			for(k=0;k<n-count;k++)
		if(s[k].id==working.id)
		break;
		for(l=k;l<n-count-1;l++)
		s[l]=s[l+1];
			
		count++;
		
	}
		customer small=s[0];
		for(k=0;k<n-count;k++)
		{
			if((s[k].at<=i)&&(s[k].at<small.at))
			{
			small=s[k];
		
			}
			
			

			
		}
		working=small;
		
	}
	if(i<sum)
	cout<<"     "<<working.id<<"         "<<i<<"-"<<i+1<<endl;

		time++;
		}	
		
	
		cout<<endl;
	cout<<"The turnaround time for each person is:"<<endl;
	for(i=1;i<=n;i++)
	{
		if(b[i-1].id==i)
		cout<<"Turnaround for person number "<<i<<" :"<<out[i]-b[i-1].at<<endl;
		
	}
}
	void priority(customer s[],int n)
	{
		customer b[100];
		
	customer temp,small,working;
	int i,pos,j,sum=0,out[100],time=0,start[100];
	for(i=0;i<n;i++)
	b[i]=s[i];
	
	for(i=0;i<n;i++)
	sum+=s[i].et;
	working=s[0];

for(i=0;i<=n;i++)
start[i]=0;
start[working.id]=2;
	cout<<"customer      "<<"time"<<endl;
	for(i=s[0].at,j=0;i<=sum;i++,j++)
	{ 
	
		if(j>=1)
		{
		int k,l; customer big=s[0];
		
				if(start[working.id]>working.et)
		{
		out[working.id]=time;
		int k,l;
		for(k=0;k<n-count;k++)
		if(s[k].id==working.id)
		break;
		for(l=k;l<n-count-1;l++)
		s[l]=s[l+1];
			
		count++;
	}
	for(k=0;k<n-count;k++)
		{
		if(s[k].at<=i)
		{
			if(s[k].pr>big.pr)
			big=s[k];
		}
			}if(working.pr!=big.pr)
				{
				working=big;
				if(start[working.id]==0)
				start[working.id]=1;
				
			}
				
		start[working.id]++;
	
	}
		
	
	if(i<sum)
	cout<<"     "<<working.id<<"         "<<i<<"-"<<i+1<<endl;
		time++;
	}
	cout<<endl;
	cout<<"The turnaround time for each person is:"<<endl;
	for(i=1;i<=n;i++)
	{
		if(b[i-1].id==i)
		cout<<"Turnaround for person number "<<i<<" :"<<out[i]-b[i-1].at<<endl;
		
	}
	
	}
	
	

int main()
{
	int n,k,p,i;
	customer s[100];
	cin>>n>>k>>p;
	if(p==0)
	{ if(k==-1)
	    {
		cout<<"Enter the customer id,arrival time,time required for each"<<endl;
		for(i=0;i<n;i++)
	     cin>>s[i].id>>s[i].at>>s[i].et;
	     s[i].pr=0;
			}
			else
			{
				cout<<"Enter the customer id,arrival time,time required for each,and the time quantum for each"<<endl;
				for(i=0;i<n;i++)
				cin>>s[i].id>>s[i].at>>s[i].et>>s[i].t;
				s[i].pr=0;
			}
}
else
{
	cout<<"Enter the customer id,arrival time,time required for each,priority of each customer"<<endl;
	for(i=0;i<n;i++)
	cin>>s[i].id>>s[i].at>>s[i].et>>s[i].pr;
}

if((p==0)&&(k==-1))
fcfs(s,n);
else if(p!=0)
priority(s,n);
else if(k!=-1)
roundrobin(s,n);


	return 0;
	
}
