//problem statment: given a maximum amount and an array of coins we need to find minimum no. of coins needed to get the desired amount.
#include<bits/stdc++.h>
using namespace std;
int minimum_coins(int amt,int n,int coin[])
{
	int t[n+1][amt+1];
	for(int i=0;i<amt+1;i++)
	{
		t[0][i]=INT_MAX-1;
	}
	for(int i=1;i<n+1;i++)
	{
		t[i][0]=0;
	}
	
	for(int j=1;j<=amt;j++)
	{
		if(j%coin[0]==0)
			t[1][j]=j/coin[0];
		else
			t[1][j]=INT_MAX-1;
	}
	for(int i=2;i<=n;i++)
	{
		for(int j=1;j<=amt;j++)
		{
			if(coin[i]<=j)
			t[i][j]=min(1+t[i][j-coin[i-1]],t[i-1][j]);
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
	int x=minimum_coins(amount,n,arr);
	cout<<"minimum no. of coins that can be used to get desired amount= "<<x<<"\n";
	return 0;
}
