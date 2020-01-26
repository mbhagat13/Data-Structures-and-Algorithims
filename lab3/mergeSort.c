#include "stdio.h"

#include "mySort.h"

void mySort(int array[], unsigned int first, unsigned int last)

{

  int mid = 0;
  int i = 0;
  int j= 0;
  int leftSide[MAX_SIZE_N_TO_SORT];
  int rightSide[MAX_SIZE_N_TO_SORT] ;
	
   int k = 0;
   if (first < last) {
    mid = (first + last) / 2;
			mySort(array, first, mid);
			mySort(array, mid + 1, last);
			//fprintf(stdout,"\n");
			for ( i = 0; i < (mid - first + 1); i++) {
			myCopy(&array[i+first],&leftSide[i]);
			
			}
			for ( j = 0; j < (last - mid); j++) {
			myCopy(&array[mid+j+1],&rightSide[j]);
				
			}
			
			 leftSide[mid-first+1]=999999;
    rightSide[last-mid]=999999;

    i =0;
    j = 0;




    for (k = first; k<= last; k++){
    if (myCompare (leftSide[i],rightSide[j])<0){
    myCopy(&leftSide[i],&array[k]);
    i++;
    }else{
    myCopy(&rightSide[j],&array[k]);
    j++;
    }


    }

   
    

  } //main if
  
} //method