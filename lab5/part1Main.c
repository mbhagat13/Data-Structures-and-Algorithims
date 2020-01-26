#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
extern int isEmpty();
extern int pop();
extern void push(int);

int main(int argc, char * argv[])
{
  int ch =0;
  int stackValue =0;
  int validity=1;
  int temp = 0;
  while ((ch = getchar()) != EOF) {

	//Ensure valid enterance   
	if (!(isalpha(ch) || ch == '>' || ch == '<' || ch == '/'))
	continue;


	//start
	if(ch =='<'){
		ch = getchar();
	} 
	if ((ch!='<') &&(temp==1)){
	validity = 0;
	}
	
	
	
	//pushing
	if(isalpha(ch)){
		push(ch);	

		ch=getchar();
	}
	
	//poppping	
	if(ch=='/'){
		ch = getchar();
		stackValue= pop();

		if(stackValue<0){
			exit(1);
		}	
		if(stackValue!=ch){
			validity = 0;
		}
		ch =getchar();
	}	
	if(ch !='>'){
		validity = 0;
	}
	
	
	ch = getchar();

	if(ch =='<'||ch== '\n'){
		temp = 0;
	}else
		temp =1;


	
	if(ch==('\n')){
		if((validity ==1) && (isEmpty()==1)){
			printf("Valid\n");
			  exit(0);
			
		}else{
			printf("Invalid\n");
		exit(1);
		}
	}

	
    
    
  }
  exit(0);
}
