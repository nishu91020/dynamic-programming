//Problem statement : we are given a string made up of T,F,|(OR),&(and),^(XOR) and we need to put 
//the brackets in such a way that expression evaluates to true find total number of ways in which this can be done.
#include<bits/stdc++.h>
using namespace std;
string s;
int solve(string s,int i,int j,bool istrue)
{
	/*int t[s.length()+1][s.length()+1];
	memset(t,-1,sizeof(t));*/
	if(i>j)
		return 0;
	if(i==j)
	{
		if(istrue==true)
			return s[i]=='t';
		else
			return s[i]='f';
	}
	/*if(t[i][j]!=-1)
		return t[i][j];*/
	int ans=0;
	for(int k=i+1;k<j;k=k+2)
	{
		int lt,lf,rt,rf;
		lt=solve(s,i,k,true);
		lf=solve(s,i,k,false);
		rt=solve(s,k+1,j,true);
		rf=solve(s,k+1,j,false);
		if(s[k]=='&')
		{
			if(istrue==true)
			ans=ans+lt*rt;
			else
			ans+=(lt*rf+lf*rt+lf*rf);
		}
		else if(s[k]=='|')
		{
			if(istrue==true)
			ans+=(lt*rf+lf*rt+lt*rt);
			else
			ans+=lf*rf;
		}
		else if(s[k]=='^')
		{
			if(istrue==true)
			ans+=(lt*rf+lf*rt);
			else
			ans+=(lf*rf+lt*rt);
		}
	}
	return ans;
}
int main()
{
	cout<<"Enter the string"<<"\n";
	cin>>s;
	bool istrue=true;
	int x=solve(s,0,s.length()-1,istrue);
	cout<<"number of ways to make the outcome true = "<<x<<"\n";
	return 0;
}
