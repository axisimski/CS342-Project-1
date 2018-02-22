/*
ALexander Simeonovski
CS 211
Project II
September 25th 2017

Program which takes in user imput and
check whether the imput is 'balanced' using
these symbols <[{(}])> 
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Define the struct (from the lab code) - instead of int* the array is char*
typedef struct StackStruct
{
 char*   darr;  /* pointer to dynamic array  */
 int     size;  /* amount of space allocated */
 int     inUse; /* top of stack indicator 
		   - counts how many values are on the stack   */
} Stack;

//=========================================================================================

//Initalize the stack (from the lab code)
void init (Stack* s)
{
 s->size = 2;
 s->darr = (char*) malloc ( sizeof (char) * s->size );
 s->inUse  =0;
}

//=========================================================================================
//push2 function to be called in  mode, same as push, but adds extra information. 
//(from the lab code)
void push2 (Stack* s, int val)
{
	

  /* check if enough space currently on stack and grow if needed */
	int t=0;
	if(s->inUse == s->size){
		
	 
    
	char *tmp = (char*)malloc(sizeof(char)*(s->size + 2));
		for( t = 0; t < s->inUse; t++){
			tmp[t] = s->darr[t];
		}
	free(s->darr);
	s->darr = tmp;
	s->size += 2;
	
	 //Print  info
	 printf("\nGrow the Dynamic Array\n");
	 printf("Size of Old Dynamic Array %d\n", s->inUse);  
	 printf("Size of New Dynamic Array is %d.\n", s->size);
	 printf("Number of elements transfered = %d\n\n", t);

 	}



  /* add val onto stack */
  s->darr[s->inUse] = val;
  s->inUse = s->inUse + 1;
}

//=========================================================================================

//Same as push2, however withou the  ingo.
void push (Stack* s, int val)
{
	

  /* check if enough space currently on stack and grow if needed */
	int t=0;
	if(s->inUse == s->size){
		
	 
    
	char *tmp = (char*)malloc(sizeof(char)*(s->size + 2));
		for( t = 0; t < s->inUse; t++){
			tmp[t] = s->darr[t];
		}
	free(s->darr);
	s->darr = tmp;
	s->size += 2;
	
}
  /* add val onto stack */
  s->darr[s->inUse] = val;
  s->inUse = s->inUse + 1;
}

//=========================================================================================

//pop function removes the top element of the stack (from the lab code)
void pop (Stack* s)
{
  s->inUse = s->inUse - 1;
}

//=========================================================================================

//initalize the stack (from the lab code)
int top (Stack* s)
{
  return (  s->darr[s->inUse-1] );
}

////=========================================================================================

//Determine if the stack is empty (lab code).
int isEmpty (Stack* s)
{
  if ( s->inUse == 0)
   return 0;
  else
    return 1;
}

//=========================================================================================

//Reset the stack.
void reset (Stack* s)
{
 char *temp;
 s->size = 2;
 temp=(char*) malloc ( sizeof (char) * s->size );
 s->darr = temp;
 s->inUse  =0;


}


//Main
//Contains initalized varibles
//While loop (until the user quits by etnering 'q')
int main ()
{
	
	//Initalize the stack
	Stack st;
 	
 	//Initalize varriables
	int j=0;
	int k;
	int l;
	int m=0;
	int n=0;
	char quit;	
	int misNum;
	int debugMode = 0;

	//Begin While loop (exitable on 'q').
	while(quit!='q'){
		
		//Initalize varriables which must be reinitalized every loop run.
		char miss=NULL;
		char input[300];
		char print[300];
		int i=0;
		int j=0;
   	 	int pushCount=0;
   	 	int popCount=0;
		init(&st);   
    	int check=0;

    	printf("Please enter your expression or enter q/Q to quit\n");
		
		//Get user imput (up to 300 symbols).
  		fgets ( input, 300, stdin );
  
  
 		//Debug mode set up  
 		if (input[0]=='-'&&input[1]=='d'){
  		
 			debugMode = 1;
 		
 		 }
      
  		quit=input[0];
 		 
 		//Get lenght of array. 
		int len=strlen(input);

		//Push and pop from the stack for length of array if symbol is encoutered	
   		for (i = 0; i <len; i++)
  		 {
   	   	
   			
   			if(input[i]=='('||input[i]=='<'||input[i]=='{'||input[i]=='['){
   		       	
				//debug mode      
   				if(debugMode==1){
   				 	printf("%c pushed onto the stack\n", input[i]);
   	  	 			push2(&st,input[i]);
  			  
 				}
   	  	    
   	  	    	//regular mode
				else if(debugMode==0){
					push(&st,input[i]);
				}
			   	  		   	  	   
 	 		}
 		
 			//Determine number of push operations
		 	if(input[i]==')'||input[i]=='>'||input[i]=='}'||input[i]==']'){
				  pushCount++;
				  
			}  		
		
		
			//This doesn't do anything, but I don't want to get rid of it just in case.
   			if(input[i]=='('||input[i]=='<'||input[i]=='{'||input[i]=='['|input[i]==')'|input[i]=='>'|input[i]=='}'|input[i]==']'){
   			
   			    print[j]=input[i];
			    j++;
		   }
		   //======================================================================================
		   
		   //Determine if anything is missing, its location and store both whatever is missing and its
		   //location into varriables.
		   //The third line of code is for debuging purposes and should be disabled.
		   if(input[i]=='>'&&isEmpty(&st)==0){
				miss='<';
			
				misNum=i;				
				
			//	printf("I %d\n and miss = %c", i, miss);
			}
			
			if(input[i]==')'&&isEmpty(&st)==0){
				miss='(';
				
				misNum=i;	
							
			//	printf("I %d\n and miss = %c", i, miss);

			}
			
			if(input[i]==']'&&isEmpty(&st)==0){
				miss='[';
					
				misNum=i;	
				
			//	printf("I %d\n and miss = %c", i, miss);

			}
			if(input[i]=='}'&&isEmpty(&st)==0){
				miss='{';
					
				misNum=i;	
			
			//	printf("I %d\n and miss = %c", i, miss);

			}		
			
		   
			//================================================================================ 
 			//Check and pop	the stack
			   
 			if(top(&st)=='<'&&input[i]=='>'){
	
				if(debugMode==1){
					printf("< popped from the stack\n");
				}
				pop(&st);
				popCount++;
	
			}	  
			
			
			if(top(&st)=='('&&input[i]==')'){
			
				if(debugMode==1){
						printf("( popped from the stack\n");
				}
			
				pop(&st);
				popCount++;
	
			}	
			
			
			if(top(&st)=='['&&input[i]==']'){
				if(debugMode==1){
					printf("[ popped from the stack\n");
				}
			
				pop(&st);
				popCount++;
	
			}	
			
			if(top(&st)=='{'&&input[i]=='}'){
	
				if(debugMode==1){
					printf("{ popped from the stack\n");
				}
				pop(&st);
				popCount++;
	
			}
			
			
	
			
		}//end forloop
	
			
  
 
   //Determine why the equation is not balanced (if it is not). 
	int y=isEmpty(&st);
	
//Debug code, ignore	printf("YYYIS %d\n", y);

	
	//If anything remains on the stack see what it is and reverse it, that would be the missing element to balance
	//the equation
	if(top(&st)=='<'||top(&st)=='('||top(&st)=='{'||top(&st)=='['){
	
		miss=top(&st); //This breaks the loop for some reason???
	
		if(miss=='<'){
			miss='>';
		}
		
		if(miss=='('){
			miss=')';
		}
		
		if(miss=='['){
			miss=']';
		}
		
		if(miss=='{'){
			miss='}';
		}
		
		misNum=pushCount+popCount; //There are problems with this.
	}


 

		//Print the expresion and other info.
		printf("Your expression is\n");
		printf ("%s\n", input);
  
   
   		 for(n=0;n<misNum;n++){ 	 	
  	 	 	 	
    		 printf (" ");  
		     	
			}
		
			 if (miss=='<'||miss=='('||miss=='{'||miss=='['||miss=='>'||miss==')'||miss=='}'||miss==']'){
    			printf ("^, missing %c", miss);
    			
			}
      

    		 printf ("\n");	


     
     	//If there were more pusehs than pops its not balanced (check just in case) and if so push something onto the stack.
   	    if(popCount!=pushCount){
   			push(&st, 's');
   		}
   
		int expressionVar=isEmpty(&st);



  		//Is the stack empty, if yes the equation is balanced
		if(expressionVar==0){	
	
			printf("\nThe expression is balanced\n\n---------------------------------------------------------\n\n");
		
		}

		//if not the equation is not balanced
		else if (expressionVar==1){
	
			printf("\nThe expression is not balanced\n\n----------------------------------------------------\n\n");
		}



		reset(&st); //Reset the stack



	}//end while loop





}//end main











