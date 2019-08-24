#include<iostream>
#include<algorithm>
#include<vector>
const int MAX=100010;
using namespace std;
int main()
{
    int n,m;
    int mid;
    bool flag=false;
    int value[MAX];
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++)
        scanf("%d",&value[i]);
    sort(value,value+n);
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)   //用二分法查找另一个value值，否则会运行超时
        {
            mid=(n-1+j)/2; //得到中间位置
            if(value[i]+value[mid]==m)  //如果v1+v2=m，直接输入，并终止查找
            {
                 flag=true;
                 printf("%d %d",value[i],value[mid]);
                 break;
            }
            else
            {
                if(value[i]+value[mid]>m) n=mid; //如果v1+v2>m,截取数组左部分
                else j=mid;
            }
            
        }
     if(flag)  break; 
    }
    if(!flag) printf("No Solution");





    return 0;
}