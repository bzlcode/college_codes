#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node{
char str[50];
struct node*link;
};
struct node *ptr=NULL;
struct node *head=NULL;
void insert(){
struct node*new=(struct node*)malloc(sizeof(struct node));
printf("Enter word to insert:\n");
scanf("%s",new->str);
new->link=NULL;
if (head==NULL)
head=new;
else{
ptr=head;
while(ptr->link!=NULL)
ptr=ptr->link;
ptr->link=new;
}
}
void findnrep(){
int flag=0;
char key[50],x[50];
if (head==NULL){
printf("empty..cant find or replace\n");
exit(0);
}
struct node*new=(struct node*)malloc(sizeof(struct node));
printf("Enter key to search:\n");
scanf("%s",key);
printf("Enter word to replace:\n");
scanf("%s",x);
ptr=head;
while(ptr!=NULL){
if(strcmp(ptr->str,key)==0){
flag=1;
strcpy(ptr->str,x);
}
ptr=ptr->link;
}
if (flag==0)
printf("Cant find the word %s\n",key);
}
void disp(){
ptr=head;
while(ptr!=NULL){
printf("%s ",ptr->str);
ptr=ptr->link;
}
}
int main(){
int ch;
do{
printf("\n__MENU__\n1.insert\n2.find and replace\n3.display\n4.exit\n");
scanf("%d",&ch);
switch(ch){
case 1:insert();break;
case 2:findnrep();break;
case 3:disp();break;
case 4:exit(0);
}
}while (1);
return 0;
}