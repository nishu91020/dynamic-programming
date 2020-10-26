//Problem statement : we are given a string and we have to find the minimum number of partition in string so that resulting substrings are palindrome.
#include<bits/stdc++.h>
using namespace std;
bool ispalindrome(string s,int l,int h)
{
	 while (h > l) 
    { 
        if (s[l++] != s[h--]) 
        { 
            
            return false; 
        } 
    } 
    return true;
}
int solve(string s,int i,int j)
{
	if(i>=j || ispalindrome(s,i,j))
		return 0;
	int ans=INT_MAX;
	for(int k=i;k<j;k++)
	{
		int y=solve(s,i,k)+solve(s,k+1,j)+1;
		ans=min(y,ans);
	}
	return ans;
}
int main()
{
	/*int n;
	cout<<"enter size of array"<<"\n";
	cin>>n;*/
	//cout<<ispalindrome("isi",0,2)<<"\n";
	string s;
	cout<<"enter string"<<"\n";
	cin>>s;
	int x=solve(s,0,s.length()-1);
	cout<<"minimum number of partition = "<<x<<"\n";
	
	return 0;
}
