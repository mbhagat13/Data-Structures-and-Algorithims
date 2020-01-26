#include "metrics.h"

void mySort(int array[], unsigned int first, unsigned int last)
 

   {
int e = 0, i, bucket;

for ( i = (first+1); i<=(last); i++){
myCopy(&array[i],&bucket);
e = i -1;

while ((e>=0)   && (myCompare(bucket,array[e])<0)){
mySwap(&array[e+1],&array[e]);
e--;

}
myCopy(&bucket,&array[e+1]);

}


}
