#include<iostream>
using namespace std;
const int MAX=100005;
class node
{
    public:
    char c;
    int next;
    bool flag;
   // int pos;
}node[MAX];
int main()
{
    bool hashtable1[200],hashtable2[200];
    bool flag;
    int n,addr1,addr2;
    int pos,next;
    char c;
    cin>>addr1>>addr2>>n;
    for(int i=0;i<n;i++)
    {
        cin>>pos>>c>>next;
        node[pos].c=c;
        node[pos].next=next;
        node[pos].flag=true;
        //node[i].pos=pos;
    }
    while(node[addr1].flag)
    {
        int a;
        a=node[addr1].c;
        hashtable1[a]=true;
        addr1=node[addr1].next;
    }
    while(node[addr2].flag)
    {
        int b;
        b=node[addr2].c;
        if(hashtable1[b])
        {
            flag=true;
            cout<<addr2;
            break;
        }
        else
        {
            hashtable2[b]=true;
            addr2=node[addr2].next;
        }  
    }
    if(! flag) cout<<-1;
    return 0;
}
