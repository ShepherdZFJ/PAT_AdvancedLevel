#include<iostream>
#include<string>
#include<map>
using namespace std;
const int max_n=1000;
const int max_m=1000;
const int MAX=100010;
int color[max_m][max_n];
//int hashtable[MAX]={0};
int main()
{
    int m,n;
    map<string,int>mp;
    string str;
    int count=0;
    string temp;
    //scanf("%d %d",&m,&n);
    cin>>m>>n;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            /*
            scanf("%d",&color[i][j]);
            hashtable[color[i][j]]++;
            if(hashtable[color[i][j]]>count)
            {
                count=hashtable[color[i][j]];
                temp=color[i][j];
            }
            */
           cin>>str;
           if(mp.count(str)) mp[str]++;
           else mp[str]=1;
           if(mp[str]>count)
            {
                count=mp[str];
                temp=str;
            }
           
        }
    }
    cout<<temp<<endl;



    return 0;
}