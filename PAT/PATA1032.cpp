#include<iostream>
using namespace std;
const int MAX=100000;
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
    //cin>>addr1>>addr2>>n;
    for(int m=0;m<MAX;m++)
{
	node[m].flag=false;
}
    scanf("%d%d%d",&addr1,&addr2,&n);
    for(int i=0;i<n;i++)
    {
        //cin>>pos>>c>>next;
        scanf("%d %c %d",&pos,&c,&next);
        node[pos].c=c;
        node[pos].next=next;
        //node[pos].flag=true;
        //node[i].pos=pos;
    }
    /*
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
            printf("%05d",addr2);
            break;
        }
        else
        {
            hashtable2[b]=true;
            addr2=node[addr2].next;
        }  
    }
    */
    while(node[addr1].next!=-1)
    {
    	node[addr1].flag=true;
    	addr1=node[addr1].next;
	}
	while(node[addr2].next!=-1)
	{
		if(node[addr2].flag)
		{
			flag=true;
			printf("%05d",addr2);
            break;
        }	
        addr2=node[addr2].next;
	}
    if(! flag) printf("-1");
    return 0;
}