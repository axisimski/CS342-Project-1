#include "lab10List.h"
int main (int argc, char** argv)
{
  MyList int1;
  MyList int2;
  MyList int3;
  MyList int4;
  MyList int5; 
  
  printf ("\nEnter input \n");
  
  int x;
  int set1;
  int set2;
  int val;
  int s1;
  int s2;
  int s3;
  while(x!=-6){
  	
	   scanf("%d", &x);
	   
	   if(x==-1){
	   	
	   	scanf("%d", &set1);
	   	scanf("%d", &val);
	   	
		   	if(set1==1){	   		 
	   		 int1.insert(val);	   		
		    }
		    
			if(set1==2){   		 
	   		 int2.insert(val);	   		
		    }
		   
		   	if(set1==3){	   		 
	   		 int3.insert(val);	   		
		    }
		    
		   	if(set1==4){	   		 
	   		 int4.insert(val);	   		
		    }
		    
		    if(set1==5){	   		 
	   		 int5.insert(val);	   		
		    }
	     	
	     }
	   
	   if(x==-2){
	   	    printf("Showing");
	   		scanf("%d", &set1);	   		
	   		if(set1==1){	   			
	   			int1.show();
			   }
			   
		 	if(set1==2){	   			
	   			int2.show();
			   } 
			   
			 if(set1==3){	   			
	   			int3.show();
			   }   
	   		if(set1==4){	   			
	   			int4.show();
			   } 
			 if(set1==5){	   			
	   			int5.show();
			   }   
			   
		}
		
		
		 if(x==-3){
	   	
	   		scanf("%d", &set2);	   		
	   		if(set2==1){	   			
	   			int1.removeAll();
			   }
			   
		 	if(set2==2){	   			
	   			int2.removeAll();
			   } 
			   
			 if(set2==3){	   			
	   			int3.removeAll();
			   }   
	   		if(set2==4){	   			
	   			int4.removeAll();
			   } 
			 if(set2==5){	   			
	   			int5.removeAll();
			  }   
			   
		}
		
		
		if(x==-4){
			
			MyList tmp;
			MyList tmp2;
			MyList tmp3;
			
			printf("Enter sets;");
			
			scanf("%d", &s1);
			scanf("%d", &s2);
			scanf("%d", &s3);
			
				if(s1>5||s2>5||s3>5){
				
				printf("Invalid input\n");
				break;
			}
		
			
			if(s2==1){				
				 tmp2=int1;				
			}			
			if(s2==2){				
				 tmp2=int2;				
			}
			if(s2==3){				
				 tmp2=int3;				
			}
			if(s2==4){				
				 tmp2=int4;				
			}
			if(s2==5){				
				 tmp2=int5;				
			}
			//=====================================
			if(s3==1){				
				 tmp3=int1;				
			}			
			if(s3==2){				
				 tmp3=int2;				
			}
			if(s3==3){				
				 tmp3=int3;				
			}
			if(s3==4){				
				 tmp3=int4;				
			}
			if(s3==5){				
				 tmp3=int5;				
			}
			
		 
			
			
			int y=tmp2.getLength()+tmp3.getLength();
			
		
			for(int i=0;i<y;i++){
				int n=tmp2.top();
				int n2=tmp3.top();
				tmp2.pop();
				tmp3.pop();	
				
				if(tmp.exists(n)!=1){
					 tmp.insert(n);
				}		 
			
			   if(tmp.exists(n2)!=1){
					 tmp.insert(n2);
				}		 
						   			
			}	 
			
			if(s1==1){				
				 int1=tmp;				
			}			
			if(s1==2){				
				 int2=tmp;				
			}
			if(s1==3){				
				 int3=tmp;				
			}
			if(s1==4){				
				 int4=tmp;				
			}
			if(s1==5){				
				 int5=tmp;				
			}
			
		 
	//		delete(tmp);
			
		}
		
		
		
		
			if(x==-5){
			
			MyList tmp;
			MyList tmp2;
			MyList tmp3;
			
			printf("Enter sets;");
			
			scanf("%d", &s1);
			scanf("%d", &s2);
			scanf("%d", &s3);
			
			if(s1>5||s2>5||s3>5){
				
				printf("Invalid input\n");
				break;
			}
		
			
			if(s2==1){				
				 tmp2=int1;				
			}			
			if(s2==2){				
				 tmp2=int2;				
			}
			if(s2==3){				
				 tmp2=int3;				
			}
			if(s2==4){				
				 tmp2=int4;				
			}
			if(s2==5){				
				 tmp2=int5;				
			}
			
			if(s3==1){				
				 tmp3=int1;				
			}			
			if(s3==2){				
				 tmp3=int2;				
			}
			if(s3==3){				
				 tmp3=int3;				
			}
			if(s3==4){				
				 tmp3=int4;				
			}
			if(s3==5){				
				 tmp3=int5;				
			}
			
			if(s1==1){				
				 tmp=int1;				
			}			
			if(s1==2){				
				 tmp=int2;				
			}
			if(s1==3){				
				 tmp=int3;				
			}
			if(s1==4){				
				 tmp=int4;				
			}
			if(s1==5){				
				 tmp=int5;				
			}
			
			
			int y=tmp2.getLength()+tmp3.getLength();
			
		
			for(int i=0;i<y;i++){
				int n=int2.top();
				int n2=int3.top();
				int2.pop();
				int3.pop();	
				
				if(tmp.exists(n)!=1){
					
					if(tmp3.exists(n)==1);
					 tmp.insert(n);
				}		 
			
			  if(tmp.exists(n2)!=1){
					
					if(tmp2.exists(n2)==1);
					 tmp.insert(n);
				}	 
						   			
			}	 
			
			if(s1==1){				
				 int1=tmp;				
			}			
			if(s1==2){				
				 int2=tmp;				
			}
			if(s1==3){				
				 int3=tmp;				
			}
			if(s1==4){				
				 int4=tmp;				
			}
			if(s1==5){				
				 int5=tmp;				
			}
			
		// delete(tmp);
			
			
		}
		
		
		
	   	
}
  
   
  	
 
 
  
  
  
  
  
  
  
  

  return 1;
}
