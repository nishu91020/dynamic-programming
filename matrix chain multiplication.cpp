//problem statement:we are given an array with size n which contains the dimensions of n-1 matrix and we have to find the minimum cost for multiplication of 
//n-1 matrices. 

#include<bits/stdc++.h>
using namespace std;

int MCM(int i,int j,int arr[])
{
	if(i>=j)
		return 0;
	int mini=INT_MAX;
	for(int k=i;k<j;k++)
	{
		int f=MCM(i,k,arr)+MCM(k+1,j,arr)+(arr[i-1]*arr[k]*arr[j]);
		if(mini>f)
			mini=f;
	}
	return mini;
}
int main()
{
	int n;
	cout<<"enter no. of elements you want to enter in array"<<"\n";
	cin>>n;
	int arr[n];
	cout<<"enter array"<<"\n";
	for(int i=0;i<n;i++)
		cin>>arr[i];
	int x=MCM(1,n-1,arr);
	cout<<"minimum cost of multiplication = "<<x<<"\n";
	
	return 0;
}
