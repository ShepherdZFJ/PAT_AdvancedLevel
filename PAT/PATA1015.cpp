#include<iostream>
#include<vector>
#include<math.h>
using namespace std;
int main()
{
	int n,d,m,reverse_n=0;
	int sqrt_n; 
	vector<int> v;
	int temp;
	while(scanf("%d",&n) && n>=0)
	{   
		int reverse_n=0;
		bool isprime=true;
		scanf("%d",&d);
		temp=n;
		if(temp<2)   //输入的数字为1的话直接返回No 
		{
			printf("No\n");
			continue;
		}
		
		while(n!=0) //数字反转并存入向量中 
		{
		  m=n%d;
		  v.push_back(m);
		  n=n/d;	
		}
		for(int i=2;i<=sqrt(temp);i++)  //判断原始数字是不是素数 
		{
			if(temp%i==0)
			{
				isprime=false;
				break;
			}
		}
		for(int i=0;i<v.size();i++)  //得到反转之后的数字 
		{
			reverse_n+=v[i]*pow(d,v.size()-1-i);
		}
			if(reverse_n<2)   //输入的数字为1的话直接返回No 
		{
			printf("No\n");
			continue;
		}
		sqrt_n=sqrt(reverse_n);   //判断反转之后的数字是不是素数 
		for(int x=2;x<=sqrt_n;x++)
		{
			if(reverse_n%x==0 ) 
			{
			   isprime=false;
			   break;	
			}	
		}
		
	    if(isprime) printf("Yes\n");
		else printf("No\n");
		v.clear();
	}
	
	return 0;
}
