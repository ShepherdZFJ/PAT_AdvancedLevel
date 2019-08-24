/*
 * @Author: MeiYing 
 * @Date: 2019-08-15 20:06:21 
 * @Last Modified by:   MeiYing 
 * @Last Modified time: 2019-08-15 20:06:21 
 */
#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
const int MAX=50;
int n,in[MAX],post[MAX];;
class node
{
    public:
    int data;
    node* lchild;
    node* rchild;
};
node* create(int postL,int postR,int inL,int inR)
{
    if(postL>postR)
    {
        return NULL;
    }
    node* root= new node();
    root->data=post[postR];
    int k;
    for(k=inL;k<=inR;k++)
    {
        if(in[k]==post[postR])
        {
            break;
        }
    }
    int numLeft=k-inL;
    root->lchild=create(postL,postL+numLeft-1,inL,k-1);
    root->rchild=create(postL+numLeft,postR-1,k+1,inR);
    return root;
}
void BFS(node* root)
{
    int count=0;
    queue<node*> q;
    q.push(root);
    while(!q.empty())
    {
        node* now=q.front();
        q.pop();
        count++;
        if(count<n) printf("%d ",now->data);
        else printf("%d",now->data);
        if(now->lchild!=NULL) q.push(now->lchild);
        if(now->rchild!=NULL) q.push(now->rchild);

    }
}

int main()
{
    scanf("%d",&n);
    node* root= new node();
    for(int i=0;i<n;i++)
    {
        scanf("%d",&post[i]);
    }
    for(int i=0;i<n;i++)
    {
        scanf("%d",&in[i]);
    }
    root=create(0,n-1,0,n-1);
    BFS(root);




    return 0;
}