//problem statement:we are given two strings and we have to find out minimum length of a string that contains both the strings. 
#include<bits/stdc++.h>
using namespace std;
int LCS(string a,string b,int m,int n)
{
	int t[m+1][n+1];
	for(int i=0;i<m+1;i++)
	{
		for(int j=0;j<n+1;j++)
		{
			if(i==0 || j==0)
				t[i][j]=0;
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
	int m=a.length();
	int n=b.length();
	int x=LCS(a,b,a.length(),b.length());
	cout<<"length of shortest common supersequence(a sequence which contains all the elements of a and b in same relative order) is "<<(m+n)-x<<"\n";
	return 0;
}
