#include<stdio.h>
#include<stdlib.h>
struct node{
int coeff;
int expo;
struct node*link;
};

struct node*Phead=NULL;
struct node*Qhead =NULL;
struct node*Rhead= NULL;

void createpoly1(){
struct node*p=NULL;
int c,e,n1;
printf("Enter the no.terms in 1st polynomial: ");
scanf("%d",&n1);
for(int i=0;i<n1;i++){
	printf("Enter the coeff. and exponent \n");
	scanf("%d%d",&c,&e);
	
	struct node*new=(struct node*)malloc(sizeof(struct node));
	new->link=NULL;
	new->coeff=c;
	new->expo=e;
	if (Phead==NULL)
		Phead=p=new;
	else{
		p->link=new;
		p=new;
	     }
		}
}

void createpoly2(){
struct node*q=NULL;
int c,e,n2;
printf("Enter the no.terms in 2nd polynomial: ");
scanf("%d",&n2);
for(int i=0;i<n2;i++){
	printf("Enter the coeff. and exponent \n");
	scanf("%d%d",&c,&e);
	
	struct node*new=(struct node*)malloc(sizeof(struct node));
	new->link=NULL;
	new->coeff=c;
	new->expo=e;
	
	if (Qhead==NULL)
		Qhead=q=new;
	else{
		q->link=new;
		q=new;
	    }
		}
}

void display(){
struct node*r=Rhead;
printf("__Result__\n");
if (Rhead==NULL)
	printf("no polynomial\n");
else{
	while(r!=NULL){
		printf("%dx^%d",r->coeff,r->expo);
		if (r->link!=NULL)
			printf(" + ");
		r=r->link;
	}
			}
printf("\n");
printf("\n");
Rhead=NULL;
}

void addpoly(){
struct node*p=Phead;
struct node*q=Qhead;
struct node*r=Rhead;
while(p!=NULL &&q!=NULL){
	struct node*new=(struct node*)malloc(sizeof(struct node));
	if(p->expo==q->expo){
		new->coeff=p->coeff+q->coeff;
		new->expo=p->expo;
		new->link=NULL;
		p=p->link;
		q=q->link;
			}
	else if(p->expo>q->expo){
	        new->coeff=p->coeff;
	        new->expo=p->expo;
	        new->link=NULL;
	        p=p->link;
		}
	else{
		new->coeff=q->coeff;
	        new->expo=q->expo;
	        new->link=NULL;
	        q=q->link;
		}
	if(Rhead==NULL)
		Rhead=r=new;
	else{
		r->link=new;
		r=new;
		}	
	
	}
	
while (p!=NULL){
	struct node*new=(struct node*)malloc(sizeof(struct node));
	new->coeff=p->coeff;
	new->expo=p->expo;
	new->link=NULL;
	if(Rhead==NULL)
		Rhead=r=new;
	else{
		r->link=new;
		r=new;
		}
	p=p->link;
		}
		
while (q!=NULL){
	struct node*new=(struct node*)malloc(sizeof(struct node));
	new->coeff=q->coeff;
	new->expo=q->expo;
	new->link=NULL;
	if(Rhead==NULL)
		Rhead=r=new;
	else{
		r->link=new;
		r=new;
	}
	q=q->link;
		}
}


void mulpoly(){
    struct node*p=Phead;
    struct node*q=Qhead;
    struct node*r=Rhead;
    while(p!=NULL){
        while(q!=NULL){
            struct node*new=(struct node*)malloc(sizeof(struct node));
            new->coeff=p->coeff *q->coeff;
            new->expo=p->expo+q->expo;
            new->link=NULL;
            if(Rhead==NULL)
                Rhead=r=new;
            else{
                r->link=new;
                r=new;
            }
            q=q->link;
        }
        p=p->link;
        q=Qhead;
    }
    p=Rhead;
    while(p!=NULL){
        struct node*prev=p;
        q=p->link;
        while(q!=0){
            if(p->expo==q->expo){
                p->coeff=p->coeff+q->coeff;
                prev->link=q->link;
                free(q);
                q=prev->link;
            }
            else{
                prev=q;
                q=q->link;
            } 
        } p=p->link;
    }
}

void main(){
int ch;
createpoly1();
createpoly2();
do{
printf("Enter the choice:\n1.addition\n2.multiplication\n");
scanf("%d",&ch);
switch (ch){
	case 1:addpoly(); display();
		break;
	case 2:mulpoly();display();
		break;
	case 3:exit(0);
		break;
	default:printf("invalid choice");
}
} while(1); 

}
