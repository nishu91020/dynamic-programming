//problem statement: we are given two strings and we have to find length of longest common substring between them.
#include<bits/stdc++.h>
using namespace std;

int longest_common_substring(string a,string b,int m,int n)
{
	int t[m+1][n+1];
	int res=0;
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
				{
					t[i][j]=1+t[i-1][j-1];
					res=max(res,t[i][j]);
				}
			else
				t[i][j]=0;
		}
	}
	return res;
}
int main()
{
	string a,b;
	cout<<"Enter string a and b"<<"\n";
	cin>>a>>b;
	int x=longest_common_substring(a,b,a.length(),b.length());
	cout<<"length of longest common subsequence "<<x<<"\n";
	return 0;
}
