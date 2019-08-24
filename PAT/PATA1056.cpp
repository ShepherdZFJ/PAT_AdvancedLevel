#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
const int MAX=100010;
int hashtable[MAX]={0};
int getMax(vector<int>v)
{
    sort(v.begin(),v.end());
    return v[v.size()-1];

}
int main()
{
    int n,m;
    int win;
    vector<int>v,v_weight,v_win;
    int weight[1010],order[1010];
    int rank[1010];
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++) 
    {
        scanf("%d",&weight[i]);  //输入mouse的重量 
        hashtable[weight[i]]=i;  //将相应的重量的位置存在hash表中方便后续排名 
    }
    for(int i=0;i<n;i++)
    {
        scanf("%d",&order[i]);  //输入初始排序 
        v_weight.push_back(weight[order[i]]);   //将排序之后的重量假如到向量中 
        /*
        if(v.size()<m)   v.push_back(weight[order[i]]);
        else
        {
            win=getMax(v);
            v_win.push_back(win);
            v.clear();
        }
        */
    }
    while(v_weight.size()>1)  //进行排名比较 
    {
        for(int i=0;i<v_weight.size();i++)  //考虑最后一个值的情况 
        {
            if(v.size()<m && i<v_weight.size() -1) v.push_back(v_weight[i]);
            else
            {
            	if(i==v_weight.size()-1 && v.size()<m) v.push_back(v_weight[i]);
            	else  i=i-1;
                win=getMax(v);
                v_win.push_back(win);
                v.clear();
               
            }
        }
        for(int x=0;x<v_weight.size();x++)
        {
            rank[hashtable[v_weight[x]]]=v_win.size()+1;
        }
        if(v_win.size()==1) rank[hashtable[v_win[0]]]=1;
        v_weight=v_win;
        v_win.clear();
    }
    for(int i=0;i<n;i++)
    {
        if(i<n-1) printf("%d ",rank[i]);
        else printf("%d",rank[i]);
    }





    return 0;
}
