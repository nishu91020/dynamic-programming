//problem statement: we are given two strings a and b, we have to find if the string a is present in b as a subsequence.
#include<bits/stdc++.h>
using namespace std;
int LCS(string a,string b,int m,int n)
{
	int t[m][n];
	for(int i=0;i<m+1;i++)
	{
		for(int j=0;j<n+1;j++)
		{
			if(i==0 || j==0)
				t[i][j]=0;
			else if(a[i-1]==b[j-1])
				t[i][j]=t[i-1][j-1]+1;
			else
				t[i][j]=max(t[i-1][j],t[i][j-1]);
		}
	}
	return t[m][n];
}
int main()
{
	string a,b;
	cout<<"enter string a and b"<<"\n";
	cin>>a>>b;
	int x=LCS(a,b,a.length(),b.length());
	if(x==a.length())
		cout<<"subsequence a is present in b"<<"\n";
	else
		cout<<"subsequence a is not present in b"<<"\n";
	return 0;
}
