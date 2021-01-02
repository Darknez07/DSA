#include<stdio.h>
#include<stdlib.h>
struct Node
{
	int data;
	struct Node *link;
};
void Insert_at_beginning(struct Node **p,int value)
{
	struct Node *temp,*dummy;
	temp=(struct Node *)malloc(sizeof(struct Node));
	if(*p==NULL)
	{
		dummy=(struct Node *)malloc(sizeof(struct Node));
		dummy->data=value;
		dummy->link=NULL;
		*p=dummy;
	}
	else
	{
		temp->data=value;
		temp->link=*p;
		*p=temp;
	}
}
void Insert_at_end(struct Node **p,int value)
{
	struct Node *temp;
	temp=(struct Node *)malloc(sizeof(struct Node));
	temp=*p;
	if(*p==NULL)
	{
		temp=(struct Node *)malloc(sizeof(struct Node));
		temp->data=value;
		temp->link=NULL;
		*p=temp;
	}
	else
	{
		while(temp->link!=NULL)
		{
			temp=temp->link;
		}
		struct Node *r;
		r=(struct Node *)malloc(sizeof(struct Node));
		r->data=value;
		r->link=NULL;
		temp->link=r;
	}
}
void Insert_at_given_pos(struct Node **p,int value,int pos)
{
	struct Node *temp,*dummy;
	temp=(struct Node *)malloc(sizeof(struct Node));
	dummy=(struct Node *)malloc(sizeof(struct Node));
	temp=*p;
	int i=0;
	while(temp->link!=NULL || i!=pos)
	{
			dummy=temp;
			temp=temp->link;
			i++;
	}
	if(i==pos && temp->link!=NULL)
	{
		struct Node *r;
		r=(struct Node *)malloc(sizeof(struct Node));
		r->data=value;
		r->link=temp;
		dummy->link=r;	
	}
	else if(temp->link==NULL &&  i!=pos)
	{
		printf("Please Enter a valid value");
	}
	else
	{
		struct Node *r;
		r=(struct Node*)malloc(sizeof(struct Node));
		r->data=value;
		temp->link=r;
		r->link=NULL;
	}		
}
void Insert_after_entered_Element(struct Node **p,int value,int k)
{
	struct Node  *temp;
	temp=(struct Node *)malloc(sizeof(struct Node));
	temp=*p;
	int i=0;
	while(temp->link!=NULL || i!=(k+1))
	{
		temp=temp->link;
		i++;
	}
	if(temp->link==NULL && i!=(k+1))
	{
		printf("Please Enter a valid position");
	}
	else
	{
		struct Node *r;
		r=(struct Node *)malloc(sizeof(struct Node));
		r->data=value;
		temp->link=r;
		r->link=temp->link;
	}
}
void Insert_before_entered_Element(struct Node **p,int value,int k)
{
	struct Node *temp,*dummy;
	temp=(struct Node *)malloc(sizeof(struct Node));
	dummy=(struct Node *)malloc(sizeof(struct Node));
	int i=0;
	while(temp->link!=NULL || i!=(k-1))
	{
		dummy=temp;
		temp=temp->link;
		i++;
	}
	if(temp->link==NULL && i!=(k-1))
	{
		printf("Please Enter a valid position");
	}
	else
	{
		struct Node *r;
		r=(struct Node *)malloc(sizeof(struct Node));
		r->data=value;
		dummy->link=r;
		r->link=temp;
	}
}
void Delete_at_beginning(struct Node **p,int value)
{
	struct Node *temp;
	temp=*p;
	*p=temp->link;
	free(temp);
}
void Delete_at_last(struct Node **p,int value)
{
	struct Node *temp;
	temp=(struct Node *)malloc(sizeof(struct Node));
	temp=*p;
	struct Node *dummy;
	while(temp->link!=NULL)
	{
		dummy=temp;
		temp=temp->link;
	}
	printf("You Know %d gets Deleted\n",temp->data);
	free(temp);	
	dummy->link=NULL;
}
void Delete_at_given_position(struct Node **p,int value,int pos)
{
	struct Node *temp,*dummy;
	temp=(struct Node *)malloc(sizeof(struct Node));
	temp=*p;
	int i=0;
	dummy=(struct Node *)malloc(sizeof(struct Node));
	while(temp->link!=NULL || i!=pos)
	{
		dummy=temp;
		temp=temp->link;
		i++;
	}
	if(temp->link==NULL)
	{
		printf("Please be generous enough to enter the right position");
	}
	else
	{
		dummy->link=temp->link;
		free(temp);
	}
}
void Delete_after_the_given_position(struct Node **p,int pos)
{
	struct Node *temp,*dummy;
	temp=(struct Node *)malloc(sizeof(struct Node));
	temp=*p;
	int i=0;
	dummy=(struct Node *)malloc(sizeof(struct Node));
	while(temp->link!=NULL || i!=(pos+1))
	{
		dummy=temp;
		temp=temp->link;
		i++;
	}
	if(temp->link==NULL)
	{
		printf("Please be generous enough to enter the right position");
	}
	else
	{
		dummy->link=temp->link;
		free(temp);
	}
}
void Delete_before_the_given_position(struct Node **p,int pos)
{
	struct Node *temp,*dummy,*r;
	temp=(struct Node *)malloc(sizeof(struct Node));
	temp=*p;
	dummy=(struct Node *)malloc(sizeof(struct Node));
	r=(struct Node*)malloc(sizeof(struct Node));
	int i=0;
	while(temp->link!=NULL || i!=pos)
	{
		r=dummy;
		dummy=temp;
		temp=temp->link;
		i++;
	}
	if(temp->link==NULL)
	{
		printf("Please be generous enough to enter the right position");
	}
	else
	{
		r->link=temp;
		free(dummy);
	}
}
void Display(struct Node **n)
{
	struct Node *temp;
	temp=(struct Node *)malloc(sizeof(struct Node));
	temp=*n;	
	while(temp->link!=NULL)
	{
		printf("%d---->",temp->data);
		temp=temp->link;
	}
	printf("%d",temp->data);
}
int main()
{
	struct Node *p;
	p=(struct Node *)malloc(sizeof(struct Node));
	p=NULL;
	Insert_at_beginning(&p,10);
	Insert_at_beginning(&p,100);
	Insert_at_end(&p,10000);
	Insert_at_given_pos(&p,15,1);
	Display(&p);
}