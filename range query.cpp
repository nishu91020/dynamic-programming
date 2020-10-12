#include<bits/stdc++.h>
using namespace std;
int b[6]={0};
int queryupdate(int arr[],int l,int r,int val)
{
	b[l]+=val;
	b[r+1]-=val;
	
}
int main()
{	int l,r,x,ans;
	int arr[]={1,2,3,4,5};
	
	do{
	
	cout<<"enter left limit"<<"\n";
	cin>>l;
	cout<<"enter right limit"<<"\n";
	cin>>r;
	cout<<"enter value to update"<<"\n";
	cin>>x;
	queryupdate(arr,l,r,x);
	cout<<"want to try once more?"<<"\n";
	cin>>ans;
	}while(ans==1);
  /*for(int i=0;i<5;i++)
	{
		arr[i]+=b[i];
	}*/
	for(int i=1;i<5;i++)
	{
		b[i]+=b[i-1];
	}
	for(int i=0;i<5;i++)
	{ 
		arr[i]+=b[i];
	}
	for(int i=1;i<5;i++)
	{ 
		arr[i]+=arr[i-1];
	}
	for(int i=0;i<5;i++)
	{ cout<<arr[i]<<" ";}
	return 0;
}
