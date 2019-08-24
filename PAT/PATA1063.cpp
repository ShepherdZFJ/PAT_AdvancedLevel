#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;
int getCommomNumberCount(vector<int>v1,vector<int>v2)
{
    int count=0;
    int low,high,mid;
    
    for(int i=0;i<v1.size();i++)
    {
	    low=0;
        high=v2.size()-1;
        while(low<=high)
        {
            mid=(low+high)/2;
            if(v2[mid]==v1[i]) 
            {
            	count++;
            	break;
			}
            else if(v2[mid]>v1[i]) high=mid-1;
            else low=mid+1;
        }
    }
    return count;
}
int main()
{
    int n,m,k;
    int Nc,Nt;
    int number;
    int set1,set2;
    double y;
    vector<int>v[60];
   
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&m);
         map<int,bool> mp;
        for(int j=0;j<m;j++)
        {
            scanf("%d",&number);
            if(!mp[number])
            {
                v[i].push_back(number);
                mp[number]=true;
            }
            
        }
    }
    scanf("%d",&k);
    for(int x=0;x<k;x++)
    {
        scanf("%d%d",&set1,&set2);
        sort(v[set2].begin(),v[set2].end());
        Nc=getCommomNumberCount(v[set1],v[set2]);
        Nt=v[set1].size()+v[set2].size()-Nc;
        y=double(Nc)/double(Nt) *100;
        printf("%.1f%%",y);
    }
}
