#include<iostream>
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
		for(int i=0;i<n-1;i++)   //��С�������� 
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
		
		for(int i=0;i<n;i++)    //Ѱ���������� 
	   {
		for(int k=i+s;k<n;k++)
		{
		
			if((a[k]>(long long)a[i]*p))   //a[i]*p��ֵ�п��ܴ���10^9,������long longת��һ�� 
			{
			
				count=k-i;  //�õ��������е����ָ��� 
				if(count>max_count) max_count=count; 
				break;
			}
		    
		   // if((a[k]<=(long long)a[i]*p))  count++;
		   // else   break;
		   
			if(k==n-1) //���ѭ������k==n-1 ���Ͳ�����ѭ���ˡ� 
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
