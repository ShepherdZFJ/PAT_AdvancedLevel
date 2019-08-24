#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
const int MAX=100010;
bool hashtable[MAX]={false};
int position[MAX]={0};
class polynomials
{
  public:
  int exponent;         //指数 
  double coefficient;	    //系数 
  void input();
};
void polynomials::input()
{
	scanf("%d %lf",&exponent,&coefficient);
}
bool cmp(polynomials a,polynomials b)
{
	return a.exponent > b.exponent;
}

int main()
{
	int k1,k2;
	int count=0;
	polynomials p,c;
	vector<polynomials>v,AB;
	scanf("%d",&k1);
	for(int i=0;i<k1;i++)
	{
		p.input();
		v.push_back(p);
		
	}
	//for(int i=0;i<v.size();i++)
	//printf("%d %lf",v[i].exponent,v[i].coefficient);
   
	scanf("%d",&k2);
	for(int i=0;i<k2;i++)
	{
		p.input();
		for(int m=0;m<v.size();m++)
		{
			c.exponent=v[m].exponent+p.exponent;
			c.coefficient=v[m].coefficient*p.coefficient;
			if(hashtable[c.exponent]) AB[position[c.exponent]].coefficient=AB[position[c.exponent]].coefficient+c.coefficient;
			else 
			{
				AB.push_back(c);
			    hashtable[AB[m].exponent]=true;
			    position[AB[m].exponent] =AB.size()-1;
			}
		}
	}
	sort(AB.begin(),AB.end(),cmp);
	count=AB.size();
	for(int i=0;i<AB.size();i++)
	{
		if(AB[i].coefficient==0) count--;
	}
	printf("%d ",count);
	for(int i=0;i<AB.size();i++)
	{
		bool flag=false;
	 	for(int j=i+1;j<AB.size();j++)
	 	{	
		 if(AB[j].coefficient !=0)  
		 {
		 	flag=true;
		 	break;
		 }
	    }
	  if(AB[i].coefficient !=0)
	 	{
	 	if(i<AB.size()-1 && flag) printf("%d %.1lf ",AB[i].exponent,AB[i].coefficient);
	 	else  printf("%d %.1lf",AB[i].exponent,AB[i].coefficient);
	    }
	}
	

	return 0;
}
