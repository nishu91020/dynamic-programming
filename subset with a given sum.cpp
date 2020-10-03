//problem statement:we are given an array and an integer sum we need to find out whether an sub-array exist which has sum equal to the given sum.

#include<bits/stdc++.h>
using namespace std;

bool subset_sum(int arr[],int n,int sum)
{
	bool t[n+1][sum+1];
	
    // If sum is 0, then answer is true 
    for (int i = 0; i <= n; i++) 
        t[i][0] = true; 
  
    // If sum is not 0 and set is empty, 
    // then answer is false 
    for (int i = 1; i <= sum; i++) 
        t[0][i] = false; 
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=sum;j++)
		{
			if(arr[i-1]>j)
				t[i][j]=t[i-1][j];
			if(arr[i-1]<=j)
			{
				t[i][j]=(t[i-1][j]) || (t[i-1][j-arr[i-1]]);
			}
			
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
	bool ans=subset_sum(a,n,sum);
	if(ans==true)
		cout<<"there exist a subarray with given sum"<<"\n";
	else
		cout<<"there does not exist a subarray with given sum"<<"\n";
	return 0;
}
