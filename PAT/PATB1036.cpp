#include<iostream> 
using namespace std;
int main()
{
	int n;
	char c;
	double m;
	scanf("%d %c",&n,&c);
	//scanf("%c",&c);
	m= double(n)/2;
	if(m<n/2+0.5) m=n/2;
	else m=n/2+1;
    for(int i=1;i<=m;i++)
	{
		if(i==1 || i==m)
		{
		  for(int j=0;j<n;j++)
          {
	        if(j<n-1) printf("%c",c);
             else printf("%c\n",c);
	      }
  	    }  
		  else
		  {
		  	for(int j=0;j<n;j++)
		  	{
		  		if(j==0)printf("%c",c);		
			    else if(j==n-1) printf("%c\n",c);
				else printf("%c",' ');			
			    
			}
		  }    	
			
	}
	return 0;
}
