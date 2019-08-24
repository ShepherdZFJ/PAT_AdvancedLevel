#include<iostream> 
#include<vector>
using namespace std;
const int maxn=100010;
struct school
{
public:
int sno;
int score;
void input();	
void print();
};
void school::input()
{
	scanf("%d%d",&sno,&score);
}
void school::print()
{
	printf("%d ",score); 
}
int main()
{
	int n;
	bool flag;
	int max,m;
	vector<school>v1,v2;
    school school[maxn]	;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    school[i].input();
    /*
	for(int i=0;i<n;i++)
    {
    		
	printf("%d ",school[i].score);
	}
    
   */
   for(int i=0;i<n;i++)
   v1.push_back(school[i]);
   
	for(int i=0;i<n;i++)
	{

		flag=true;
		//v.push_back(school[i]);
	    for(int j=0;j<v2.size();j++)
	    {
	    	if(v1[i].sno==v2[j].sno)
	        {
	    	v2[j].score=v2[j].score+v1[i].score;
	    	flag=false;
			break;
		    }
		    //if(flag==false) break;
		}

	   if(flag)  v2.push_back(school[i]);
	}
	/*
	for(int i=0;i<v2.size();i++)
	printf("%d %d\n",v2[i].sno,v2[i].score);
	*/  
     max=-1;
	for(int i=0;i<v2.size();i++)
    {
    
      if(v2[i].score>max)
      {
      	max=v2[i].score;
      	m=v2[i].sno;
	  }
	}
	
    printf("%d %d",m,max);
    
	return 0;
}
