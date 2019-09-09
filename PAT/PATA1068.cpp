/*
 * @Author: MeiYing 
 * @Date: 2019-08-28 20:18:16 
 * @Last Modified by: MeiYing
 * @Last Modified time: 2019-08-28 21:16:52
 */
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int n,m;
vector<int>v,ans,value;
bool flag;
void DFS(int index,int sum)
{
    if(sum==m && ans.size()==0)
    {
      ans=v;
      flag=true;
      return;
    }
    if(index==n ||sum>m) return ;
    if(!flag)
    {
        v.push_back(value[index]);
        DFS(index+1,sum+value[index]);
        v.pop_back();
        DFS(index+1,sum);
    }
     
    
    
}

int main()
{
    int a;
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a);
        value.push_back(a);
    }
    sort(value.begin(),value.end());
    DFS(0,0);
    if(ans.size()==0)
    {
        printf("No Solution");
    }
    else
    {
        for(int i=0;i<ans.size();i++)
        {
            if(i<ans.size()-1)
            {
                printf("%d ",ans[i]);
            }
            else
            {
                printf("%d",ans[i]);
            }
            
        }
    }
    
    return 0;
}