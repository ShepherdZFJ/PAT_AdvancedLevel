#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
class man
{
    public:
    int id;
    int talent;
    int virtue;
    int sum_score;
    int priority;

};
bool cmp(man a,man b)
{
    if(a.priority==b.priority)
    {
        if(a.sum_score==b.sum_score)
        {
            if(a.virtue==b.virtue) return a.id<b.id;
            else return a.virtue>b.virtue;
        }
        else return a.sum_score>b.sum_score;
    }
    else return a.priority<b.priority;
}
int main()
{
    man m;
    vector<man>v;
    int n,low,high;
    scanf("%d%d%d",&n,&low,&high);
    for(int i=0;i<n;i++)
    {
        scanf("%d%d%d",&m.id,&m.virtue,&m.talent);
        if(m.virtue>=low && m.talent>=low)
        {
            if(m.virtue>=high && m.talent>=high)
            {
                m.sum_score=m.virtue+m.talent;
                m.priority=1;  //sageMAN
            }
            else if(m.virtue>=high && m.talent<high)
            {
                m.sum_score=m.virtue+m.talent;
                m.priority=2;  //nobleman
            }
            else if(m.virtue<high && m.talent<high && (m.virtue>=m.talent))
            {
                m.sum_score=m.virtue+m.talent;
                m.priority=3;  //foolman

            }
            else
            {
                m.sum_score=m.virtue+m.talent;
                m.priority=4;  //smallman

            }
            v.push_back(m);
        }
    }
    printf("%d\n",v.size());
    sort(v.begin(),v.end(),cmp);
    for(int i=0;i<v.size();i++)
    {
        printf("%d %d %d\n",v[i].id,v[i].virtue,v[i].talent);
    }



    return 0;
}


         