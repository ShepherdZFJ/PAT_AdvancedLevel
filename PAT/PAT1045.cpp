#include<iostream> 
#include<vector>
using namespace std;
const int maxn=100010;
int main()
{

	vector<int>v;
	int n;
	int a[maxn];
    
	int count=0;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	  scanf("%d",&a[i]);
	for(int i=0;i<n;i++)
	{
	    int s1=0,s2=0;
	    int x1=0,x2=0;
	    bool flag1=false;
	    bool flag2=false;
		for(int j=0;j<i;j++)
		{
			if(a[j]<a[i]) s1++;
			if(a[j]>a[i]) s2++;
			if(s1>0&&s2>0) flag1=true;
			if(flag1) break;
			
		}
	   	if(flag1) continue;
		for(int k=i+1;k<n;k++)
		{
		
			if(a[k]<a[i])  x1++;
			if(a[k]>a[i])  x2++;
			if(x1>0&&x2>0) flag2=true;
			if(flag2)  break;
		}
		if(flag2) continue;
		count++;
		v.push_back(a[i]);
		
		
	}
	printf("%d\n",count);
	if(v[0]>v[v.size()-1])
	{
		for(int i=v.size()-1;i>=0;i--)
		{
			 if(i>0)  printf("%d ",v[i]);
			 else  printf("%d",v[i]);
		}
	       
	
	}
	else
	{
	
	for(int i=0;i<v.size();i++)
	{
	    if(i<v.size()-1) printf("%d ",v[i]);
	    else printf("%d",v[i]);
	
	}
	    
	
	
    }
	
	return 0;
}
