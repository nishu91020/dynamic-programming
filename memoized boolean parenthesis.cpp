//Problem statement : Boolean paranthesis(memoized)
#include<bits/stdc++.h>
using namespace std;
string s;
unordered_map<string,bool>mp;
int solve(string s,int i,int j,bool istrue)
{
	int t[s.length()+1][s.length()+1];
	memset(t,-1,sizeof(t));
	if(i>j)
		return 0;
	if(i==j)
	{
		if(istrue==true)
			return s[i]=='t';
		else
			return s[i]='f';
	}
	string temp=to_string(i);
	temp.push_back(" ");
	temp.append(to_string(j));
	temp.push_back(" ");
	temp.append(to_string(istrue));
	if(mp.find(temp)!=mp.end())
		return mp(temp);
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
	return mp(temp)= ans;
}
int main()
{
	mp.clear();
	cout<<"Enter the string"<<"\n";
	cin>>s;
	bool istrue=true;
	int x=solve(s,0,s.length()-1,istrue);
	cout<<"number of ways to make the outcome true = "<<x<<"\n";
	return 0;
}
