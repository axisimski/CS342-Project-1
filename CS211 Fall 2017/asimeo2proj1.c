
//Programing Project I
//September 9th 2017
//CS 211
//Alexander Simeonovski

#include<stdio.h>
#include <stdlib.h>


//This function will take in two arrays as parameters and will copy the contents of one into the other. 

void arrayCopy (int fromArray[], int toArray[], int size){
	
	int i=0; //intialize variable for forloop.
	
	for(i;i<size;i++){
		
		toArray[i]=fromArray[i]; //Loop trough the elements of the array and copy them from one into the other. 
	
		}
}



//This function takes one array and its size as parameters and sorts the array in ascending order. 
void myFavorateSort (int arr[],  int size){
	
	//initialize varriables
	int i=0; 
	int j=0;
	int k;	

	//loop trough the array
	for (i;i<size;i++){
		
		//in the inner loop compare elements and transfer position them such that the array becomes sorted.	
   		for (j=i+1;j<size;j++){
    	
    		//If the previous element of the array is greather than the next they are swapped.
    		if (arr[i]>arr[j]){ 
    			
				k=arr[i];
    			
    			arr[i]=arr[j];
    			
    			arr[j]=k;    			
    				
			}
    	
		}
	
	}
		
}


//This function will conduct a linear seatch trough an unsorted array.	
int linSearch (int arr[], int size, int target, int*element){
	
	//Initalize varriables
	int i=0;
	int j=0;

	//loop trough the size of the array 
	while(arr[i]!=target&& i<size){
	
		i++;
		
		if(arr[i]==target){
			j=i;
		}
		
	};

	*element=j;

}



//Thi function will take in a sorted array of a defined size and perform a binary search for a user imputed integer.
//It will return whether the integer was found, the number of comparisons it took for it to be found and the which element of the array it was located at.
int binSearch (int arr[], int size, int target, int *element, int *numComps){
	
	//Initalize varriables
	int i=0;
	int j=0;
	int o=0;
	int numComparisons=0;
	int high;
	int low=1;
	int mid;

	high=size-1;
	
	//Loop until high equals to or exceeds low
	while (low <= high)
	{
		numComparisons++;
		if(arr[mid] < target)
		{
			low = mid + 1;

		}
		else if(arr[mid] == target) //Condition to declare a target found.
		{
	
			//If target is found return the element and number of comparisons.
			//Target doesn't need to be returned since its a parameter of the function
			//and main 'knows' what it is.
			*numComps=numComparisons;
			*element=mid+1;
			break;
		}
		else
		{
			 high = mid - 1;
		}
		mid = (low + high)/2;
	}
	if(low > high)
	{
		
	 	*element=0; //This condition means that the loop should be over and the target wasn't found.

	}
			
}



int main(){
	
	//Initalize varriables	
	int target;
	int element;
	int elementb;
	int compb;	
	int val;
	int size=1;
	
	//Initalize 'loop varriables'
	int j=0;
	int i=0;
	int x=0;	
	int z=0;
	int m=0;
	int r=0;
	int w=0;

	
	//Initalize pointers 
	int*pointy;
	int*pointybel;
	int*pointybcomp;
	
	//Initalize the two arrays.
	int *a;
	int *b;


//----------------------------------------------------------------------------------------------------------------------	
	a = (int *) malloc (size * sizeof(int) ); ; 

	printf("Enter a values into the array, when you are done enter -999\n");
	
	//While the imput != -999 keep scaning for values and adding them to the array while dynamically 
	//alocating more space.
	while(val!=-999){
		

 		scanf ("%d", &val); 
		
		if(j==size){
			
			int y;
			int *temp;
    		temp = (int *) malloc ( size * 2 * sizeof(int) );
    	
			for ( y = 0 ; y < size ; y++){
    			temp[y] = a[y];
			}
 	
 			free (a);
			a = temp;
 			size = size * 2;
			}
	
		a[j]=val;
		j++;
		
	}
	
	//----------------------------------------------------------------------------------------------------------------------	

	
	b = (int *) malloc (size * sizeof(int) ); 

	//Copy array a into array b.	
	arrayCopy(a, b, j);
	
	//Sort array b (to be used in the binary search).
    myFavorateSort (b, j);
    

	//While the imput !=0 keep imputing and looking for target numbers.
	while(target!=-999){
		 
		printf("\nEnter the number you want to search for\n");
		scanf ("%d ", &target);
		
		if(target==-999){
			break;
		}
		printf("%d\n", target); 
	
		z++;
		
		//Perform a linear search on the unsorted array and print the results. 
		for(r;r<z;r++){
	
			pointy=&element;
		
			linSearch(a, j, target, pointy);
		
			if(element!=0&&target!=-999){
				printf("We found %d as the %d element of the unsorted array after %d Linear comparisons.\n",target, element,element+1);
			
			}
		
			else if(element==0){
				printf("The number was not Found using Linear Search\n");
				}
			}
		
		//Perform a binary search on the sorted array and return the results.
		for(w;w<z;w++){
			
			pointybcomp=&compb;
			pointybel=&elementb;
		
			binSearch(b, j, target ,pointybel, pointybcomp);
			
			if(elementb!=0&&target!=-999){
			
				printf("We found %d as the %d element of the sorted array after %d Binary comparisons.\n",target, elementb-2,compb-1);			
			
				}
			
			else{
				printf("The number was not found using Binary Search\n\n");
				}
		
			
		}
	}
}















