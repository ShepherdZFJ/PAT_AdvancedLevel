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
    int mid;
    long long  nearSum=9999999;
    int value_min=0;
    int count=0;
    bool flag=true;
    bool temp=true;
    int sum[MAX];
    vector<int>v1;
    vector<int>v2;
    scanf("%d",&n);
    scanf("%d",&m);
    sum[0]=0;
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&value[i]);
        sum[i]=sum[i-1] +value[i];
    }
    for(int i=0;i<=n;i++)
    {
        mid=(i+1+n)/2;
        for(int j=i+1;j<=n;j++)
        {
            if(sum[mid]-sum[i]==m)
            {
                 printf("%d-%d\n",i+1,mid);
                 flag=false;
                 break;
            }
            else
            {
                if(sum[mid]-sum[i]<m) j=mid;
                else if(sum[mid]-sum[i]>m)
                {
                    if(sum[mid]-sum[i]<nearSum)
                    {
                        nearSum=sum[mid]-sum[i];
                        n=mid;
                    }
                    else
                    {
                        v1.push_back(i);
                        v2.push_back(j);
                
                    }
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