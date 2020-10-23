//problem statement: we are given a strings a, we have to find number of insertion operation to be performed to make the string palindrome.
#include<bits/stdc++.h>
using namespace std;
int LPS(string a,string b,int m,int n)
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
	cin>>a;
	b=a;
	reverse(b.begin(),b.end());
	int x=LPS(a,b,a.length(),b.length());
	cout<<"nuber of insertions required = "<<a.length()-x<<"\n";
	return 0;
}
