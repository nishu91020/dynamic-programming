//problem statment:we need to divide an array into two sub-arrays such that their sum is minimum or
//sum(subset1)-sum(subset2) is min.

#include<bits/stdc++.h>
using namespace std;

bool subset_sum(int arr[],int sum,int n)
{
	bool t[n+1][sum+1];
	for(int i=0;i<n+1;i++)
	{
		for(int j=0;j<sum+1;j++)
		{
			if(i==0) //base condition
				t[i][j]=false;
			if(j==0) //base condition
				t[i][j]=true;
			if(arr[i-1]<=j)
			{
				t[i][j]=(t[i-1][j-arr[i-1]] )||( t[i-1][j]);
			}
			else
				t[i][j]=t[i-1][j];
		}
	}
	return t[n][sum];
}

int min_subset_sum_diff(int arr[],int n)
{
	int sum=0;
	for(int i=0;i<=n;i++)
		sum+=arr[i];
	int s=sum/2;
	int min=INT_MAX;
	for(int i=0;i<=s;i++)
	{
		if(subset_sum(arr,i,n))
		{
			if(sum-(2*i)<min)
				min=i;
		}
	}
	return min;
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
	int ans=min_subset_sum_diff(a,n);
	cout<<"minimum difference of sum of any two subsets of a set is:"<<ans<<"\n";
	return 0;
}
