#include<iostream>
#include<vector>
#include<algorithm>
#include<string.h>
using namespace std;
class student_info
{
    public:
    int id;
    char name[10];
    int grade;
    void input();
};
void student_info::input()
{
    scanf("%d %s %d",&id,name,&grade);
}
bool cmp1(student_info a,student_info b)
{
    return a.id<b.id;
}
bool cmp2(student_info a,student_info b)
{
    if(strcmp(a.name,b.name)==0) return a.id<b.id;
    else return strcmp(a.name,b.name)<0;   
}
bool cmp3(student_info a,student_info b)
{
    if(a.grade==b.grade) return a.id<b.id;
    else return a.grade<b.grade; 
}
int main()
{
    int n,c;
    student_info s;
    vector<student_info>v;

    scanf("%d%d",&n,&c);
    for(int i=0;i<n;i++)
    {
        s.input();
        v.push_back(s);

    }
   if(c==1) sort(v.begin(),v.end(),cmp1);
   if(c==2) sort(v.begin(),v.end(),cmp2);
   if(c==3) sort(v.begin(),v.end(),cmp3);
    for(int i=0;i<v.size();i++)
    {
        printf("%06d %s %d\n",v[i].id,v[i].name,v[i].grade);
    }
    return 0;
}