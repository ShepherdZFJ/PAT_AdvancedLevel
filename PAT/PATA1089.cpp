/*
 * @Author: MeiYing 
 * @Date: 2019-08-15 13:59:59 
 * @Last Modified by: MeiYing
 * @Last Modified time: 2019-08-15 19:55:36
 */
#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int n,pos;
    bool flag;
    int init_seq[110];
    int part_sort_seq[110];
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&init_seq[i]);
    }
    for(int i=0;i<n;i++)
    {
        scanf("%d",&part_sort_seq[i]);
    }
    for(int i=0;i<n;i++)
    {
        if(i==n-1) break;
        if(part_sort_seq[i]>part_sort_seq[i+1])
        {
            pos=i+1;
            break;
        }
    }
    
    for (int i = 1; i < n; i++)
    {
        if (part_sort_seq[i] < part_sort_seq[i - 1])
        {
            pos = i;
            break;
        }
    }
    for(int i=pos;i<n;i++)
    {
        if(init_seq[i]!=part_sort_seq[i])
        {
            flag=true;
            break;
        }
    }
    if(flag)
    {
        bool sign,s;
        printf("Merge Sort\n");
        for(int step=2;step/2<=n;step*=2)
        {
            
            for(int i=0;i<n;i+=step)
            {
                sort(init_seq+i,init_seq+min(i+step,n+1));
            }
            if(sign)
            {
                for(int i=0;i<n;i++)
                {
                    if(i<n-1) printf("%d ",init_seq[i]);
                    else printf("%d\n",init_seq[i]);
                }
                break;
            }
            for(int i=0;i<n;i++)
            {
                if(init_seq[i]!=part_sort_seq[i])
                {
                    sign=false;
                    break;
                }
                else
                {
                    sign=true;
                }
                
            }
        }
    } 
    else
    {
            printf("Insertion Sort\n");
            sort(part_sort_seq,part_sort_seq+pos+1);
            for(int i=0;i<n;i++)
            {
                if(i<n-1) printf("%d ",part_sort_seq[i]);
                else printf("%d\n",part_sort_seq[i]);
            }                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                         
    
    }
   
    return 0;

}