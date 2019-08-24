#include<iostream> 
#include<vector>
using namespace std;
int main()
{
	int a,b,sum;
	int n,count=0;
	vector<int>v1;
	bool flag=false;
	scanf("%d%d",&a,&b);
	sum=a+b;
	if(sum==0) 
	{
		printf("%d",0);
	}
	if (sum<0) 
	{
	   flag=true;
	   sum=-sum;
	}
	while(sum!=0)
	{
	  n=sum%10;
	  v1.push_back(n);
	  sum=sum/10;
	  count++;	
	}
	//	printf("%d\n",count);
	if(flag) printf("%c",'-');

	for(int i=v1.size()-1;i>=0;i--)
	{
		printf("%d",v1[i]);
		if(count>3)
		{
		if(count%3==0)
			{
			   if((v1.size()-i)%3==0&&i>0) printf("%c",',');
			}
			else if(count%3==1)
			{
			if(i==v1.size()-1&&i>0)	printf("%c",',');
			if(((v1.size()-1-i)%3==0)&&(v1.size()-i>3)&&i>0) printf("%c",',');
			}
			else
			{
				if(i==v1.size()-2)	printf("%c",',');
			if(((v1.size()-2-i)%3==0)&&(v1.size()-i>3)&&i>0) printf("%c",',');
			}
		}
	
	}
	return 0;
}
