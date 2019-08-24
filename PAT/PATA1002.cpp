#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
const int MAX=100010;
bool hashtable[MAX]={false};
class polynomials
{
  public:
	    int exponent;         //指数 
	    double coefficient;   //系数 
	    void input();
};
void polynomials::input()
{
	scanf("%d%lf",&exponent,&coefficient);
	//scanf("%f",&coefficient);
}
bool cmp(polynomials a,polynomials b)    //????????????
{
	return a.exponent > b.exponent;
}
int main()
{
	int n,m;
	bool flag=false;
	int positiontable[100010];
	vector<polynomials>v;
	polynomials p1[10000];
	polynomials p2[10000];
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		p1[i].input();
		hashtable[p1[i].exponent]=true;
		positiontable[p1[i].exponent]=i;
		v.push_back(p1[i]);
	}

	scanf("%d",&m);
	for(int i=0;i<m;i++)
	{
		p2[i].input();
		if(hashtable[p2[i].exponent])  v[positiontable[p2[i].exponent]].coefficient += p2[i].coefficient;
		else 
		{
		v.push_back(p2[i]);
		n++;	
		}
	}
	 sort(v.begin(),v.end(),cmp) ;
	for(int i=0;i<v.size();i++)
	{
	  	if(v[i].coefficient ==0) n--;
	}
	 printf("%d ",n);
	 for(int i=0;i<v.size();i++)
	 {
	 	bool flag=false;
	 	for(int j=i+1;j<v.size();j++)
	 	{	
		 if(v[j].coefficient !=0)  
		 {
		 	flag=true;
		 	break;
		 }
	    }
	    
	 	if(v[i].coefficient !=0)
	 	{
	 	if(i<v.size()-1 && flag) printf("%d %.1lf ",v[i].exponent,v[i].coefficient);
	 	else  printf("%d %.1lf",v[i].exponent,v[i].coefficient);
	    }
	    
	 }
	//printf("%s","over");
	return 0;
}
