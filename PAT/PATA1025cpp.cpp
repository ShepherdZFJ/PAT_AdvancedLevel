#include<iostream> 
#include<string.h>
#include<algorithm>
using namespace std;
class student
{
public:
	char sno[15];
	int score;
	int exam_room_number;
	int exam_room_rank;
	int rank;
//	void input();
} stu[50000];
bool cmp(student a,student b)
{
	if(a.score != b.score) return a.score>b.score;
	else return strcmp (a.sno,b.sno) < 0;
}
/*
void student::input()
{
	scanf("%s%d",sno,&score);
}
*/
int main()
{
   int n,m;
   int k=0;
   int x=0;
   scanf("%d",&n);
   for(int i=0;i<n;i++)	
   {
   	scanf("%d",&m);
   	x=x+m;
   	for(int j=k+0;j<k+m;j++)
   	{
   	    scanf("%s%d",stu[j].sno,&stu[j].score);
		stu[j].exam_room_number=i+1;	
	}
	sort(stu+k,stu+k+m,cmp);
	stu[k].exam_room_rank=1;
	for(int s=k+1;s<k+m;s++)
	{
		if(stu[s].score == stu[s-1].score)
		{
			stu[s].exam_room_rank=stu[s-1].exam_room_rank;
		}
		else 
	         stu[s].exam_room_rank=s-k+1;
     	
	}
	k=k+m;	
   }
   int rank=1;
   sort(stu,stu+x,cmp);
   stu[0].rank=1;
   for(int i=1;i<x;i++)
   {
   	if(stu[i].score == stu[i-1].score)  stu[i].rank=stu[i-1].rank;
   	else stu[i].rank=i+1;
   }
	for(int i=0;i<x;i++)
	{
		printf("%s %d %d %d\n",stu[i].sno,stu[i].rank,stu[i].exam_room_number,stu[i].exam_room_rank);
	}
		
	return 0;
}
