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
int main(){
	string a;
	cout<<"Enter string a and b"<<"\n";
	cin>>a;
	string b=a;
	reverse(a.begin(),a.end());
	//cout<<b<<" "<<a<<"\n";
	int x=LCS(b,a,b.length(),a.length());
	cout<<"length of longest palindromic subsequence is "<<x<<"\n";
	return 0;
}
