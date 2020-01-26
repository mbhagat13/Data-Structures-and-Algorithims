#include <stdlib.h>
#include <stdio.h>
#include <math.h>

/**
 *  The functions in this module implement a Heapdata structure
 *  of integers.
 */
 int heap[100]={0};
 static int last =-1;
 static int deleting =0;


/**
 * heapSize() returns the number of items in the Heap.
 *
 */
int heapSize()
{
  return last;  //A dummy return statement
}

int findParent(int a){

if((a%2)==0 && (a>=3)){//rightchild
return (a)/2 -1;

}else if((a%2)==1 && (a>=3)) {//leftchild
return (a-1)/2;
	
}else
return 0;

	
}


void mySwap(int a, int b){
int temp = heap[a];
heap[a]=heap[b];
heap[b]=temp;



}	


void heapify(int i)
 {
int left;
int right;
int largest= 0;
int check;

left = (2*i)+1;
right = (2*i)+2;


//if(right<= heapSize()){
 if((heap[left]<= heap[right])){
 check = right;
 }else{
 check = left;
 }


//printf("LeftIndex: %d LeftValue: %d RightIndex: %d RightValue: %d\n", left, heap[left],right,heap[right]);
//printf("Check: %d, Largest: %d, i: %d\n", check, largest, i);
 
if ((check<=heapSize()) && (heap[i] < heap[check])){
largest = check;

}
else{
	
largest = i;

}

//printf("Check: %d, Largest: %d, i: %d\n", check, largest, i);
 

if (deleting ==0){
if(largest!=i && i>=0){
mySwap(largest,i);
heapify(findParent(i));
}
}else
if(largest!=i && largest<= heapSize()){
mySwap(largest,i);
heapify(largest);
}
 
 
}


/**
 * heapDelete() removes the biggest integer in the heap and returns it.
 *
 */
	


int heapDelete()
{
	int max = heap[0];
	heap[0] = heap[last];
	
	last--;	
	deleting =1;
	heapify(0);
	return max;
}





/**
 *  addHeap(thing2add) adds the "thing2add" to the Heap.
 *
 */
void addHeap(int thing2add)
{
last++;
heap[last] = thing2add;

if(last<=2)
heapify(0);
else{
heapify((last-1)/2);
}
}	

void printHeap(int i){
	int left = 0, right = 0;

	left = (2*i)+1;
	right = (2*i)+2;

	printf("<node id=\"%d\">", heap[i]);

	
	//print left child
	if (left<= heapSize()){
	printHeap(left);
	}

	//print right child
	if (right<= heapSize()){
	printHeap(right);
	}
	printf("<\\node>");
}
  




 