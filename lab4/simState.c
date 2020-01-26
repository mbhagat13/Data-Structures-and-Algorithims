#include <stdlib.h>
#include <stdio.h>

typedef struct states{
		char id;
		struct states * next0;
		struct states * next1;
	} state;

char garbage[8];
char deleted[8];
	
void initialize_states (state fsm[])
{
	int i = 0;
	fsm[0].id = 'A';
	fsm[1].id = 'B';	
	fsm[2].id = 'C';
	fsm[3].id = 'D';
	fsm[4].id = 'E';
	fsm[5].id = 'F';
	fsm[6].id = 'G';
	fsm[7].id = 'H';

		fsm[0].next0 = &(fsm[1]);
		fsm[0].next1 = &(fsm[2]);

		
	
		fsm[1].next0 = &(fsm[4]);
		fsm[1].next1 = &(fsm[5]);

		

		fsm[2].next0 = &(fsm[0]);
		fsm[2].next1 = &(fsm[4]);

		

		fsm[3].next0 = &(fsm[7]);
		fsm[3].next1 = &(fsm[6]);


		fsm[4].next0 = &fsm[3];
		fsm[4].next1 = &(fsm[4]);

		
		fsm[5].next0 = &(fsm[6]);
		fsm[5].next1 = &(fsm[0]);
	
		
		fsm[6].next0 = &(fsm[2]);
		fsm[6].next1 = &(fsm[7]);

		

		fsm[7].next0 = &(fsm[5]);
		fsm[7].next1 = &(fsm[1]);
	for (i =0; i<8; i++){
	deleted[i] = '0';

	}

			
}	

void print_s(state fsm[]){
	int i=0;
	state * next0;
	state * next1;
	next0 = &fsm[0];
	next1 = &fsm[0];
	for(i=0;i<8;++i){
		if(deleted[i]=='0'){
			printf("%c ",fsm[i].id);
			next0 = &fsm[i];
			next1 = &fsm[i];
			next0 = next0->next0;
			next1 = next1->next1;
			printf("%c ", next0->id);
			printf("%c ", next1->id);
			printf("\n");
		}
	}
}

void change(state *present, char arr[]){
	int stateNumber=0;
	switch (arr[2]){
		case '0':
			stateNumber = arr[4] - present[0].id;
			if(arr[4] >= 'A' && arr[4] <= 'H' && deleted[arr[4] - 65] == '0'){
				present->next0 = &present[stateNumber];
			}
			else
			printf("Error: State %c deleted or an invalid input has been entered\n", arr[3]);
			break;
		case '1':
			stateNumber = arr[4] - present[0].id;
			if(arr[4] >= 'A' && arr[4] <= 'H' && deleted[arr[4] - 65] == '0'){
				present->next1 = &present[stateNumber];
			}
			else
			printf("Error: State %c deleted or an invalid input has been entered\n", arr[3]);
			break;
			default:
            printf("There is an error in your input. Please try again \n");
		}
}	

void garbage_i(state* present){
	
	   state *next = present;
    next = next -> next0;
    garbage[present -> id - 65] = '0';
    
    if(garbage[next -> id - 65] != '0')
    {
        garbage_i(next);
    }
    
    next = present -> next1;
    if(garbage[next -> id-65] != '0')
    {
        garbage_i(next);
    }	
}

void print_g(state fsm[]){
	int i,check=0;

	for(i=0;i<8;i++){
		if(garbage[i] != '0')
		{
			printf("Garbage: "); 			
			i = 8;
		}
	}
	for(i=0;i<8;i++){
		if(garbage[i] != '0')
		{
			printf("%c ", fsm[i].id); 			
			check++;
		}
	}
	if(check==0){
		printf("No Garbage\n");
	}else
	printf("\n");

	
	}
	
	void garbage_reset(){
    int i;
    for(i=0;i<8;i++)
        garbage[i] = i+65;
}


void delete(state *present, char argument){
	int i =0, garbageCount = 0;
	garbage_reset();
    garbage_i(present);
	for (i =0; i<8;i++){
		if(garbage[i]!='0'){
			garbageCount++;
		}
	}
	
	if(argument == '0' ){
		if (garbageCount == 0){
            printf("No states deleted. \n");
        }else
        {
            printf("Deleted: < "); 
            for(i=0;i<8;i++)
            {
                if ((garbage[i]!='0') && (deleted[i] != (i+65)))
                { 
                    printf("%c ", garbage[i]);
                    deleted[i] = garbage[i];
                }
            }
		 printf(">\n");

        }
	}else{
		if ((argument <= 'H') && (argument >= 'A'))
        {
            if((garbage[argument-65] == argument) && (deleted[argument-65] == argument))
            {
                printf("Deleted State %c", garbage[argument-65]);
            }    
            else
                printf("Not Deleted");    
        }
        else
            printf("Error please try again.");
		
		printf("\n");
		
	}
	
		
}

int main(int argc, char * argv[])
{

	state fsm[8];
	state *present;
	char arr [] = {"000000"};
	char command = '-';
	int i;
	initialize_states (fsm);
	
	present = &fsm[5];
	
	printf("Initial State: %c\n",present->id);

	while (command != 'e'){
	//command = getc(stdin);
	fgets (arr, 10, stdin);

	/*for(i = 0; i<6;i++){
		printf("%c",arr[i]);
	}*/
	command = arr[0];
	
	if (command == '0'){
	present=present->next0;
	printf("%c\n", present->id);				
	} 
	
	else if (command == '1'){
		present=present->next1;
	printf("%c\n", present->id);				
	}
	
	else if (command == 'p'){
	print_s (fsm);
	}
	
	else if (command == 'g'){
		
	garbage_reset();
	garbage_i(present);
	print_g (fsm);
	
	}
	else if (command == 'c'){
	/*arr[0]=getchar();
	arr[1]=getchar();
	arr[2]=getchar();
	arr[3]=getchar();
	arr[4]=getchar();
	*/
	
	change(present,arr);
	}

	else if (command == 'd'){
	if (arr[2] != 0){

	delete(present, arr[2]);

	}else
		delete(present, '0');

		
	} else if (command == 'e')
		printf("Exiting Program");

	
	}





    exit(0);
}

