//problem statement:we need to insert an operation + or - in front of each element of the gin array such that we get the desired sum
//we need to find in how many ways this can be done

#include<bits/stdc++.h>
using namespace std;
int count_of_subset_sum(int arr[],int n,int sum)
{
	int t[n+1][sum+1];
	memset(t,0,sizeof(t));
	for(int i=0;i<=n;i++)
		t[0][i]=1;
	for(int i=1;i<=sum;i++)
		t[i][0]=0;
	for(int i=1;i<n+1;i++)
	{
		for(int j=1;j<sum+1;j++)
		{
			if(arr[i-1]<=j)
				t[i][j]=t[i-1][j-arr[i-1]]+t[i-1][j];
			if(arr[i-1]>j)
				t[i][j]=t[i-1][j];
				
		}
	}
	return t[n][sum];
}
int target_sum(int arr[],int n,int sum)
{
	int s=0;
	for(int i=0;i<n;i++)
		s+=arr[i];
	int q=(sum+s)/2;
	int f=count_of_subset_sum(arr,n, q);
	return f;
}
int main()
{
	int n;
	cout<<"enter no. of elements you want to create array"<<"\n";
	cin>>n;
	int a[n];
	cout<<"enter elements of array"<<"\n";
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	int sum;
	cout<<"enter the sum"<<"\n";
	cin>>sum;
	int x=target_sum(a,n,sum);
	cout<<"no. of ways to get the target sum="<<x<<"\n";
	
}
