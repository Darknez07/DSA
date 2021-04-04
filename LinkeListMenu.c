#include<stdio.h>
#include<stdlib.h>
struct Node
{
	int data;
	struct Node *ptr;
};
void Insert(struct Node **p,int value)
{
	struct Node *temp;
	temp=*p;
	if(*p==NULL)
	{
		temp=(struct Node *)malloc(sizeof(struct Node));
		temp->data=value;
		temp->ptr=NULL;
		*p=temp;
	}
	else
	{
		while(temp->ptr!=NULL)
		{
			temp=temp->ptr;
		}
		struct Node *r;
		r=(struct Node *)malloc(sizeof(struct Node));
		r->data=value;
		r->ptr=NULL;
		temp->ptr=r;
	}
}
void Update(struct Node **n,int pos,int value)
{
	struct Node *temp;
	temp=(struct Node *)malloc(sizeof(struct Node));
	temp=*n;
	int i=1;
	if(pos==1)
	{
		temp->data=value;
	}
	else
	{
		while(i!=pos)
		{
			if(temp->ptr!=NULL)
			{
				temp=temp->ptr;
			}
			else
			{
				printf("\nEnter a proper position to Update\n ");
				break;
			}
			i++;
		}
		temp->data=value;
	}
}
void Delete(struct Node **p)
{
	struct Node *temp;
	temp=(struct Node *)malloc(sizeof(struct Node));
	temp=*p;
	struct Node *dummy;
	while(temp->ptr!=NULL)
	{
		dummy=temp;
		temp=temp->ptr;
	}
	printf("You Know %d gets Deleted\n",temp->data);
	free(temp);	
	dummy->ptr=NULL;
}
void Display(struct Node **p)
{
	struct Node *temp;
	temp=*p;
	while(temp->ptr!=NULL)
	{
		printf("%d----->",temp->data);
		temp=temp->ptr;
	}
	printf("%d\n",temp->data);
}
int main()
{
	struct Node *p;
	p=(struct Node *)malloc(sizeof(struct Node));
	p=NULL;
	int s,x=0;
	while(x!=5)
	{
	printf("Please choose from the following: ");
	printf("\n1.Insert The number at the back");
	printf("\n2.Delete from the Back if");
	printf("\n3.Updating the number at certain position in the list");
	printf("\n4.Display The Current list");
	printf("\n5.Exit");
	printf("\nChoice: ");
	scanf("%d",&x);
	switch(x)
	{
		case 1:
		printf("Please Enter the Value to Insert: ");
		scanf("%d",&s);
		Insert(&p,s);
		break;
		case 2:
		Delete(&p);
		break;
		case 3:
		printf("Enter the element position to Update if the proper position is not provided than the last element is updated: ");
		int pos;
		scanf("%d",&pos);
		printf("Enter the New value: ");
		int value;
		scanf("%d",&value);
		Update(&p,pos,value);
		break;
		case 4:
		Display(&p);
		break;
	}
	}
	return 0;
}