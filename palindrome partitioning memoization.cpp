//Problem statement : we are given a string and we have to find the minimum number of partition in string so that resulting substrings are palindrome.(memoized)
#include<bits/stdc++.h>
using namespace std;
string s;
bool ispalindrome(string s,int i,int j)
{
	while(i<j)
	{
		if(s[j--]!=s[i++])
			return false;
	}
	return true;
}
solve(string s,int i,int j)
{
	int t[s.length()+1][s.length()+1];
	memset(t,-1,sizeof(t));
	if(i>=j || ispalindrome(s,i,j))
		return 0;
	if(t[i][j]!=-1)
		return t[i][j];
	int ans=INT_MAX;
	for(int k=i;k<j;k++)
	{
		int y=solve(s,i,k)+solve(s,k+1,j)+1;
		ans=min(ans,y);
	}
	return t[i][j]=ans;
}
int main()
{
	
	cout<<"Enter the string"<<"\n";
	cin>>s;
	int x=solve(s,0,s.length()-1);
	cout<<"minimum number of palindrome partitioning = "<<x<<"\n";
	
	return 0;
}
