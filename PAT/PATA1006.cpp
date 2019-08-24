#include<iostream>
#include<string>
#include<vector>
const int MAX=100010;
using namespace std;
class person
{
	public:
		char person_no[20];
		char c;
		int sign_in_h;
		int sign_in_m;
		int sign_in_s;
		int sign_out_h;
		int sign_out_m;
		int sign_out_s;
		void input();
		void print();
		int time_in_sum;
		int time_out_sum;	
};
void person::input()
{    
      //ע����������һ��%d���治���пո񣬷������벻�� 
	scanf("%s %d %c %d %c %d %d %c %d %c %d",&person_no,&sign_in_h,&c,&sign_in_m,&c,&sign_in_s,&sign_out_h,&c,&sign_out_m,&c,&sign_out_s);   
}
/*
void person::print()
{
	printf("%s, %d,%d,%d",person_no,h,m,s);
}
*/
int main()
{
    int n;
    int temp_in=0;
    int temp_out=0;
    int person_in=0,person_out=0;
	person p;
	vector<person>v;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
	  p.input();
	  p.time_in_sum=3600*p.sign_in_h+60*p.sign_in_m+p.sign_in_s;
	  p.time_out_sum=3600*p.sign_out_h+60*p.sign_out_m+p.sign_out_s;
		v.push_back(p);
    }
	  temp_in=v[0].time_in_sum;
	  temp_out=v[0].time_out_sum;
	 for(int i=0;i<v.size();i++)   
	{
		if(v[i].time_in_sum<temp_in)
		{
			temp_in=v[i].time_in_sum;
			person_in=i;	
		}
		if(v[i].time_out_sum>temp_out)
		{
			temp_out=v[i].time_out_sum;
			person_out=i;	
		}
	}
	printf("%s %s",v[person_in].person_no,v[person_out].person_no);
	return 0;
}
