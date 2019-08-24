#include<iostream>
#include<vector>
using namespace std;
bool hashtable1[10000]={false};
int hashtable2[10000]={0};
int dp[10000];
int main()
{
    int n,m,length;
    int order[200];
    int stripe[10000];
    bool flag=true; 
    vector<int>v;
    scanf("%d",&n);
    scanf("%d",&m);
    for(int i =0;i<m;i++)
    {
        scanf("%d",&order[i]);
        hashtable1[order[i]]=true; //记录是否在喜爱的序列里面
        hashtable2[order[i]]=i;    //记录颜色的优先级
    }
    scanf("%d",&length);
    for(int i=0;i<length;i++)
    {
        scanf("%d",&stripe[i]);
    }
   for(int i=0;i<length;i++)
   {
       
       if(hashtable1[stripe[i]]) 
        {
        	dp[i]=1;
        	flag=false; 
            for(int j=0;j<i;j++)
            {   //得到dp[i],dp[i]表示以stripe[i]为结尾，同时满足优先级的的子序列最大值
                if(hashtable2[stripe[j]]<=hashtable2[stripe[i]] && dp[j]+1>dp[i])  
                    dp[i]=dp[j]+1;
            }
        }
   }
   int k=0;
   for(int i=0;i<length;i++)
   {
       if(dp[i]>dp[k]) k=i;

   }  
   if(flag)  printf("0");
   else printf("%d",dp[k]);   



    return 0;
}