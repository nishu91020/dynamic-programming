//problem statement:matrix chain multiplication using memoized version.
#include<bits/stdc++.h>

using namespace std;
	int n;
	
int MCM(int a[],int i,int j)
{
	int t[n+1][n+1];
	//cout<<n+1;
	memset(t,-1,sizeof(t));
	if(i>=j)
		return 0;
	if(t[i][j]!=-1)
		return t[i][j];
	int ans=INT_MAX;
	for(int k=i;k<j;k++)
	{
		int x=MCM(a,i,k)+MCM(a,k+1,j)+(a[i-1]*a[k]*a[j]);
		ans=min(x,ans);
	}
	return t[i][j]=ans;
}
int main()
{
	cout<<"enter no. of elements you want to enter in array"<<"\n";
	cin>>n;	
	int arr[n];
	cout<<"enter array"<<"\n";
	for(int i=0;i<n;i++)
		cin>>arr[i];
	int x=MCM(arr,1,n-1);
	cout<<"minimum cost of multiplication = "<<x<<"\n";
	return 0;
}
