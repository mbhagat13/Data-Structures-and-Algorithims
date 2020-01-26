#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
extern int pop();
extern void push(int);
extern void addHeap(int);
extern void printHeap(int);

extern int heapSize();
extern int heapDelete();
extern int isEmpty();

int main(int argc, char * argv[])
{
  int value= 0;
  int i = 0;
  int max = 0;
  int size= 0;
  while (scanf("%d\n", &value) != EOF) {
    fprintf(stderr, "READING INPUT: %d\n", value);
	addHeap(value);

 }
printHeap(0);
printf("\n");

size = heapSize();
printf("\n");
printf("Pushing Stack:\n");


for(i = 0 ; i<=size;i++){
max = heapDelete();

printf("%d\n", max);

push (max);
}

printf("\n");

printf("Popping Stack:\n");
while(isEmpty()==0){
printf("%d\n",pop());	
}
  

  
  exit(0);
}
