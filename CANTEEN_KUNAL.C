#include<stdio.h>
#include<conio.h>
#include<malloc.h>

struct order
{
char food_name[20];
};

struct node
{
int data;
struct node*next;
};

void push();
void pop();
void display();
void count();

struct order e[20];
typedef struct node snode;
snode*p,*q;
snode*start=NULL;

void main()
{
int ch;
int ch1;
do
{
	clrscr();
	printf("\n...WELCOME TO FOOD ORDER SYSTEM ...\n\n");
	printf("Order food		   	press 1\n");
	printf("Display order		   	press 2\n");
	printf("Delete orderd food	   	press 3\n");
	printf("Count food items	   	press 4\n");
	printf("Exit			   	press 5\n");
	printf("\nEnter your choise:");
	scanf("%d",&ch);
	switch(ch)
	{
		case 1:push();
		break;
		case 2:display();
		break;
		case 3:pop();
		break;
		case 4:count();
		break;
		case 5:printf("\nTHANK YOU FOR VISITING\n");
		getch();
		exit();
		break;
}
printf("\n\nDo you want to go on main menu(press 6 for yes):");
scanf("%d",&ch1);
}
while(ch1==6);
getch();
}

snode*create_node(int x)
{
p=(snode*)malloc(sizeof(struct node*));
p->data=x;
p->next=NULL;
return p;
}

void push()
{
int x;
while(1)
{
printf(".......Select The Food From list.......\n\n");
printf("1 BURGER			|Rs 45|\n");
printf("2 SAMOSA			|Rs 10|\n");
printf("3 PIZZA				|Rs 60|\n");
printf("4 VADA PAV			|Rs 10|\n");
printf("5 COLD COFFEE			|Rs 45|\n");
printf("6 MILKSHAKE			|Rs 45|\n");
printf("7 TEA				|Rs 10|\n");
printf("\nType the appropriate number from the above list :\n");
scanf("%d",&x);
printf("\nFor main menu press 9\n");
if(x>7)
{break;
}
p=create_node(x);
if(start==NULL)
{
start=p;
}
else
{
q=start;
while(q->next!=NULL)
{
q=q->next;
}
q->next=p;
}
}
}
void pop()
{

int x;
printf(".......Select The Food From list.......\n\n");
printf("1 BURGER			|Rs 45|\n");
printf("2 SAMOSA			|Rs 10|\n");
printf("3 PIZZA				|Rs 60|\n");
printf("4 VADA PAV			|Rs 10|\n");
printf("5 COLD COFFEE			|Rs 45|\n");
printf("6 MILKSHAKE			|Rs 45|\n");
printf("7 TEA				|Rs 10|\n");
if(start==NULL)
{
printf("\nPlease order the food");
}
else
{
printf("\nOrderd food serial number are:\n");
{
q=start;
do
{
x=q->data;
printf("\norderd food number is %d \n",x);
q=q->next;
}while(q!=NULL);
}

printf("\nEnter the food number you have to delete:");
scanf("%d",&x);
q=start;
if(q->data==x)
{
printf("\norder number %d is remove",x);
start=q->next;
free(q);
}
else
{
while(q->next!=NULL)
{
if(q->next->data==x)
{
p=q;
q=q->next;
printf("\nyour ordered food %d is remove\n",x);
p->next=q->next;
free(q);
}
else
{
q=q->next;
}
}
}
}
}

void display()
{
int x;
printf(".......Select The Food From list.......\n\n");
printf("1 BURGER			|Rs 45|\n");
printf("2 SAMOSA			|Rs 10|\n");
printf("3 PIZZA				|Rs 60|\n");
printf("4 VADA PAV			|Rs 10|\n");
printf("5 COLD COFFEE			|Rs 45|\n");
printf("6 MILKSHAKE			|Rs 45|\n");
printf("7 TEA				|Rs 10|\n");
if(start==NULL)
{
printf("\nplease order the food");
}
else
{
q=start;
do
{
x=q->data;
printf("\nyou have order: ");
printf("%d",x);
q=q->next;
}while(q!=NULL);
}
}

void count()
{
int i=0;
q=start;
while(q!=NULL)
{
q=q->next;
i++;
}
printf("\nTotal number of food items ordered: %d\n",i);
}