//problem statement: basic problem statement of knapsack is we are given two arrays value array and weight array we need to find the maximum profit that we
//can gain by choosing items given that the size of our bag is fixed that is W or we can say we need to choose item with min weight and max value.
//bottom-up approach.
#include<bits/stdc++.h>
using namespace std;
int knapsack(int wt[],int val[],int maxi,int n)
{
	int t[n+1][maxi+1];
	for(int i=0;i<n+1;i++)
	{
		for(int j=0;j<maxi+1;j++)
		{
			if(i==0 || j==0) //base condition (capacity of bag is 0 or size of array is 0)
				t[i][j]=0;
			else if(wt[i-1]<=j)
			{
				t[i][j]=max((val[i-1]+t[i-1][j-wt[i-1]]),t[i-1][j]);//either we include the item or we don't include it.
			}
			else
				t[i][j]=t[i-1][j];//if weight of item is greater than max. capacity of bag we will definately not include it.
		}
	}
	return t[n][maxi];
}
int main(){
	int n;
	cout<<"enter no. of elements you want to create array"<<"\n";
	cin>>n;
	int wt[n],val[n];
	cout<<"enter elements of weight array"<<"\n";
	for(int i=0;i<n;i++)
	{
		cin>>wt[i];
	}
	cout<<"enter elements of value array"<<"\n";
	for(int i=0;i<n;i++)
	{
		cin>>val[i];
	}
	int cap;
	cout<<"enter the maximum capacity of bag"<<"\n";
	cin>>cap;
	int ans=knapsack(wt,val,cap,n);
	cout<<"maximum profit is"<<" "<<ans<<"\n";
	return 0;
	
}
