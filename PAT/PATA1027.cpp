#include<iostream> 
#include<vector>
using namespace std;
void print(int);
int main()
{   
   
	int red,green,blue;
	scanf("%d%d%d",&red,&green,&blue);
	printf("#");
	print(red);
	print(green);
	print(blue);
	
	
	return 0;
}
void print(int n)
{
	vector<int>v;
	int m,count=0;
	while(n!=0)
	{
		m=n%13;
		v.push_back(m);
		n=n/13;
		//count++;
	}
	if(v.size()==0) printf("00");
	if(v.size()==1) printf("0");
	for(int i=v.size()-1;i>=0;i--)
	{
			if(v[i]<10) printf("%d",v[i]);
		else
		{
			if(v[i]==10) printf("A");
			if(v[i]==11) printf("B");
			if(v[i]==12) printf("C");
		}
	}
	
}
