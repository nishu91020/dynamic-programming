//problem statement:we are given two strings we have to print a string that contains both the strings as subsequence.
#include<bits/stdc++.h>
using namespace std;
void LCS(string a,string b,int m,int n)
{
	int t[m+1][n+1];
	for(int i=0;i<m+1;i++)
	{
		for(int j=0;j<n+1;j++)
		{
			if(i==0 || j==0)
				t[i][j]=0;
			else if(a[i-1]==b[j-1])
				t[i][j]=1+t[i-1][j-1];
			else
			t[i][j]=max(t[i-1][j],t[i][j-1]);
		}
	}
	string s;
	int i=m,j=n;
	while(i>0 && j>0)
	{
		if(a[i-1]==b[j-1])
			{
				s.push_back(a[i-1]);
				i--;
				j--;
			}
		else if(t[i-1][j]>=t[i][j-1])
			{
				s.push_back(a[i-1]);
				i--;
			}
		else
			{
				s.push_back(b[j-1]);
				j--;
			}
	}
	while(i>0)
	{
		s.push_back(a[i-1]);
		i--;
	}
	while(j>0)
	{
		s.push_back(b[j-1]);
		j--;
	}
	reverse(s.begin(),s.end());
	cout<<s<<"\n";
}

int main()
{
	string a,b;
	cout<<"Enter string a and b"<<"\n";
	cin>>a>>b;
	LCS(a,b,a.length(),b.length());
	
	return 0;
}
