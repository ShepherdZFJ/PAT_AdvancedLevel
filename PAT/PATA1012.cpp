#include<iostream> 
#include<algorithm>
#include<vector>
#include<string.h>
const int MAX=100010;
using namespace std;
class grade
{
	public:
		char sno[6];
		int score_C;
		int score_M;
		int score_E;
		double score_AVG;
		void input();
		void print();
		void cal_avg();
};
void grade::input()
{
	scanf("%s %d %d %d",&sno,&score_C,&score_M,&score_E);
}
void grade::print()
{
	printf("%s %d %d %d %lf",sno,score_C,score_M,score_E,score_AVG);
}
void grade::cal_avg()
{
	score_AVG=double((score_C+score_M+score_E))/3;
}
bool cmp_C(grade a,grade b)
{
	return a.score_C>b.score_C;

}
bool cmp_M(grade a,grade b)
{
	return a.score_M>b.score_M;

}
bool cmp_E(grade a,grade b)
{
	return a.score_E>b.score_E;

}
bool cmp_AVG(grade a,grade b)
{
	return a.score_AVG>b.score_AVG;

}
int main()
{
	char student_no[6];
	grade gra[10000];
	vector<grade>rank_C;
	vector<grade>rank_M;
	vector<grade>rank_E;
	vector<grade>rank_AVG;
	int n,m;
	scanf("%d",&n);
	scanf("%d",&m);
	for(int i=0;i<n;i++)
	{
	  gra[i].input();
	  gra[i].cal_avg();	
	  rank_C.push_back(gra[i]);
	  rank_M.push_back(gra[i]);
	  rank_E.push_back(gra[i]);
	  rank_AVG.push_back(gra[i]);
	}
//	for(int i=0;i<n;i++)
//	gra[i].print();in
sort(rank_C.begin(),rank_C.end(),cmp_C);
sort(rank_M.begin(),rank_M.end(),cmp_M);
sort(rank_E.begin(),rank_E.end(),cmp_E);
sort(rank_AVG.begin(),rank_AVG.end(),cmp_AVG);
for(int i=0;i<m;i++)
{   
    int best_rank;
    char best_subject;
    int position_C=1;
    int position_M=1;
    int position_E=1;
    int position_AVG=1;
	bool flag=true;
	scanf("%s",&student_no);
	for(int x=0;x<rank_C.size();x++)
	{
		if(x>0 && rank_C[x].score_C<rank_C[x-1].score_C) position_C++;
		if(strcmp(rank_C[x].sno,student_no)==0)
		{
			flag=false;
			break;
		}
	}
	if(flag) 
	{
	  printf("N/A\n");
	  continue;	
	}
	for(int x=0;x<rank_M.size();x++)
	{
		if(x>0 && rank_M[x].score_M<rank_M[x-1].score_M) position_M++;
		if(strcmp(rank_M[x].sno,student_no)==0) break;
	}
	for(int x=0;x<rank_E.size();x++)
	{
		if(x>0 && rank_E[x].score_E<rank_E[x-1].score_E) position_E++;
		if(strcmp(rank_E[x].sno,student_no)==0) break;
	}
	for(int x=0;x<rank_AVG.size();x++)
	{
		if(x>0 && rank_AVG[x].score_AVG<rank_AVG[x-1].score_AVG) position_AVG++;
		if(strcmp(rank_AVG[x].sno,student_no)==0) break;
	}
	if(position_AVG<=position_C)
	{
		best_rank=position_AVG;
		best_subject='A';	
	}
	else
	{
		best_rank=position_C;
		best_subject='C';	
	}
	if(position_M<best_rank)
	{
		best_rank=position_M;
		best_subject='M';
	}
	if(position_E<best_rank)
	{
		best_rank=position_E;
		best_subject='E';
	}
	printf("%d %c\n",best_rank,best_subject);
	
}
	return 0;
}
