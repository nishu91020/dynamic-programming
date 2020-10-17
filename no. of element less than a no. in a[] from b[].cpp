#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin>>n;
	int a[n],b[n];
	for(int i=0;i<n;i++)
		cin>>a[i];
	for(int i=0;i<n;i++)
		cin>>b[i];
	sort(a,a+n);
	for(int i=0;i<n;i++)
	{int ans=-1;
	int lo=0,hi=n-1;
	while(lo<=hi)
		{
			int mid=(lo+hi)/2;
			if(b[i]<a[mid])
				{
					ans=mid;
					lo=mid+1;
				}
			else
				{
					hi=mid-1;
				}
				
		}		
	}
	return 0;
	
}
