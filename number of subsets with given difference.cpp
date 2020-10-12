//problem statment:we need to find how many pairs of subset exist such that their difference is equal to a given differece.
#include<bits/stdc++.h>
int number_of_subset_sum(int arr[],int n,int sum)
{
	int t[n+1][sum+1];
	for(int i=0;i<=sum;i++)
	{
		t[0][i]=0;
	}
	for(int i=0;i<=n;i++)
	{
		t[i][0]=1;
	}

	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=sum;j++)
		{
			if(j>=arr[i-1])
			{
				t[i][j]=t[i-1][j-arr[i-1]]+t[i-1][j];
			}
			else
				t[i][j]=t[i-1][j];
		}
	}
	return t[n][sum];
}
int n_of_subset_with_given_diff(int arr[],int n,int d)
{
	int sum=0;
	for(int i=0;i<n;i++)
	{
		sum+=arr[i];
	}
	if((sum+d)%2!=0)
		return 0;
	int s=(sum+d)/2;
	return number_of_subset_sum(arr,n,s);
}
using namespace std;
int main(){
	int n;
	cout<<"enter the number of elements in array"<<"\n";
	cin>>n;
	int arr[n];
	cout<<"enter array elements"<<"\n";
	for(int i=0;i<n;i++)
		cin>>arr[i];
	int diff;
	cout<<"enter the desired difference b/w two subsets"<<"\n";
	cin>>diff;
	int ans=n_of_subset_with_given_diff(arr,n,diff);
	cout<<"no. of subsets with a given difference"<<" "<<ans<<"\n";
	return 0;
}
