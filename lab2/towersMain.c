#include <stdio.h>
#include <stdlib.h>
#include "towers.h"

int main(int argc, char **argv)
{
    int n = 3;
    int from = 1;
    int dest = 2;
    if (argc == 1) {
	 towers(n, from, dest);
    } 
    if (argc == 2) {
        n = atoi(argv[1]);
    }
	else if (argc ==4) {
	n = atoi(argv[1]);	
	from = atoi(argv[2]);
	dest = atoi(argv[3]);
	
	}else{
	fprintf(stderr, "Wrong number of parameters entered");
	exit(0);
	}
		

	if((from == dest) || (from <1) || (from>3) || (dest <1) || (dest>3)){
	fprintf(stderr, "The tower ids can only be 1,2 or 3. Also, the starting and ending destination cannot be the same.");	
	exit(0);
	}
	if (n<1){
	fprintf(stderr, "The amount of disks you entered is not valid");
	exit(0);
	}
	else{
    towers(n, from, dest);
   }
 exit(0);
}

