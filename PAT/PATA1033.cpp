/*
 * @Author: MeiYing 
 * @Date: 2019-07-13 13:18:31 
 * @Last Modified by: MeiYing
 * @Last Modified time: 2019-07-13 13:19:17
 */

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class station
{
    public:
           double price;
           double distance;
};
bool cmp(station a,station b)
{
    return a.distance<b.distance;
}
int main()
{
    double capacity;   //油箱最大容量
    double distance;   //到目的地的距离
    double v_avg;      //平均速度
    int n;          //加油站数量
    station sta;
    vector<station>v;
    double s=0;
    int m=1;
    double sum=0,p;
    int pos;
    double temp;
    double c_max;
    double c_leave=0;
    int dis;
    scanf("%lf%lf%lf%d",&capacity,&distance,&v_avg,&n);
    sta.price=0;
    sta.distance=distance;
    v.push_back(sta); //将终点加到向量v中，方便后续判断。
    for(int i=0;i<n;i++)
    {
        scanf("%lf%lf",&sta.price,&sta.distance);
        v.push_back(sta);
    }
    sort(v.begin(),v.end(),cmp); //将加油站的顺序距离从近到远排序一边
    p=v[0].price;
    c_max=capacity;   //把油箱最大容量赋值给c_max,方便后面利用其计算。
    for(int i=0;i<v.size();i++)
    {
        double p_min=-1;
        bool flag1=false;
        bool flag2=false;
        bool flag=false;
        s+=v_avg*50;   //s为当前加油站加满油能跑到距离
        if(v[0].distance!=0) s=0;  //如果第一个加油站距离不为0，那么车子没法加油，直接不能到达最终目的地。
        temp=p;
        while(s>=v[m].distance)  //说明以当前加油站加满油能跑的距离路途中有加油站
        { 
            flag=true;    //说明加满油的路途中至少有一个加油站可以加油续航，否则说明不能到达目的地，终止算法。
            if(p>v[m].price)  //存在加油站比当前油价低
            {
                flag1=true;   //根据这个值去判断要不要统计途中没出现油价比当前低的，获得途中较低的油价
                p=v[m].price;
                pos=m;
            }
            else 
            {
                if(!flag1) //途中没出现油价比当前油价低的加油站
                {
                    if(!flag2) //将当前加油站的下一个加油站的油价赋值给p_min,方便后面比较得出较低油价
                    {
                        p_min=v[m].price;
                        pos=m;
                        flag2=true; 
                    }
                    else 
                    {
                        if(p_min>v[m].price)  p_min=v[m].price; //通过比较得出较低油价的加油站
                        pos=m;
                    }
                }
            }       
            m++;
            if(flag1) break; //一旦发现比当前油价低的加油站，终止寻找算法，该加油站为下一个加油目的地。
        }
        //------------------------------------------------统计路费：以下是路费的计算逻辑
        if(!flag1) //没有找到比当前油价低的加油站
        {
             p=p_min; //没有找到比当前油价低的加油站，所以把找到的较低的油价赋值给p
             sum+=temp*capacity; //没有找到比当前油价低的加油站，所以在该加油站把油箱加满，这样满足成本最低算法逻辑
             capacity=((v[pos].distance-v[i].distance)/v_avg); //消耗掉的油=油箱可加油的容量
             c_leave=c_max-((v[pos].distance-v[i].distance)/v_avg); //油箱所剩的油
        }
        else //找到了比当前油价低的加油站
        {
            if(((v[pos].distance-v[i].distance)/v_avg)>c_leave)  //如果到油价低的加油站需要的油大于油箱剩余的
            {
                sum+=temp*(((v[pos].distance-v[i].distance)/v_avg)-c_leave); 
                c_leave=0;
            }   
            else //如果到油价低的加油站需要的油小于或等于油箱剩余的
            {
                sum+=temp*c_leave;
                c_leave -=((v[pos].distance-v[i].distance)/v_avg);
            }
                
        }
        
        if(p==0) break;  //p=0说明已经到达终点目的地，退出算法
        if(!flag)  break;  //flag=false说明当前加油站加满油也跑不到下一个加油站了，此时没必要继续，终止算法。
        s=v[pos].distance;
        i=pos-1;
        
    }
    if(p==0) printf("%.2lf",sum);
    else
    {
        printf("The maximum travel distance = %.2lf",s);
    } 

    return 0;
}