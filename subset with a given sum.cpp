//problem statement:we are given an array and an integer sum we need to find out whether an sub-array exist which has sum equal to the given sum.

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
	bool ans=subset_sum(a,sum,n);
	if(ans==true)
		cout<<"there exist a subarray with given sum"<<"\n";
	else
		cout<<"there does not exist a subarray with given sum"<<"\n";
	return 0;
}
