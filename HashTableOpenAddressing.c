#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct el
{
	char name[256];
	struct el *next;
}node;
node *hashTable[100];
int HashTableSize=10;
void Intialize()
{
	int i;
	for(i=0;i<HashTableSize;i++)
	{
		hashTable[i]=NULL;
	}
}
int chartoint(char name[])
{
	int s=0,i;
	for(i=0;i<strlen(name);i++)
	{
		s+=name[i];
	}
	return s;
}
int keyfind(char keyname[])
{
	int ascii,key;
	node *n;
	ascii=chartoint(keyname);
	key=ascii%HashTableSize;
	if(strcmp(hashTable[key]->name,keyname)==0)
	{
		return key;
	}
	return -1;
}
node * searchfurther(char keyn[])
{
	node *n;
	int ascii=chartoint(keyn);
	int key=ascii%HashTableSize;
	for(n=hashTable[key];n!=NULL;n=n->next)
	{
		if(strcmp(n->name,keyn)==0)
		{
			return n;
		}
	}
	return NULL;
}
void printfList(node *p)
{
	node *n;
	for(n=p;n!=NULL;n=n->next)
	{
		printf(" [%s] ",n->name);
	}
}
void printfhashTable()
{
	int i;
	for(i=0;i<HashTableSize;i++)
	{
		printf("\nHashValue [%d]",i);
		printfList(hashTable[i]);
	}
}
void CallAction()
{
	printf("\nHello Welcome to the program");
	printf("\n1.Add a Node to HashTable");
	printf("\n2.Search a Node");
	printf("\n3.Delete a Node");
	printf("\n4.Print The Hash table");
	printf("\n5.To exit the program");
	printf("\nEnter it now :");
}
void Search()
{
	int k;
	node *p;
	char key[256];
	printf("Enter the Value to search: ");
	scanf("%s",key);
	k=keyfind(key);
	if(k==-1)
	{
		p=searchfurther(key);
		if(p==NULL)
		{
			printf("Node Does not exist");
		}
		else
		{
			printf("[%s] at %d",p->name,k);
		}
	}
	else
	{
		printf("[%s] at %d",hashTable[k]->name,k);
	}
}
void Delete()
{
	int k;
	node *p;
	node *n;
	char key[256];
	printf("Enter the Value to Delete:");
	scanf("%s",key);
	k=keyfind(key);
	if(k==-1)
	{
		p=searchfurther(key);
		if(p==NULL)
		{
			printf("Does not exist");
		}
		else
		{
			n=p;
			p->next=n->next;
			free(n);		
		}
	}
	else
	{
		n=hashTable[k];
		if(n->next==NULL)
		{
			free(n);
		}
		else
		{
			hashTable[k]=n->next;
			free(n);
		}
	}
}
void addNode()
{
	node *n1,*n;
	int key;
	n=(node *)malloc(sizeof(node));
	printf("Enter the Element to add:");
	scanf("%s",n->name);
	int ascii=chartoint(n->name);
	key=ascii % HashTableSize;
	n->next=NULL;
	if(hashTable[key]==NULL)
	{
		hashTable[key]=n;
	}
	else
	{
	for(n1=hashTable[key];n1->next!=NULL;n1=n1->next);
	n1->next=n;
	}
}
void main()
{
	Intialize();
	int act=1;
	while((act==4)|| (act==1)||(act==2) || (act==3))
	{
		CallAction();
		scanf("%d",&act);
		if(act==1)
		{
			addNode();
		}
		if(act==2)
		{
			Search();
		}
		if(act==3)
		{
			Delete();
		}
		if(act==4)
		{
			printfhashTable();
		}
		if(act==5)
		{
			break;
		}
	}
}
