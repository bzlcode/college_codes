#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node {
char url[100];
struct node *prev ,*curr,*nxt;
};

struct node *head=NULL;
struct node *curr=NULL;
struct node *ptr;

void visit(){
struct node *new=(struct node*)malloc(sizeof(struct node));
if (new==NULL){
	printf("error");
	return ;
	}
printf("Enter the url to visit: ");
scanf("%s",new->url);
new->nxt=NULL;
new->prev=NULL;
if (head == NULL)
	head=curr=new;
else {
	curr->nxt=new;
	new->prev=curr;
	curr=new;
	}
printf("visited %s",curr->url);
}

void forward(){
if (ptr==NULL)
	printf("no pages visited\n");
else if(ptr->nxt==NULL)
	printf("Already the last page\n");
else{
	ptr=ptr->nxt;
	printf("Forward to %s",ptr->url);
	}
}

void backward(){
if (ptr==NULL)
	printf("no pages visited\n");
else if(ptr->prev==NULL)
	printf("Already the first page\n");
else{
	ptr=ptr->prev;
	printf("backward to %s",ptr->url);
	}
}

void history(){
struct node *ptr;
if (head ==NULL)
	printf("No pages\n");
else{
	ptr=head;
	while(ptr!=NULL){
		printf("%s->",ptr->url);
		ptr=ptr->nxt;
			}
	}
}

int main(){
int ch;

do{
printf("\n__MENU__\n1.visit a page\n2.go forward\n3.go backward\n4.show history\n5.exit\n");
scanf("%d",&ch);
switch(ch){
case 1:visit();ptr=curr;break;
case 2:forward();break;
case 3:backward();break;
case 4:history();break;
case 5:exit(0);
}
}while (1);
return 0;
}
