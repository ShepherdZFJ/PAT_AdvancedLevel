/*
 * @Author: MeiYing 
 * @Date: 2019-08-06 17:35:17 
 * @Last Modified by: MeiYing
 * @Last Modified time: 2019-08-06 17:36:24
 */
#include<iostream>
#include<algorithm>
using namespace std;

const int maxn=100010;
int main()
{
   int n,p;
   int a[maxn];
   int s=0;
   bool flag=false;
   scanf("%d%d",&n,&p);
		int count=0;
		int max_count=0;
		for(int i=0;i<n;i++)
	       scanf("%d",&a[i]);
        /* 
		for(int i=0;i<n-1;i++)   //从小到大排序 
		{
			for(int j=0;j<n-1-i;j++)
			{
				int temp;
				if(a[j]>a[j+1])
				{
				temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
				}
			}
		}
		*/
        sort(a,a+n);
		for(int i=0;i<n;i++)    //寻找完美数列 
	   {
		for(int k=i+s;k<n;k++)
		{
		
			if((a[k]>(long long)a[i]*p))   //a[i]*p的值有可能大有10^9,所以用long long转换一波 
			{
			
				count=k-i;  //得到完美数列的数字个数 
				if(count>max_count) max_count=count; 
				break;
			}
		    
		   // if((a[k]<=(long long)a[i]*p))  count++;
		   // else   break;
		   
			if(k==n-1) //如果循环到了k==n-1 ，就不用再循环了。 
			{
			flag=true;
			count=n-i;
			if(count>max_count) max_count=count;
			}
		}
		s=count-1;
		if(flag) break;
	   }
		printf("%d\n",max_count);
		
	
	
	
	return 0;
}