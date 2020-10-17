//problem statment: given a maximum amount find the max no. of ways to make up the sum to given max we are provided an array of coins available.
#include<bits/stdc++.h>
using namespace std;

int max_ways(int amt,int n,int arr[])
{
	int t[n+1][amt+1];


	for(int i=0;i<amt+1;i++)
	{
		t[0][i]=0;
	}
		for(int i=0;i<n+1;i++)
	{
		t[i][0]=1;
	}

	for(int i=1;i<n+1;i++)
	{for(int j=1;j<amt+1;j++)
		{
			if(arr[i-1]<=j)
				t[i][j]=t[i][j-arr[i-1]]+t[i-1][j];
			else
				t[i][j]=t[i-1][j];
		}		
	}
	return t[n][amt];
}
int main()
{
	int amount;
	int n;
	cout<<"enter amount"<<"\n";
	cin>>amount;
	cout<<"enter no of elements in coin array"<<"\n";
	cin>>n;
	int arr[n];
	cout<<"enter coins that can be used"<<"\n";
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	int x=max_ways(amount,n,arr);
	cout<<"max. no. of coins that can be used to get desired amount= "<<x<<"\n";
	return 0;
}
