//problem statement:we are given two arrays we need to find the longest common subsequence length.
#include<bits/stdc++.h>
using namespace std;

int longest_common_subsequence(string a,string b,int m,int n)
{
	int t[m+1][n+1];
	for(int i=0;i<m+1;i++)
	{
		for(int j=0;j<n+1;j++)
		{
			if(j==0 || i==0)
			{
				t[i][j]=0;
			}
		}
	}
	for(int i=1;i<m+1;i++)
	{
		for(int j=1;j<n+1;j++)
		{
			if(a[i-1]==b[j-1])
				t[i][j]=1+t[i-1][j-1];
			else
				t[i][j]=max(t[i-1][j],t[i][j-1]);
		}
	}
	return t[m][n];
}
int main()
{
	string a,b;
	cout<<"Enter string a and b"<<"\n";
	cin>>a>>b;
	int x=longest_common_subsequence(a,b,a.length(),b.length());
	cout<<"length of longest common subsequence "<<x<<"\n";
}
