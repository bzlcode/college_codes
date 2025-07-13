#include<stdio.h>
struct poly{
    int coeff;
    int expo;
}p1[10],p2[10],p3[10];

int readpoly(struct poly p[10]){
    int t;
    printf("Enter the no. of terms: ");
    scanf("%d",&t);
    printf("Enter the coeff and power of each term\n");
    for (int i=0;i<t;i++){
        scanf("%d",&p[i].coeff);
        scanf("%d",&p[i].expo);
        printf("\n");
    }
    return t;
}

void displaypoly(struct poly p[10],int t){
    for(int i=0;i<t-1;i++){
        printf("%dX^%d + ",p[i].coeff,p[i].expo);
    }
    printf("%dX^%d\n",p[t-1].coeff,p[t-1].expo);
}

int addpoly(struct poly p1[10],struct poly p2[10],int t1,int t2,struct poly p3[10]){
    int i=0;
    int j=0;
    int k=0;
    while (i<t1 && j<t2){
        if (p1[i].expo == p2[j].expo){
            p3[k].coeff=p1[i].coeff+p2[j].coeff;
            p3[k].expo=p1[i].expo;
            i+=1;
            j+=1;
            k+=1;
        } 
        else if(p1[i].expo > p2[j].expo){
            p3[k].coeff=p1[i].coeff;
            p3[k].expo=p1[i].expo;
            i+=1;
            k+=1;
        }
        else{
        p3[k].coeff=p2[j].coeff;
            p3[k].expo=p2[j].expo;
            j+=1;
            k+=1;
        }
    }
    while (i<t1){
        p3[k].coeff=p1[i].coeff;
        p3[k].expo=p1[i].expo;
        i++;
        k++;
    }
    while (j<t2){
        p3[k].coeff=p2[j].coeff;
        p3[k].expo=p2[j].expo;
        j++;
        k++;
    }
    return k;
}

void main(){
   int t1=readpoly(p1);
   displaypoly(p1,t1);
   int t2=readpoly(p2);
   displaypoly(p2,t2);  
   int t3= addpoly(p1,p2,t1,t2,p3);
   displaypoly(p3,t3);
}