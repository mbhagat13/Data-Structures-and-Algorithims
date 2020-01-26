
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define HASH_TABLE_SIZE 1057

typedef struct Entry Entry, *EntryPtr;
struct Entry {
	char * string;
	int count;
};


Entry hash_table[HASH_TABLE_SIZE];

void initialize()
{
	int i;
	for(i=0;i<HASH_TABLE_SIZE;i++)
		hash_table[i].count = 0;
}

void add(char * tag)
{
	int i = 0;
	int sum = 0;
	int key;
	
	for(i=0; i<sum; i++)
	{
		sum=sum+ tag[i];
	}
	
	key = sum%HASH_TABLE_SIZE;
	
	if(hash_table[key].string != NULL)
	{
		if(strcmp(hash_table[key].string, tag) == 0)
			hash_table[key].count++;
		else
		{
			while(hash_table[key].string != NULL)
			{
				key++;
				if(hash_table[key].string != NULL)
				{
					if(strcmp(hash_table[key].string, tag) == 0)
					{
						hash_table[key].count++;
						break;
					}
				}
			}
		}		
	}
	
	if (hash_table[key].string == NULL)
	{
		hash_table[key].count++;
		hash_table[key].string = tag;	
	}
}

void print()
{
	int i;
	for(i=0;i<HASH_TABLE_SIZE; i++)
	{
		if(hash_table[i].count != 0)
			printf("%s|%d\n", hash_table[i].string, hash_table[i].count); 
	}
}
