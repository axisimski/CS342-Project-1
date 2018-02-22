#include <stdio.h>
#include <stdlib.h>

//BEGINING OF DEFINITIONS #############################################################################################################################

typedef struct mazeStruct{
	char **arr;  //2D array		
	int xsize, ysize; 	//sizes 
	int xstart, ystart; //start cordinates
	int xend, yend; 	//end cordinates
} maze;

typedef struct node {
  struct node* next; 
  struct node* prev; //Might not need this, but just in case
  int x;
  int y;
} NODE;

//##################################################################################################################################END OF DEFINITIONS


//BEGINING OF STACK OPERATIONS/OTHER FUNCTIONS########################################################################################################

//Print the stack recursivley (backwards). 
void printStak(NODE *head){
	
	if( head==NULL ){
		//If the head is null we display this message which should be on top since we are going backwards. 
		printf("\nThe the path to solving the maze is;\n"); 	
	}
	else{
		printStak(head->next );
		printf("(%d and %d)->\n", head->x, head->y);		
		
	}

}//end printStak

//============================================================================================

/* print out the initial maze (took this code from the lab) */
printMaze(maze m1){
	
int i;
int j;
for (i = 0; i < m1.xsize+2; i++){   
    for (j = 0; j < m1.ysize+2; j++)
       printf ("%c", m1.arr[i][j]);
       printf("\n");
    }
}//end PrintMaze

//============================================================================================

//Push onto the stack 
void push(NODE **head, int x, int y, int deBug){

	//Make a new node and allocate for it. 
	NODE *tmp = (NODE *) malloc(sizeof(NODE));
	tmp->x = x;
	tmp->y = y;
	
	//If deBug is 'On' print the debuging info. 
	if (deBug==1){
			printf("Pushing onto the stack: (%d, %d)\n", tmp->x, tmp->y);
	}
	
	tmp->next = *head;
	*head = tmp;
	
}//end Push

//============================================================================================


//This will reset the stack recursivley. (In reality it leaves one element on the stack and I have no idea how to get rid of it).
void resetStak(NODE *head){

	if(head->next!=NULL){
		
		NODE *tmp = (NODE *) malloc(sizeof(NODE)); //Don't even know what's going on here, I did that part a few days ago and don't even wanna mess with it.
		tmp=head;
		head=head->next;
		free (tmp);
		
		resetStak(head);	
	}
	
	else head=NULL;
	

	
//	 return;
}


//============================================================================================

//Pop jead of the stack
void pop(NODE **head, int deBug){

	NODE *tmp = *head;
	
	if (deBug==1){
			printf("Popping off stack: (%d, %d)\n", tmp->x, tmp->y);
	}

	if(*head != NULL){
		*head = (*head)->next;
		free(tmp);
	}
	
	
} //end pop

//============================================================================================

//Checks if the list is empty (I dont think I ended up using this anywhere, but it is one of the requirements).
int isEmpty (NODE* head)
{
  if (head == NULL)
    return 1;
  else
    return 0;
}
//end is Empty

//============================================================================================

//THis checks if the end is found by "looking around" the neighboors of xnow X ynow. 
int isFound(char **arr, int xnow, int ynow){
	
	if(arr[xnow-1][ynow]=='e'){	
		printf("\nSOLVED IT~!\n");
		return 1;				
	}	

	else if(arr[xnow+1][ynow]=='e'){	
		printf("\nSOLVED IT~!\n");
		return 1;		
	}	
	
	
	else if(arr[xnow][ynow-1]=='e'){
		printf("\nSOLVED IT~!\n");
		return 1;		
	}	
	
	
	else if(arr[xnow][ynow+1]=='e'){
		printf("\nSOLVED IT~!\n");
		return 1;
		
	}
	
}//isfound end

//============================================================================================

//Initalize the maze
void init (NODE* head)
{

 head->next=NULL;
 head->prev=NULL;
 

}//end initalize



//BEGIN MAIN()############################################################################################################################)
int main (int argc, char **argv)
{
	
maze m1; //Declare the maze 
NODE *mStack = (NODE *)malloc(sizeof(NODE)); //Declare the stack.
init(mStack);
int deBug=1; //Declare debug mode. 0 means its off. 

  int xpos, ypos;
  int i,j;

  FILE *src;

  /* verify the proper number of command line arguments were given */
  if(argc != 2) {
     printf("Usage: %s <No file with this name, or more than one file selected>\n", argv[0]);
     exit(-1);
  }
   
  /* Try to open the input file. */
  if ( ( src = fopen( argv[1], "r" )) == NULL )
  {
    printf ( "Can't open input file: %s", argv[1] );
    exit(-1);
  }
 
  /* read in the size, starting and ending positions in the maze */
  fscanf (src, "%d %d", &m1.xsize, &m1.ysize);
  fscanf (src, "%d %d", &m1.xstart, &m1.ystart);
  fscanf (src, "%d %d", &m1.xend, &m1.yend);
  /* print them out to verify the input */
  
  printf("\n\nNOTE DEBUG MODE IS ALWAYS ON, TO TURN IT OFF set deBug on line 181 to 0,\nI couldn't figure out how to scan for it so I want to show that it its there\n\n");
  printf ("size: %d, %d\n", m1.xsize, m1.ysize);
  printf ("start: %d, %d\n", m1.xstart, m1.ystart);
  printf ("end: %d, %d\n", m1.xend, m1.yend);
  
    
  //Check for valid input and send a message to standard error if:
  //the starting or ending positions are out of range  
  if(m1.xstart>m1.xsize||m1.ystart>m1.ysize||m1.yend>m1.ysize||m1.xend>m1.xsize){
     
	 fprintf(stderr, "%s", "Starting or ending cordinates OUT OF RANGE!\n\n");
 	 exit(1);
  }

	//Any  of the values are negative. 
  if(0>m1.xsize||0>m1.ysize||0>m1.ystart||0>m1.yend||0>m1.xstart||0>m1.xend){
  	
	  	fprintf(stderr, "%s", "\nStarting or ending cordinates OUT OF RANGE (Can't have negative numbers')!\n\n");
		exit(1);
	}



  /* allocate the maze */
  m1.arr = (char **) malloc (sizeof(char *) * (m1.xsize+2));
  for (i = 0; i < m1.xsize+2; i++)
     m1.arr[i] = (char *) malloc (sizeof(char ) * (m1.ysize+2));

  /* initialize the maze to empty */
  for (i = 0; i < m1.xsize+2; i++)
     for (j = 0; j < m1.ysize+2; j++)
       m1.arr[i][j] = '.';

  /* mark the borders of the maze with *'s */
  for (i=0; i < m1.xsize+2; i++)
    {
     m1.arr[i][0] = '*';
     m1.arr[i][m1.ysize+1] = '*';
    }
  for (i=0; i < m1.ysize+2; i++)
    {
     m1.arr[0][i] = '*';
     m1.arr[m1.xsize+1][i] = '*';
    }

  /* mark the starting and ending positions in the maze */
  m1.arr[m1.xstart][m1.ystart] = 's';
  m1.arr[m1.xend][m1.yend] = 'e';
		  
  /* mark the blocked positions in the maze with *'s */
  while (fscanf (src, "%d %d", &xpos, &ypos) != EOF)
    {
     m1.arr[xpos][ypos] = '*';
    }
 
 //Print the maze
  printMaze(m1);
  
/*Set varriables for all sorts of things over here, put them here rather than the begining
of Main() because it makes debuging a lot easier, given the relativley long main function.*/
 
int freeSize=m1.ysize; //When looping to free the array use this
int xnow=m1.xstart; //Xnow is the current node to be put on the stack. In the bgining it equals to the starting x cordinate
int ynow=m1.ystart;//Ynow is the current node to be put on the stack. In the bgining it equals to the starting y cordinate
int xPerma=xnow; //This permanently keeps the starting x point. (Could have been done with m1.start, but I couldn't fugure that 
int yPerma=ynow; //out when I started writing the code, so it just stayed. 

int test=0; //This will test whether we have an empty stack or found the end point. if(isEmpty=0) doesn't work for some reason.
int counter=0; //Keeps track of all stack operations.
int noSolution=0; //If no solution is found we know not to print the stack or any other message by keeping this at 0. 

//Push xnow and ynow onto the stack. 
push(&mStack,  xnow,  ynow,deBug);


//While test is 0 this will continue to loop. Test will cease to equal zero if the stack is empty OR an end is found. 
while(test<1){
	
	counter++;
	
	//If we find the end point, end the loop by incremeanting test. 
	if (isFound(m1.arr, xnow, ynow)==1){	
		
		test++;
	}


//If a position has been visited mark it with something so its' no longer a 'b'. 
//This code basically checks all neighboors and if any are unvisited it goes there and 
//pushes them onto the stack. 
//It checks different direction until it has nowhere else to go at which point
//it goes back by poping from the stack. (Since it marks every position it goes to as 
//visited it never returns to the same place twice. 
//If the stack is empty it means that it has visited every possible place and 
//no solution has been found.


	//Check up
	else if(m1.arr[xnow+1][ynow]=='.'){
		xnow++;
		
		push(&mStack,xnow, ynow, deBug);
		m1.arr[xnow][ynow]='V';

	}	
//---------------------------------------------------------------------------	
	//Check right
	else if(m1.arr[xnow][ynow+1]=='.'){
		ynow++;				
		push(&mStack, xnow, ynow, deBug);
		m1.arr[xnow][ynow]='V';		

	}
//---------------------------------------------------------------------------	
	

	//Check down
 	else if(m1.arr[xnow-1][ynow]=='.'){
		xnow--;
		m1.arr[xnow][ynow]='V';
		push(&mStack, xnow, ynow,deBug);
				
	
	}
//---------------------------------------------------------------------------	
	
	//Checl left
	else if(m1.arr[xnow][ynow-1]=='.'){
		ynow--;	
		m1.arr[xnow][ynow]='V';		
		push(&mStack, xnow, ynow, deBug);
			

	}	
	
//---------------------------------------------------------------------------	
	else{
	
		//If we return to the begining
		if(xPerma==xnow&&yPerma==ynow){
			test++;
			printf("\n NO SOLUTION!!!\n");
			noSolution=1;
			break;
			}; 	
			
			
			//eslse pop the stack and set the values.
			pop(&mStack, deBug);
			xnow = mStack->x;
			ynow = mStack->y;	
			
		
		}



	

	
}//end whileoop


	//If noSolution=0 (which means that a solution exists, print the number of moves and what they are).
	if(noSolution==0){
	
		printf ("The path from start to finish is %d moves long and consists of;\n", counter);

 		printStak(mStack);
	
	}

//---------------------------------------------------------------------

	//Reset the stack
	resetStak(mStack);
//---------------------------------------------------------------------

	//FREE THE ARRAY
	int f;
	for(f = 0; f < (m1.xsize+2); f++){
		free(m1.arr[f]);
	}
	free(m1.arr);
//---------------------------------------------------------------------

  
 	fclose(src); //close the file

}//END MAIN
    
///#################################################################################################################################    
    
    
    
    
    
    
    
    
    
    
    
  
    
    
    
    
    
    
    
    
    
    
    
    










