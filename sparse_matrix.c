#include<stdio.h>
int i,j,k,m,n;
int M[10][10],S[10][10],S2[20][20];
int A1[10][10],A2[10][10],C[10][10],T1[10][10],T2[10][10];

void read(){
printf("Enter rows,columns-m,n:\n");
scanf("%d",&m);
scanf("%d",&n);
printf("Enter the elements\n");
for(i=0;i<m;i++){
	for(j=0;j<n;j++){
		scanf("%d",&M[i][j]);	
}	printf("\n");
}	}

void disp(int M[10][10]){
for(i=0;i<m;i++){
	for(j=0;j<n;j++){
		printf("%d ",M[i][j]);	
}printf("\n");	
}}

void create_tuple(int S[10][10]){
S[0][0]=m;
S[0][1]=n;
k=1;
for(i=0;i<m;i++){
	for(j=0;j<n;j++){
		if (M[i][j] != 0){
			S[k][0]=i;
			S[k][1]=j;
			S[k][2]=M[i][j];
			k+=1;
		}	}
}S[0][2]=k-1;
}

void disp_tuple(int S[10][10]){
for(i=0;i<S[0][2]+1;i++){
	for(j=0;j<3;j++){
		printf("%d ",S[i][j]);
}
printf("\n");
}}


void transpose(){
S2[0][0]=S[0][1];
S2[0][1]=S[0][0];
S2[0][2]=S[0][2];
k=1;
m=S[0][1];
n=S[0][0];
for(i=0;i<m;i++){
	for (j=1;j<n+1;j++)
		if(S[i][j]==i){
			S2[k][0]=S[j][1];
			S2[k][1]=S[j][0];
			S2[k][2]=S[j][2];
			k+=1;
		}	
}
printf("The transposed tuple is\n");
for(i=0;i<=S2[0][2];i++){
	for(j=0;j<3;j++){
		printf("%d ",S2[i][j]);
}
printf("\n");
}}


void Add(){
int r1=A1[0][0];
int c1=A1[0][1];
int r2=A2[0][0];
int c2=A2[0][1];
if (r1!=r2 || c1!=c2)
	printf("Incompatible");
	
else{
	C[0][0]=A1[0][0];
	C[0][1]=A1[0][1];
	int m1=1;
	int n1=1;
	int k1=1;
	for (i=0;i<r1-1;r1++){
		for(j=0;j<c1-1;j++){
			if( A1[m1][0]==i && A1[m][1] ==j && A2[n1][0]==i && A2[n1][1]==j){
				C[k1][0]=A1[m1][0];
				C[k1][1]=A1[m1][1];
				C[k1][2]=A1[m1][2] + A2[n1][2];			
		}
		
		else if(A1[m1][0]==i && A1[m][1]==j){
            C[k1][0]=A1[m1][0];
            C[k1][1]=A1[m1][1];
            C[k1][2]=A1[m1][2];
            m1+=1;
            k1+=1;
        }
        else if(A2[n1][0]==i && A2[n1][1]==j){
            C[k1][0]=A2[n1][0];
            C[k1][1]=A2[n1][1];
            C[k1][2]=A2[n1][2];
            n1+=1;
            k1+=1;
        }
}			
}C[0][2]=k1-1;
}
}

void main(){
int ch;
printf("Select\n1-transpopse\n2-Add\n");
scanf("%d",&ch);
if (ch==1){

read();	
printf("The entered matrix is \n");
disp(M);
create_tuple(M);
printf("\n");
printf("The tuple representation is\n");
disp_tuple(S);
printf("\n");
transpose();

}
else if (ch==2){
read(A1);
create_tuple(T1);
read(A2);
create_tuple(T2);
Add();
disp_tuple(C);
}}