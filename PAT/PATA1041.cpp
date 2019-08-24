#include<iostream>
#include<vector>
using namespace std;
const int MAX=100010;
int main()
{
    bool hashtable[MAX]={false};
    int count[MAX]={0};
    int n;
    vector<int>v;
    int number;
    bool flag=false;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&number);
        if(!hashtable[number])
        {
            v.push_back(number);
            hashtable[number]=true;
            count[number]=1;
        }
        else count[number]++;
    }
    for(int i=0;i<v.size();i++)
    {
        if(count[v[i]]==1)
        {
            flag=true;
            printf("%d",v[i]);
            break;
        }
    }
    if(!flag) printf("None");




    return 0;
}