//problem statement:we are given a coin array and an amount we need to find minimum no. of coins that can be used to get desired amount
#include<bits/stdc++.h>
using namespace std;

int min_coins(int amt,int n,int arr[])
{
	int t[n+1][amt+1];

	for(int i=0;i<amt+1;i++)
	{
		t[i][0]=INT_MAX-1;
	}

	for(int i=0;i<n+1;i++)
	{
		t[0][i]=0;
	}
	for(int j=1;j<amt+1;j++)
		{
			if(j%arr[0]==0)
				t[0][j]=j/arr[0];
			else
				t[0][j]=INT_MAX-1;
		}
	for(int i=2;i<n+1;i++)
	{for(int j=1;j<amt+1;j++)
		{
			if(arr[i-1]<=j)
				t[i][j]=min(1+arr[i][j-arr[i-1]],arr[i-1][j]);
			else
				t[i][j]=arr[i-1][j];
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
	int x=min_coins(amount,n,arr);
	cout<<"minimum number of ways to get the desired amount= "<<x<<"\n";
	
	return 0;
}
