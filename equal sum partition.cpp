# include<bits/stdc++.h>
using namespace std;
bool subset_sum(int a[],int sum,int n)
{
	bool t[n+1][sum+1];
	memset(t,false,sizeof(t));
	for(int i=0;i<n+1;i++)
	{
		for(int j=0;j<sum+1;j++)
		{
			if(i==0) //base condition
				t[i][j]=false;
			if(j==0) //base condition
				t[i][j]=true;
			if(a[i-1]<=j)
			{
				t[i][j]=(t[i-1][j-a[i-1]] || t[i-1][j]);
			}
			else
				t[i][j]=t[i-1][j];
		}
	}
	return t[n][sum];
}
bool equal_sum_partition(int arr[],int n)
{
	int sum=0;
	for(int i=0;i<n;i++)
	{
		sum+=arr[i];
	}
	if(sum%2!=0)
		return false;
	else
	{int s=sum/2;
	//cout<<sum;
	return subset_sum(arr,s,n);}

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
	bool ans=equal_sum_partition(a,n);
	if(ans==true)
		cout<<"array can be divided into subarray with equal sum"<<"\n";
	else
		cout<<"array can't be divided into subarray with equal sum"<<"\n";
	
	return 0;
}
