#include<iostream>
#include<map>
#include<vector>
using namespace std;
const int MAX=100010;
int value[MAX];
int value_min[MAX];
int main()
{
    int n,m;
    int value_min=0;
    int count=0;
    bool flag=true;
    bool temp=true;
    vector<int>v1;
    vector<int>v2;
    scanf("%d",&n);
    scanf("%d",&m);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&value[i]);
    }
    for(int i=1;i<=n;i++)
    {
	    int sum=0;
        for(int j=i;j<=n;j++)
        {
            sum+=value[j];
            if(sum==m)
            {
                printf("%d-%d\n",i,j);
                flag=false;
                break;
            }
            if(sum>m && flag)
            {
                if(temp)
                {
                   value_min= sum;
                   temp=false;
                }
                if(value_min==sum && !temp )
                {
                   
                   v1.push_back(i);
                   v2.push_back(j);
                }
                if(value_min>sum && !temp)
                {
                   value_min=sum;
                   v1.clear();
                   v2.clear();
                   v1.push_back(i);
                   v2.push_back(j);
                
                }
                 
                 
                
              
            }
            
        }
      
    }
    if(flag)
    {
        for(int i=0;i<v1.size();i++)
        {
            printf("%d-%d\n",v1[i],v2[i]);
        }
    }

    return 0;
}