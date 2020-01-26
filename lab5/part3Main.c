#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
extern char *  pop();
extern void push(char *);
extern int isEmpty();
extern void initialize();
extern void add();
extern void print();

int main(int argc, char * argv[])
{
	int ch;
	char array[100], array2[100];
	int i = 0;
	char* stringVal;
	char* check;
	int validate = 1;

	initialize();

	
	while ((ch = getchar()) != EOF)
	{
		if(ch=='\n'){
			if(isEmpty() == 0){
			validate = 0;
			}
	
			if(validate==1){
			fprintf(stderr, "Valid \n");
			print();
			exit(0);
			}
			else{
			printf("Not valid\n");
			exit(1);
			}
			
		}
		
		
		if (!(isalpha(ch) || ch == '>' || ch == '<' || ch == '/'))
			continue;
    	else if (ch == '<')
    	{
    		ch = getchar();
    		i = 0;
    		if(isalpha(ch))
    		{
    			while(ch != '>')
    			{
    				array[i] = ch;
    				ch = getchar();
					i++;
    				}
    			stringVal = malloc(i*sizeof(char));
    			strcpy(stringVal,array);
    			memset(&array[0], 0, sizeof(array));
    			add(stringVal,i);
    			push(stringVal);
    		}
    		else if(ch == '/')
    		{
    			ch = getchar();
    			i = 0;
    			while(isalpha(ch))
    			{
    				array[i] = ch;
    				ch = getchar();
    				i++;
    			}
    			if(isEmpty() == 1)
    			{
    				pop();
    				exit(1);
    			}
    			else
    			{
    				check = pop();
    				strcpy(array2,check);
    				if(strcmp(array,array2) != 0)
    				{
					validate = 0;
    				}
    			}
    		memset(&array[0],0,sizeof(array));
    		memset(&array2[0],0,sizeof(array2));
    		}
    	
    	}

	}
	
	exit(0);
}
