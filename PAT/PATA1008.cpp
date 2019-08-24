#include<iostream> 
#include<set>
#include <algorithm>
#include<vector>
using namespace std;
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
    set<int> s;
    vector<int>v;
    int count=0;
	int n,m;
	int temp;
	int floor_no;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&m);
		v.push_back(m);
	}
	/*
	set<int>::iterator it1 = s.begin();
    set<int>::iterator it2 = s.end();
     for(;it1!=it2;it1++)
     {
       v.push_back(*it1);	
	 }
	 */
     //sort(v.begin(),v.end(),cmp);
     for(int i=0;i<v.size();i++)
     {
         //printf("%d ",v[i]);
         	
		 if(i==0)
		 {
		 	count=+6*v[i];
		 }
		 else
		 {
		 	if(v[i]>v[i-1]) count+=6*(v[i]-v[i-1]);
		 	else count+=4*(v[i-1]-v[i]);
		 }
		 
	 }
     count+=5*v.size();
	printf("%d",count) ;
	return 0;
}
