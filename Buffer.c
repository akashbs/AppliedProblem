#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Queue{	
	char *data;
	struct Queue *next;
}node;

node* Insert(char *val)
{
	node *temp = (node*)malloc(sizeof(node));	
	temp->data = (char*)malloc(sizeof(char)*strlen(val));
	strcpy(temp->data,val);

	temp->next = NULL;
	return temp;
}

node* Remove(node *head, int val)
{
	node *temp;
	while(val && head)
	{
		temp = head;
		head = head->next;
		free(temp);
		val--;
	}
	return head;
}

void List_All(node *head)
{
	while(head)
	{
		printf("%s",head->data);
		head = head->next;
	}
}

int main(void)
{
	
	node head;
	head.next = NULL;
	node *auxIns = NULL;
	node *truHead = NULL;
	
	int max_Size = 0;
	int cur_Size = 0;
	
	static const unsigned long long int maxSTRLEN = 20000000;
	
	char ch;
	char EAT_CHAR;
	scanf("%d",&max_Size);
	
	while(1)
	{
		scanf("%c",&ch);
		switch(ch)
		{
			case ('A'):
			{
					int num = 0;
					scanf("%d",&num);
					
					if(!truHead)
						auxIns = &head;
					
					if((num + cur_Size) > max_Size)
					{
						if(truHead)
						{
							if(num >= max_Size)
							{
								truHead = Remove(truHead,cur_Size);
								cur_Size = 0;
								auxIns = &head;								
							}
							else
							{
								truHead = Remove(truHead,(num + cur_Size) - max_Size);
								cur_Size = max_Size - num;
							}
						}
					}
					scanf("%c",&EAT_CHAR);
					while(num)
					{
						char *str = (char*)malloc(maxSTRLEN*sizeof(char));
						fgets(str,maxSTRLEN,stdin);
						if(num <= max_Size)		//If the number of inputs is greater than the max_Size of Buffer then the difference will be skipped and wouldn't be inserted in buffer
						{	
							auxIns->next = Insert(str);
							auxIns = auxIns->next;
							cur_Size++;
						}	
						num--;
						free(str);
					}
					
					if(!truHead)
						truHead = head.next;
					
					break;
			}
			
			case ('R'):
			{
					int numRem = 0;					
					scanf("%d",&numRem);
					
					truHead = Remove(truHead,numRem);
					cur_Size -= numRem;
						
					break;
			}
			
			case ('L'):
					if(truHead)
						List_All(truHead);
						
					break;
			
			case ('Q'):
					exit(0);
					
			default: break;
		}
	}
	
	return 0;
}
