/*
 * @Author: MeiYing 
 * @Date: 2019-07-30 14:30:13 
 * @Last Modified by:   MeiYing 
 * @Last Modified time: 2019-07-30 14:30:13 
 */
#include<iostream>
#include<math.h>
using namespace std;
int prime(int m)
{
    bool flag,bl;
    int q;
    flag=true;
    if(m<=1) return 2;
    while(flag)
    {
         bl=true;
        q=sqrt(m);
        for(int i=2;i<=q;i++)
        {
            if(m%i==0)
            {
                //flag=false;
                m++;
                bl=false;
                break;
            }
        }  
        if(bl)
        {
            flag=false;
            break;
        }
    }
    return m;
}
int main()
{
    int n,m,value;
    int p,index,k;
    bool flag;
    bool hashtable[100000]={false};
    scanf("%d%d",&m,&n);
    p=prime(m);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&value);
        index=value%p;
        if(!hashtable[index])
        {
            printf("%d",index);
            hashtable[index]=true;
        }
        else
        {
           // printf("-");
           int x=1;
           k=(index+1)%p;
           flag=true;
           while(flag)
           {
               if(hashtable[k])
               {
                   x++;
                   if(x==p)
                   {
                       flag=false;
                       printf("-");
                       break;
                   }
                    k=(index+x*x)%p;
                    if(k>=p)
                    {
                        flag=false;
                       printf("-");
                       break;
                    }
                  
               }
               else
               {
                   printf("%d",k);
                   hashtable[k]=true;
                   flag=false;
               }
               
           }


        }
        if(i<n-1) printf(" ");  

    }


    return 0;
}