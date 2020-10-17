//problem statement:we are given an array of price and length we have to find maximum profit that can be generated.
#include<bits/stdc++.h>
using namespace std;
int rod_cutting_problem(int len[],int val[],int n,int l)
{
	int t[n+1][l+1];
	for(int i=0;i<=l;i++)
		t[0][i]=0;
	for(int i=0;i<=n;i++)
		t[i][0]=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=l;j++)
		{
			if(len[i-1]<=j)
				t[i][j]=max((val[i-1]+t[i][j-len[i-1]]),t[i-1][j]);
			else
				t[i][j]=t[i-1][j];
		}
	}
	return t[n][l];	
}
int main()
{
	int l;
	cout<<"enter length of rod "<<"\n";
	cin>>l;
	int arr[l];
	cout<<"enter array of price"<<"\n";
	for(int i=0;i<l;i++)
		cin>>arr[i];
	int len[l];
	for(int i=0;i<l;i++)
		len[i]=i+1;
	int k=rod_cutting_problem(len,arr,l,l);
	cout<<"maximum profit= "<<k<<"\n";
}
