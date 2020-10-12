//problem statement:we need to find out the max. profit that can be obtained given a weight and value array and supply of each item is unlimited
//unbounded knapsack

#include<bits/stdc++.h>
using namespace std;

int unbounded_knapsack(int wt[],int val[],int n,int w)
{
	int t[n+1][w+1];
	for(int i=0;i<=w;i++)
		t[0][i]=0;
	for(int i=0;i<=n;i++)
		t[i][0]=1;
	for(int i=0;i<=n;i++)
	{
		for(int j=0;j<=w;j++)
		{
			if(wt[i-1]<=j)
				t[i][j]=max(val[i-1]+t[i][j-wt[i-1]],t[i-1][j]);
			else
				t[i][j]=t[i-1][j];
		}
	}
	return t[n][w];	
}
int main()
{
	int n;
	cout<<"enter no. of elements"<<"\n";
	cin>>n;
	int wt[n],val[n],w;
	cout<<"enter weight array"<<"\n";
	for(int i=0;i<n;i++)
	{
		cin>>wt[i];
	}
	cout<<"enter value array"<<"\n";
	for(int i=0;i<n;i++)
	{
		cin>>val[i];
	}
	cout<<"enter max weight that can be put in the bag"<<"\n";
	cin>>w;
	int f=unbounded_knapsack(wt,val,n,w);
	cout<<"maximum profit = "<<f<<"\n";
	
	return 0;
}
