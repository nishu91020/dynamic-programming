//problem statement:we are given a string and we need to find out a subsequence that is repeated maximum number of times with largest length.
#include<bits/stdc++.h>
using namespace std;

int LCS(string a,string b,int m,int n)
{
	int t[m+1][n+1];
	for(int i=0;i<m+1;i++)
	{
		for(int j=0;j<m+1;j++)
		{
			if(i==0 || j==0)
				t[i][j]=0;
			else if(a[i-1]==b[j-1] && i!=j)
			t[i][j]=1+t[i-1][j-1];
			else
				t[i][j]=max(t[i-1][j],t[i][j-1]);
		}
	}
	return t[m][n];
}
int main()
{
	string s;
	cout<<"enter the string"<<"\n";
	cin>>s;
	int x=LCS(s,s,s.length(),s.length());
	cout<<"length of longest repeating subsequence = "<<x<<"\n";
}
