#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<algorithm>
using namespace std;
class student_info
{
    public:
   // int cno;
    string id;
    vector<int>cno;
};
int toInt(char a[])
{
    int count=0;
    for(int i=0;i<4;i++)
    count+=a[i]-'0';
    return count;
}
/*
bool cmp(int a,int b)
{
    return a<b;
}
*/
int main()
{
    int n,k;
    int course_no,stu_number;
    //char name[10];
    string name;
    student_info s;
    vector<student_info>v;
    map<string, int> m; 
   // scanf("%d%d",&n,&k);
   cin>>n>>k;
    for(int i=0;i<k;i++)
    {
        //scanf("%d%d",&course_no,&stu_number);
        cin>>course_no>>stu_number;
        for(int j=0;j<stu_number;j++)
        {
            //int pos;
            //scanf("%s",s.id);
           // pos=toInt(s.id);
            cin>>s.id;
            if(m.count(s.id)>0)
            {
                v[m[s.id]].cno.push_back(course_no);
            }
            else
            {
            	s.cno.push_back(course_no);
                v.push_back(s);
                //hashtable[pos]=true;
                //hashtable_pos[pos]=v.size()-1;
                m[s.id]=v.size()-1;
                s.cno.clear();
            }           
            //s.cno=course_no;
        }
    }
    for(int i=0;i<n;i++)
    {
        //int temp;
        //scanf("%s",name);
        //temp=toInt(name);
        cin>>name;
        if(m.count(name))
        {
            sort(v[m[name]].cno.begin(),v[m[name]].cno.end());
            //printf("%s %d ",name,v[hashtable_pos[temp]].cno.size());
            cout<<name<<" "<<v[m[name]].cno.size()<<" ";
            for(int x=0;x<v[m[name]].cno.size();x++)
            {
                if(x<v[m[name]].cno.size()-1) cout<<v[m[name]].cno[x]<<" ";
                //printf("%d ",v[m[name]].cno[x]);
                else cout<<v[m[name]].cno[x];
                //printf("%d",v[hashtable_pos[temp]].cno[x]);
            }
        }
        else
        {
           // printf("%s 0",name);
           cout<<name<<" 0";
        }
        cout<<endl;
                
    }



    return 0;
}
