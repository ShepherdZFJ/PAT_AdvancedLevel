#include<iostream>
using namespace std;
int main()
{
    double count=1;
	double game_rate[3][3];
	double sum;
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
	    scanf("%lf",&game_rate[i][j]);
	}
	for(int i=0;i<3;i++)
	{
		int position=0;
	    double temp;
	    
		temp=game_rate[i][0];
		for(int j=0;j<3;j++)
		{
		  if(game_rate[i][j]>temp)
		  {
		  	temp=game_rate[i][j];
		  	position=j;
		   }	
		}
		count=count*temp;
		if(position==0) printf("%c ",'W');
		else if (position==1) printf("%c ",'T');
		else printf("%c ",'L');
	}
	sum=(count*0.65-1)*2;
	printf("%.2lf",sum);
	return 0;
} 
