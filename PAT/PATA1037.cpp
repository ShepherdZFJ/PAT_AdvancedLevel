#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
    int n_c,n_p;
    int time,value;
    int count=0;
    int min1,min2;
    vector<int> v_n1,v_n2,v_p1,v_p2;
    scanf("%d",&n_c);
    for(int i=0;i<n_c;i++)
    {
        scanf("%d",&time);
        if(time>0) v_n1.push_back(time);
        if(time<0) v_n2.push_back(time);
    }
    scanf("%d",&n_p);
      for(int i=0;i<n_p;i++)
    {
        scanf("%d",&value);
        if(value>0) v_p1.push_back(value);
        if(value<0) v_p2.push_back(value);
    }
    sort(v_n1.begin(),v_n1.end(),cmp);
    sort(v_n2.begin(),v_n2.end());
    sort(v_p1.begin(),v_p1.end(),cmp);
    sort(v_p2.begin(),v_p2.end());
    if(v_n1.size()>v_p1.size()) min1=v_p1.size();
    else min1=v_n1.size();
    if(v_n2.size()>v_p2.size()) min2=v_p2.size();
    else min2=v_n2.size();
    for(int i=0;i<min1;i++)
    {
        count+=v_n1[i]*v_p1[i];
    }
    for(int i=0;i<min2;i++)
    {
        count+=v_n2[i]*v_p2[i];
    }
    printf("%d",count);
    return 0;
}