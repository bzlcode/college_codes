#include <stdio.h>
int front=-1, rear=-1 , size=100,q[100];
void create(){
    printf("Enter the size\n");
    scanf("%d",&size);
    printf("Enter the elements\n");
    for (int i=0;i<size;i++){
    scanf("%d",&q[i]);
    }
    front=0;
    rear=size-1;
}
void enqueue(int item){
    if (rear=size-1)
        printf("full");
    else if(front== -1 && rear== -1){   

        front=0;
        rear=0;                     

        q[front]=item; }
    else {
        rear+=1;
        q[rear]=item;
    }
    }

void q_print(){
    for(int i=front;i<rear+1;i++){
        printf("%d,",q[i]);
    }
}
void main(){
    int item;
    create();
    printf("Enter the item to add\n");
    scanf("%d",&item);
    enqueue(item);
    printf("\n");
    q_print();
}