#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
struct node{
	char data;
	struct node *left,*right;
};

#define MAX 50
struct node* Stack[MAX];
int top=-1;	

struct node* newNode(char data){
	struct node* new=(struct node*)malloc(sizeof(struct node));
	new->data=data;
	new->left=new->right=NULL;
	return new;
}

void push(struct node* new){
	if(top<MAX-1){
		Stack[++top]=new;
	}	}

struct node* pop(){
	if(top!=-1)
		return Stack[top--];
	return NULL;
}

struct node* buildTree(char postfix[]){
	for(int i=0;postfix[i]!='\0';i++){
		char ch=postfix[i];
		if(isalnum(ch)){
			struct node* new=newNode(ch);
			push(new);
		}
		else{
			struct node* new=newNode(ch);
			new->right=pop();
			new->left=pop();
			push(new);
		}		}
	return pop();
}

void displayin(struct node* ptr){
	if(ptr!=NULL){
		displayin(ptr->left);
		printf("%c",ptr->data);
		displayin(ptr->right);
	}	
	}

void displaypre(struct node* ptr){
	if(ptr!=NULL){
		printf("%c",ptr->data);
		displaypre(ptr->left);
		displaypre(ptr->right);
	}	
	}

void displaypost(struct node* ptr){
	if(ptr!=NULL){
		displaypost(ptr->left);
		displaypost(ptr->right);
		printf("%c",ptr->data);
	}	
	}


int main(){
	char postfix[50];
	printf("Enter expression in postfix form:\n");
	scanf("%s",postfix);
	printf("\n");
	struct node* ptr=buildTree(postfix);
	printf("expression tree inorder traversal:\n");
	displayin(ptr);	
	printf("\n");
	printf("expression tree preorder traversal:\n");
	displaypre(ptr);
	printf("\n");
	printf("expression tree postorder traversal:\n");
	displaypost(ptr);
	printf("\n");
	return 0;
}
