#include<iostream>
#include<vector>
#include<string.h>
#include<algorithm>
using namespace std;
class student
{
   public:
   char name[11];
   char sno[11];
   int grade;
   void input();
};
void student::input()
{
    scanf("%s %s %d",&name,&sno,&grade);
}
bool cmp(student a,student b)
{
    if(a.grade!=b.grade) return a.grade>b.grade;
    else return strcmp (a.sno,b.sno) < 0;
}
int main()
{
    student s;
    vector<student>v1,v2;
    int n,grade1,grade2;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
       s.input();
       v1.push_back(s);
    }
    scanf("%d %d",&grade1,&grade2);
    for(int i=0;i<v1.size();i++)
    {
        if(v1[i].grade>=grade1 && grade2>=v1[i].grade)  v2.push_back(v1[i]);
    }
    if(v2.size()==0)  printf("NONE\n");
    else
    {
        sort(v2.begin(),v2.end(),cmp);
        for(int i=0;i<v2.size();i++)
        {
            printf("%s %s\n",v2[i].name,v2[i].sno);
        }
    }


    return 0;
}