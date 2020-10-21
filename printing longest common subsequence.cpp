//problem statement: we are given two strings, print longest common subsequence of the two strings.
#include<bits/stdc++.h>
using namespace std;
void longest_common_subsequence(string a,string b,int m,int n)
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
				t[i][j]=t[i-1][j-1]+1;
			else
				t[i][j]=max(t[i-1][j],t[i][j-1]);
		}
	}
	int index=t[m][n];
	char s[index+1];
	s[index]='\0';
	int i=m,j=n;
	while(i>0 && j>0)
	{
	
			if(a[i-1]==b[j-1])
			{
				s[index-1]=a[i-1];	
				i--;
				j--;
				index--;
			}
			else if(t[i-1][j] > t[i][j-1])
					i--;
			else
					j--;

	}
	cout<<"LCS Of "<<a <<" and "<< b<<" is "<<s<<"\n";
}
int main()
{
	string a,b;
	cout<<"Enter string a and b"<<"\n";
	cin>>a>>b;
	longest_common_subsequence(a,b,a.length(),b.length());
	/*string x=longest_common_subsequence(a,b,a.length(),b.length());
	cout<<"length of longest common subsequence "<<x<<"\n";	*/
	return 0;
}
