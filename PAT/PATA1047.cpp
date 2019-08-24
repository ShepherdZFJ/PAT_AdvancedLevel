#include<iostream>
#include<vector>
#include<string>
#include<string.h>
#include<algorithm>
using namespace std;
const int MAX=100010;
bool hashtable[MAX]={false};
int hashtable_pos[MAX]={0};
class student
{
    public:
        vector<string>name;
        int cno;

};
bool cmp(string a,string b)
{
    //return strcmp(a.c_str,b.c_str)<0;
    return a<b;
}
int main()
{
    int n,k,c;
    string id;
    student s;
    vector<student>v;
    //scanf("%d %d",&n,&k);
    cin>>n>>k;
    for(int i=0;i<n;i++)
    {
       // scanf("%s",id);
         cin>>id;
        //scanf("%d",&c);
        cin>>c;
        for(int j=0;j<c;j++)
        {
            //scanf("%d",&s.cno);
            cin>>s.cno;
            if(hashtable[s.cno])
            {
                v[hashtable_pos[s.cno]].name.push_back(id);

            }
            else
            {
                hashtable[s.cno]=true;
                s.name.push_back(id);
                v.push_back(s);
                hashtable_pos[s.cno]=v.size()-1;
            }
            s.name.clear();
        }

    }
    for(int i=1;i<=k;i++)
    {
        if(hashtable[i])
        {
            sort(v[hashtable_pos[i]].name.begin(),v[hashtable_pos[i]].name.end(),cmp);
            cout<<i<<" "<<v[hashtable_pos[i]].name.size()<<endl;
            for(int x=0;x<v[hashtable_pos[i]].name.size();x++)
            {
               cout<<v[hashtable_pos[i]].name[x]<<endl;
            }
        }
    }
    



    return 0;
}