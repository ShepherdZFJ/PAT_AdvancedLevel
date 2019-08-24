#include<iostream> 
using namespace std;
int main()
{
	int n;
	char c;
	double m;
	//scanf("%d",&n);
	//scanf("%c",&c);
	cin>>n>>c;
	m= double(n)/2;
	if(m<n/2+0.5) m=n/2;
	else m=n/2+1;
    for(int i=1;i<=m;i++)
	{
		if(i==1 || i==m)
		{
		  for(int j=0;j<n;j++)
          {
	        if(j<n-1) cout<<c;     //printf("%c",c);
             else cout<<c<<endl;  //printf("%c\n",c);
	      }
  	    }  
		  else
		  {
		  	for(int j=0;j<n;j++)
		  	{
		  		if(j==0)   cout<<c;  //printf("%c",c);		
			    else if(j==n-1) cout<<c<<endl;  //printf("%c\n",c);
				else cout<<" ";    //printf("%c",' ');			
			    
			}
		  }    	
			
	}
	return 0;
}
