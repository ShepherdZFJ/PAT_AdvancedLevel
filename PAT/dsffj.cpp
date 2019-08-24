#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;
const int MAX=100010;
int hashtable[MAX]={0};
/* 
bool isOrder(vector<int>v)
{
    bool flag=true;
    for(int i=0;i<v.size();i++)
    {
        if(v[i]!=i)
        {
            flag=false;
            break;
        }
    }
    return flag;
}
*/

int toSwap(vector<int>v)
{
    int count=0;
    int pos,temp;
    vector<int>::iterator it; 
    //bool flag=true;
    while(count<10)
    {
        pos=hashtable[0];
        if(pos!=0)
       {
            temp=hashtable[v[hashtable[pos]]];
            //swap(v[pos],v[hashtable[pos]]);
            it=v.begin()+hashtable[pos];
            v.erase(it);
            hashtable[v[hashtable[pos]]]=0;
            hashtable[0]=temp; 
                  
       }
       else
       {
           /*
           int x;
          map<int,bool>::iterator it;
          it=mp.find(true);
          if(it!=mp.end())
          {
              x=it->first;
          }
          */
          it=v.begin();
         
          temp=hashtable[*it];
          swap(v[pos],*it);
          hashtable[*it]=0;
          hashtable[0]=temp;      
       }
       
       count++;
    }
    return count;
}
int main()
{
    int n,m;
    int count;
    int k=0;
    vector<int>v;
    map<int,bool>mp;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&m);
        if(m!=i) 
        {
            v.push_back(m);
            hashtable[m]=v.size()-1;
        }
        
        
        
    }
 count=toSwap(v);
    printf("%d",count);
    return 0;
}

