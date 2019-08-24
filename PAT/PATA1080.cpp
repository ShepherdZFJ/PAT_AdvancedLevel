/*
 * @Author: MeiYing 
 * @Date: 2019-08-09 10:57:37 
 * @Last Modified by: MeiYing
 * @Last Modified time: 2019-08-10 15:08:25
 */
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class student
{
    public:
    int sno;
    int exam_grade;
    int interview_grade;
    int final_grade;
    vector<int>school;

    /* 
    int school1;
    int school2;
    int school3;
    */
};
bool cmp(student a,student b)
{
    if(a.final_grade==b.final_grade)
    {
        return a.exam_grade>b.exam_grade; 
    }
    else
    {
        return a.final_grade>b.final_grade;
    }
    
}
bool cmp2(student a,student b)
{
    return a.sno<b.sno;
}
int main()
{
    int n;//学生人数
    int m;//学校数量
    int k;//可报考志愿学校数量
    int school_no;
   // int temp=0;
    bool hashtable[100000]={false};
    int cnt[110]={0};
    student s;
    vector<student> sch[110],stu;
    int school_capacity[110];
    scanf("%d%d%d",&n,&m,&k);
    for(int i=0;i<m;i++)
    {
        scanf("%d",&school_capacity[i]);
    }
    for(int i=0;i<n;i++)
    {
        scanf("%d%d",&s.exam_grade,&s.interview_grade);
        s.sno=i;
        s.final_grade=s.exam_grade+s.interview_grade;
        s.school.clear();
        for(int j=0;j<k;j++)
        {
            scanf("%d",&school_no);
            s.school.push_back(school_no);
            //v[school_no].push_back(s);
        }
        stu.push_back(s);
    }
    sort(stu.begin(),stu.end(),cmp);
    for(int i=0;i<n;i++)
    {   //注意：录取规则是从高分开始录取，假如这个人的第一志愿学校已经录取满了，那么立即考虑他的第二志愿
        int lastindex;
        for(int j=0;j<k;j++)
        {
            int schid=stu[i].school[j];
            if(cnt[schid]<school_capacity[schid])
            {
                sch[schid].push_back(stu[i]);
                cnt[schid]++;
                break;
            }
            else
            {
                lastindex=sch[schid].size()-1;
                if(stu[i].final_grade==sch[schid][lastindex].final_grade && stu[i].exam_grade==sch[schid][lastindex].exam_grade)
                {
                    sch[schid].push_back(stu[i]);
                    cnt[schid]++;
                    break;
                }
            }
            

        }
    }
    for(int i=0;i<m;i++)
    {
        if(sch[i].size()>0)
        {
            sort(sch[i].begin(),sch[i].end(),cmp2);
            for(int j=0;j<sch[i].size();j++)
            {
                if(j<sch[i].size()-1) printf("%d ",sch[i][j].sno);
                else printf("%d\n",sch[i][j].sno);
            }
        }
        else
        {
            printf("\n");
        }
        
    }
    







    return 0;
}
