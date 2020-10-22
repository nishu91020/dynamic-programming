//problem statement:we are given a string find minimum number of deletion needs to be performed to make it palindrome.
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
			else if(a[i-1]==b[j-1])
			{
				t[i][j]=1+t[i-1][j-1];
			}
			else
				t[i][j]=max(t[i-1][j],t[i][j-1]);
		}
	}
	return t[m][n];
}
int main()
{
	string a,b;
	cout<<"Enter string a"<<"\n";
	cin>>a;
	b=a;
	reverse(a.begin(),a.end());
	int x=LCS(a,b,a.length(),b.length());
	cout<<"number of deletions to make the string palindrome "<<a.length()-x<<"\n";
	return 0;
}
