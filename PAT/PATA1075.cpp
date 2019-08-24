#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
const int MAX1=100000;
const int MAX2=10;
bool hashTab[MAX1]={false};
bool hashtable[MAX1][MAX2]={false};
int hash_pos[MAX1]={0};
class submission
{
    public:
    int id;
    int p_no;
    int score;
    int total_score=0;
    int rank;
    //vector<int>p_score;
    int p_score[6]={-1,-1,-1,-1,-1,-1};
    int p_number=0;
};
bool cmp(submission a,submission b)
{
    if(a.total_score==b.total_score)
    {
        if(a.p_number==b.p_number)
        {
            return a.id<b.id;
        }
        else return a.p_number>b.p_number;
    }
    else return a.total_score>b.total_score;
}
int main()
{
    int n,k,m;
    int a[6];
    submission s;
    vector<submission>v;
    scanf("%d%d%d",&n,&k,&m);
    for(int i=1;i<=k;i++)
    {
        scanf("%d",&a[i]);
    }

    for(int i=0;i<m;i++)
    {
        scanf("%d%d%d",&s.id,&s.p_no,&s.score);
        for(int i=1;i<=k;i++)
        {
         	s.p_score[i]=-1;
        }
       
        if(hashTab[s.id]) //判断这个人有没有递交过
        {
                if(hashtable[s.id][s.p_no])   //判断这个人递交的题目以前有没有提交过
            {
                if(s.score>v[hash_pos[s.id]].p_score[s.p_no]) 
                {
                	int temp;
                	temp=s.score-v[hash_pos[s.id]].p_score[s.p_no];
                    v[hash_pos[s.id]].p_score[s.p_no]=s.score;
                    v[hash_pos[s.id]].total_score+=temp;
                    if(s.score==a[s.p_no])v[hash_pos[s.id]].p_number++;
                }    
            }
            else
            {
            	
                hashtable[s.id][s.p_no]=true;
                v[hash_pos[s.id]].p_score[s.p_no]=s.score;
                if(s.score==-1) s.score=0;
                v[hash_pos[s.id]].total_score+=s.score;
                if(s.score==a[s.p_no])v[hash_pos[s.id]].p_number++;
                //v.push_back(s);
                //hash_pos[s.id][s.p_no]=v.size()-1;
            }
        }
        else
        {
        	hashtable[s.id][s.p_no]=true;  //提交之后记录 
        	if(s.score>=0)
        	{
        		 hashTab[s.id]=true;
	             s.p_score[s.p_no]=s.score;
	             if(s.score==a[s.p_no]) s.p_number++;
	             s.total_score=s.score;
	             v.push_back(s);
	             hash_pos[s.id]=v.size()-1; 
			}
                        
        }
           
    }
    sort(v.begin(),v.end(),cmp);
    int temp=1;
    for(int i=0;i<v.size();i++)
    {
        if(i==0)
        {
            v[i].rank=1;
        }
        else
        {
            {
                if(v[i].total_score==v[i-1].total_score)
                {
                    v[i].rank=v[i-1].rank;
                }
                else v[i].rank=i+1;
            }
        }  
    }
    for(int i=0;i<v.size();i++)
    {
        printf("%d %05d %d ",v[i].rank,v[i].id,v[i].total_score);
        for(int j=1;j<=k;j++)
		{
			if(j<k)
			{
				if(hashtable[v[i].id][j])
			    {
				     if(v[i].p_score[j]>0) printf("%d ",v[i].p_score[j]);
				     else printf("0 ");
			    }
			    else printf("- ");
			}
			else
			{
				if(hashtable[v[i].id][j])
			    {
				     if(v[i].p_score[j]>0) printf("%d\n",v[i].p_score[j]);
				     else printf("0\n");
			    }
			    else printf("-\n");
			}
			
		} 
		
    }






    return 0;
}