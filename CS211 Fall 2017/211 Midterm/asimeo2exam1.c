#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Define a stack
//The following code is from projects etc;
 
typedef struct node{
   int num;
   struct node *next;
} NODE;
//---------------------------------------------------------------------


void push(NODE **head, int n){	

	NODE *p = (NODE *) malloc(sizeof(NODE)); 
	p->num = n;
	p->next=NULL;	

	if(*head == NULL){
		*head = p; 	
	}
	
	else{
		NODE *tmp = *head; 
		
		while(tmp->next != NULL){
			tmp = tmp->next;
		}
			
		tmp->next = p; 		
	}
}


void pop(NODE**head){

*head = (*head)->next;
	
	
}

int top(NODE**head){

	NODE *tmp = *head; 
	
	if(tmp==NULL){
		return 0;
	}
	else
	return tmp->num;
	
}


int isEmpty(NODE **head){
	if(*head!=NULL){
		return 1;
	}
	
	else return 0;
}

//----------------------------------------------------------------end display

int main ()
{
	
  //Define 3 queues
  NODE* pos=NULL;
  NODE*neg=NULL;
  NODE* mul=NULL;
  
  int n=1; //Value to scan for

 
  //Couldn't figure out how to make a new line every 8 integers so just gonna use varriables mod 8
  int c1=1;
  int c2=1;
  int c3=1;
  
 //While scanf!=0 read in integers and put them in the appropriate stack 
 while(n!=0){
 	
 	
 	scanf("%d", &n);
 	
 	if(n==0){
 		break;
	 }
	
	if(n%4==0){
		push(&mul, n);
	}
	
	 if(n<0){
		  push(&neg, n);
	}
	
	 if(n>0){
		 push(&pos, n);

	}
 	
 } 

//Print positive integers
printf("\n\nThe positive integers are:\n");

while(isEmpty(&pos)!=0){
	
	if((c1-1)%8==0){	
		printf("\n");		
	}
	c1++;


	printf("%1d ", top(&pos));
	pop(&pos);
	
}

//Print the negative integers
printf("\n\nThe negative integers are:\n");

while(isEmpty(&neg)!=0){
	
	if((c2-1)%8==0){	
		printf("\n");		
	}
	c2++;

	printf("%1d ", top(&neg));
	pop(&neg);
	
}

//Print the mod 4 integers
printf("\n\nThe integers  divisible by 4 are:\n");

	while(isEmpty(&mul)!=0){
	
		if((c3-1)%8==0){
			printf("\n");		
		}
	
		c3++;

		printf("%1d ", top(&mul));
		pop(&mul);
	
	}	
 
 printf("\n\n\nDONE!");

	
	
}
