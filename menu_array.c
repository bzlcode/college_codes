#include<stdio.h>
int n,i,arr[20];
void read(){
    printf("Enter the number of elements\n");
    scanf("%d\n",&n);
    for (i=0;i<n ;i++){
        scanf("%d",&arr[i]);
    }
}

void disp(){
    for (i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}

void insert(){
    int num,ind;
    printf("Enter the number to insert:\n");
    scanf("%d",&num);
    printf("Enter the index\n");
    scanf("%d",&ind);
    for (i=n-1;i>=ind-1;i--){
        arr[i+1]=arr[i];
    }
    arr[ind]=num;
    n++;
}

void del_pos(){
    int pos;
    printf("Enter the position to delete\n");
    scanf("%d",&pos);
    for(i=pos;i<=n-1;i++){
        arr[i]=arr[i+1];
    }
    n--;
}

void del_el(){
    int el,ind;
    printf("Enter the element\n");
    scanf("%d",&el);
    for(i=0;i<n;i++){
        if(arr[i]==el){
            ind=i;
            break;
            }
        }
    for (i=ind;i<n;i++){
        printf("%d",i);
        arr[i]=arr[i+1];
    }
    n--;
}

void search(){
    int el;
    printf("Enter element\n");
    scanf("%d",&el);
    for (i=0;i<n;i++){
        if (arr[i]==el ){
            printf("Element found at index %d",i);
        break; 
        }  
    }
}
int main(){
    int op;
    printf("choose operation\n");
    printf(" 1-read\n 2-display\n 3-insert \n 4-delete postion \n 5-delete element\n 6-search\n ");
    scanf("%d",&op);
    
    switch (op)
    {
        case 1:
            read();
            break;
        case 2:
            disp();
            break;
        case 3:
            insert();
            break;
        case 4:
            del_pos();
            break;
        case 5:
            del_el();
            break;
        case 6:
            search();
            break;
        default :
            printf("Invalid");  
        }  
        printf("\n");

        if (op<7){
            main();    
        }
        else{
            return 0;
}       }