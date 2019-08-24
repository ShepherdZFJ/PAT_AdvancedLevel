#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;
class student_info
{
   public:
   string name;
   char sex;
   string id;
   int grade;
   void input();
};
void student_info::input()
{
    cin>>name>>sex>>id>>grade;
}
bool cmp1(student_info a,student_info b)
{
    return a.grade<b.grade;
}
bool cmp2(student_info a,student_info b)
{
    return a.grade>b.grade;
}
int main()
{
    int n;
    student_info s;
    vector<student_info>v1,v2;
    bool empty_F=false,empty_M=false;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        s.input();
        if (s.sex=='M') v1.push_back(s);
        else v2.push_back(s);
    }
sort(v1.begin(),v1.end(),cmp1);
sort(v2.begin(),v2.end(),cmp2);
if(v1.size()==0) empty_M=true;
if(v2.size()==0) empty_F=true;
if(!empty_M && !empty_F)
{
    int temp;
    cout<<v2[0].name<<" "<<v2[0].id<<endl;
    cout<<v1[0].name<<" "<<v1[0].id<<endl;
    temp=v2[0].grade - v1[0].grade;
    cout<<temp<<endl;
}
else
{
    //cout<<"Absent"<<endl;
    if(!empty_F) cout<<v2[0].name<<" "<<v2[0].id<<endl;
    else cout<<"Absent"<<endl;
    if(!empty_M) cout<<v1[0].name<<" "<<v1[0].id<<endl;
    else cout<<"Absent"<<endl;
    cout<<"NA"<<endl;
}


    return 0;
}


