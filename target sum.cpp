//problem statement:we need to insert an operation + or - in front of each element of the given array such that we get the desired sum
//we need to find in how many ways this can be done

#include<bits/stdc++.h>
using namespace std;
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
int target_sum(int arr[],int n,int tsum)
{
	int sum=0;
	for(int i=0;i<n;i++)
	{
		sum+=arr[i];
	}
	if((sum+tsum)%2!=0)
		return 0;
	int s=(sum+tsum)/2;
	return number_of_subset_sum(arr,n,s);
}

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
	int ans=target_sum(arr,n,diff);
	cout<<"no. of subsets with a given target sum ="<<" "<<ans<<"\n";
	return 0;
}
