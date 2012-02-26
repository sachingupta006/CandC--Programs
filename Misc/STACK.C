#include<stdio.h>
/*
struct stack
{
	int no;
	struct stack *next;
}*top;
main()
{
	int ch;
	top=NULL;
	clrscr();
	do
	{
		printf("\t\tSTACK OPERATION\n");
		printf("\t\t===============\n");
		printf("\t\t1.PUSH\n");
		printf("\t\t2.POP\n");
		printf("\t\t3.DISPLAY\n");
		printf("\t\t4.EXIT\n");
		printf("\tEnter your choice\n");
		scanf("%d",&ch);
		if(ch==1)
			push();
		else if(ch==2)
			pop();
		else if(ch==3)
			display();
		else
			break;
	}
	while(ch!=4);
	getch();
}
push()
{
	struct stack *ptr,*new1;
	new1=(struct stack *)malloc(sizeof(struct stack));
	printf("\nEnter the no:");
	scanf("%d",&new1->no);
	new1->next=NULL;
	if(top==NULL)
	{
		top=new1;
	}
	else
	{
		new1->next=top;
		top=new1;
	}
}
pop()
{
	struct stack *ptr;
	if(top==NULL)
	{
		printf("\nStack is empty\n");
	}
	else
	{
		ptr=top;
		printf("\n\nThe poped value is :%d\n\n",ptr->no);
		top=top->next;
		free(ptr);
	}
}
display()
{
	struct stack *ptr;
	ptr=top;
	printf("\n\nThe stack is .....\n\n");
	while(ptr!=NULL)
	{
		printf("%d\t",ptr->no);
		ptr=ptr->next;
	}
	printf("\n");
}
*/

/*
struct queue
{
	int no;
	struct queue *next;
}*front,*rear;
main()
{
	int ch;
	front=rear=NULL;
	clrscr();
	do
	{
		printf("\t\tQUEUE OPERATION\n");
		printf("\t\t===============\n");
		printf("\t\t1.ADDITION\n");
		printf("\t\t2.DELETION\n");
		printf("\t\t3.DISPLAY\n");
		printf("\t\t4.EXIT\n");
		printf("\tEnter your choice\n");
		scanf("%d",&ch);
		if(ch==1)
			add();
		else if(ch==2)
			del();
		else if(ch==3)
			display();
		else
			break;
	}
	while(ch!=4);
	getch();
}
add()
{
	struct queue *ptr,*new1;
	new1=(struct queue *)malloc(sizeof(struct queue));
	printf("\nEnter the no:");
	scanf("%d",&new1->no);
	new1->next=NULL;
	if(rear==NULL)
	{
		front=new1;
		rear=new1;
	}
	else
	{
		rear->next=new1;
		rear=new1;
	}
}
del()
{
	struct queue *ptr;
	ptr=front;
	if(front==NULL)
	{
		printf("\nQueue is empty\n");
	}
	else
	{
		front=front->next;
		printf("\n\nThe deleted value is :%d\n\n",ptr->no);
		free(ptr);
	}
}
display()
{
	struct queue *ptr;
	ptr=front;
	printf("\n\nThe Queue is .....\n\n");
       while(ptr!=NULL)
	{
		printf("%d\t",ptr->no);
		ptr=ptr->next;
	}
	printf("\n");
}
*/
/*
main()
{

struct llist
{
	int no;
	struct llist *next;
};
struct llist *start=NULL,*ptr,*new1;
char ch='y';
clrscr();
while(ch=='y')
{
	new1=(struct llist *)malloc(sizeof(struct llist));
	printf("\nEnter the no:");
	scanf("%d",&new1->no);
	new1->next=NULL;
	if(start==NULL)
	{
		start=new1;
		ptr=new1;
	}
	else
	{
		ptr->next=new1;
		ptr=new1;
	}
	printf("\nDo u wish to continue:");
	ch=getch();
}
ptr=start;
printf("\n\nThe linklist is ......\n\n");
while(ptr!=NULL)
{
	printf("%d\t",ptr->no);
	ptr=ptr->next;
}
getch();
}
*/
/*

struct llist
{
	int no;
	struct llist *next;
}*start;
main()
{
	int ch;
	start=NULL;
	clrscr();
	do
	{
	printf("\t\tSINGLE LINKLIST OPERATION\n");
	printf("\t\t=========================\n");
	printf("\t\t1.CREATION\n");
	printf("\t\t2.INSERTION\n");
	printf("\t\t3.DELETION\n");
	printf("\t\t4.SEARCH\n");
	printf("\t\t5.DISPLAY\n");
	printf("\t\t6.MODIFICATION\n");
	printf("\t\t7.EXIT\n");
	printf("\t\tEnter the choice:\n");
	scanf("%d",&ch);
	if(ch==1)
		create();
	else if(ch==2)
		insert();
	else if(ch==3)
		del();
	else if(ch==4)
		search();
	else if(ch==5)
		display();
	else if(ch==6)
		mod();
	else if(ch==7)
	{
		printf("Bye Bye....");
		break;
	}
	}
	while(ch!=7);
	getch();
}
create()
{
	struct llist *new1,*ptr;
	char ch='y';
	while(ch=='y')
	{
	new1=(struct llist *)malloc(sizeof(struct llist));
	printf("\nEnter the no:");
	scanf("%d",&new1->no);
	new1->next=NULL;
	if(start==NULL)
	{
		start=new1;
		ptr=new1;
	}
	else
	{
		ptr->next=new1;
		ptr=new1;
	}
	printf("One node added\n");
	printf("\nDo u wish to add more:");
	ch=getch();
	printf("\n\n");
	}

}

insert()
{
	int ch1;
	do
	{
		printf("INSERTION MENU\n");
		printf("+++++++++++++++\n");
		printf("1.BEGINING\n");
		printf("2.MIDDLE\n");
		printf("3.END\n");
		printf("4.RETURN\n");
		printf("Enter the choice\n");
		scanf("%d",&ch1);
		if(ch1==1)
			addbeg();
		else if(ch1==2)
			addmid();
		else if(ch1==3)
			addend();
		else if(ch1==4)
			return;
		else
			printf("Invalid chocie\n");
	}
	while(ch1!=4);
}

addbeg()
{
	struct llist *new1;
	new1=(struct llist *)malloc(sizeof(struct llist));
	printf("\nEnter the no:");
	scanf("%d",&new1->no);
	new1->next=NULL;

	new1->next=start;
	start=new1;
}
addmid()
{
	struct llist *prev,*ptr,*new1;
	int n;
	new1=(struct llist *)malloc(sizeof(struct llist));
	printf("\nEnter the no:");
	scanf("%d",&new1->no);
	new1->next=NULL;
	printf("Enter the no. where u want to insert the new node:");
	scanf("%d",&n);
	for(ptr=start;ptr!=NULL;prev=ptr,ptr=ptr->next)
	{
		if(ptr->no==n)
			break;
	}
	prev->next=new1;
	new1->next=ptr;
	printf("\none node added\n");
}
addend()
{
	struct llist *new1,*ptr;
	new1=(struct llist *)malloc(sizeof(struct llist));
	printf("\nEnter the no:");
	scanf("%d",&new1->no);
	new1->next=NULL;
	ptr=start;
	for(ptr=start;ptr->next!=NULL;ptr=ptr->next);

	ptr->next=new1;
	ptr=new1;

}

del()
{

	int ch2;
	do
	{
		printf("DELETION MENU\n");
		printf("+++++++++++++++\n");
		printf("1.BEGINING\n");
		printf("2.MIDDLE\n");
		printf("3.END\n");
		printf("4.RETURN\n");
		printf("Enter the choice\n");
		scanf("%d",&ch2);
		if(ch2==1)
			delbeg();
		else if(ch2==2)
			delmid();
		else if(ch2==3)
			delend();
		else if(ch2==4)
			return;
		else
			printf("Invalid chocie\n");
	}
	while(ch2!=4);
}
delbeg()
{
	struct llist *ptr;
	ptr=start;
	start=start->next;
	free(ptr);
	printf("one node deleted\n");
}
delmid()
{
	struct llist *ptr,*prev;
	int n;
	printf("Enter the node that u want to delete:");
	scanf("%d",&n);
	for(ptr=start;ptr->next!=NULL;prev=ptr,ptr=ptr->next)
	{
		if(ptr->no==n)
			break;
	}
	prev->next=ptr->next;
	free(ptr);
	printf("One node deleted\n");
}
delend()
{
	struct llist *ptr,*prev;
	for(ptr=start;ptr->next!=NULL;prev=ptr,ptr=ptr->next);
	prev->next=NULL;
	free(ptr);
	printf("One node deleted\n");
}


search()
{
	struct llist  *ptr;
	int n;
	printf("Enter the no. that u want to search:");
	scanf("%d",&n);
	for(ptr=start;ptr!=NULL;ptr=ptr->next)
	{
		if(ptr->no==n)
		{
			printf("Node found\n");
			break;
		}
	}
	if(ptr==NULL)
		printf("Not found\n");


}
display()
{
	struct llist *ptr;
	ptr=start;
	printf("\n\nThe linklist is ......\n\n");
	while(ptr!=NULL)
	{
		printf("%d\t",ptr->no);
		ptr=ptr->next;
	}
	 printf("\n");
}

mod()
{
	struct llist *ptr;
	int n;
	printf("Enter the no. that u want to search:");
	scanf("%d",&n);
	for(ptr=start;ptr!=NULL;ptr=ptr->next)
	{
		if(ptr->no==n)
		{
			printf("No. is :%d",ptr->no);
			break;
		}
	}
	printf("Enter the new no.:");
	scanf("%d",&ptr->no);

}
*/

#include<stdio.h>
#include<conio.h>
#include<alloc.h>

struct bnode
{
	int data;
	struct bnode *next;
}*start;

struct bnode *getdata()
{
	struct bnode *new1;
	new1=(struct bnode*)malloc(sizeof(struct bnode));
	printf("\n\n enter the node value:");
	scanf("%d",&new1->data);
	return new1;
}

//function to add  new nodes

add()
{
	struct bnode *ptr,*x;
	x=getdata();
	if(start==NULL)
	{
		start=x;
		x->next=start;
	}
	else
	{
		for(ptr=start;ptr->next!=start;ptr=ptr->next);
		ptr->next=x;
		x->next=start;
	}
	return;
}

disp()
{
	struct bnode *ptr;
	ptr=start;
	printf("\nThe list is-");
	do
	{
		printf("%d-",ptr->data);
		ptr=ptr->next;
	}while(ptr!=start);
	return 0;
}

//functions to insert a node in the middle
insert(int ins,int nv)
{
	struct bnode *inst,*ptr,*pn;
	inst=(struct bnode*)malloc(sizeof(struct bnode));
	inst->data=nv;
	ptr=start;
	do
	{
		if(ptr->data==ins)
		{
			pn=ptr->next;
			ptr->next=inst;
			inst->next=pn;
			break;
		}
		else
			ptr=ptr->next;
	}while(ptr!=start);
	return;
}

//functions to delete a particular node
delet(int dn)
{
	struct bnode *ptr,*prev,*pnn;
	ptr=start;
	if(start->data==dn)
	{
		for(ptr=start;ptr->next!=start;ptr=ptr->next);
		ptr->next=start->next;
		start=ptr->next;
	}
	else
	{
		do
		{
			if(ptr->data==dn)
			{
				pnn=ptr->next;
				prev->next=pnn;
				break;
			}
			prev=ptr;
			ptr=ptr->next;
		}while(ptr!=start);
	}
	return;
}


void main()
{
	int n,ins,nv,deln;
	start=NULL;
	clrscr();
	do
	{
		printf("\n\nMENU");
		printf("\n******");
		printf("\n\n1.add");
		printf("\n\n2.display list");
		printf("\n\n3.insertion");
		printf("\n\n4.deletion");
		printf("\n\n5.exit");
		printf("\n\nenter ur choice");
		scanf("%d",&n);
		if(n==1)
		{
			printf("\n\n addition of a new node");
			add();
		}
		if(n==2)
		{
			disp();
		}
		if(n==3)
		{
			printf("\n\n insertion in the middle");
			printf("\n-------------------------");
			printf("\n\n enter after which node:");
			scanf("%d",&ins);
			printf("\n\n enter the new node value:");
			scanf("%d",&nv);
			insert(ins,nv);
			disp();
		}
		if(n==4)
		{
			printf("\n\n deletion of a node");
			printf("\n--------------------");
			printf("\n\n enter the node to be deleted");
			scanf("%d",&deln);
			delet(deln);
			disp();
		}
	}while(n>0 && n<5);
}












