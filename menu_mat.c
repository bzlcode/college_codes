#include <stdio.h>
/*displaying*/
void disp(int C[10][10],int m, int n)
{
for(int i=0;i<m;i++)
{   for(int j=0;j<n;j++)
    {   printf("%d\t",C[i][j]);
    }
    printf("\n");
}
}

void matadd()
{
    int m,n,i,j,k,A[10][10],B[10][10],C[10][10];
printf("Enter the number of rows: ");
scanf("%d",&m);
printf("Enter the number of columns: ");
scanf("%d",&n);
printf("Enter the elements for first matrix: \n");
for(i=0;i<m;i++)
{   for(j=0;j<n;j++)
    {   scanf(" %d",&A[i][j]);
    }
    printf("\n");
}
printf("Enter the elements for second matrix: \n");
for(i=0;i<m;i++)
{   for(j=0;j<n;j++)
    {   scanf(" %d",&B[i][j]);
    }
    printf("\n");
}
for(i=0;i<m;i++)
{   for(j=0;j<n;j++)
    {   printf("%d\t",A[i][j]);
    }
    printf("\n");
}
printf("\n");
for(i=0;i<m;i++)
{   for(j=0;j<n;j++)
    {   printf("%d\t",B[i][j]);
    }
    printf("\n");
}
printf("\n");
/*add*/
for(i=0;i<m;i++)
{   for(j=0;j<n;j++)
    {   C[i][j]=A[i][j]+B[i][j];
}
}
printf("After addition\n");
disp(C,m,n);
}
/*------*/
void matmul()
{
    int m,n,i,j,k,A[10][10],B[10][10],C[10][10];
printf("Enter the number of rows: ");
scanf("%d",&m);
printf("Enter the number of columns: ");
scanf("%d",&n);
printf("Enter the elements for first matrix: \n");
if(m==n)
{   
for(i=0;i<m;i++)
{   for(j=0;j<n;j++)
    {   scanf(" %d",&A[i][j]);
    }
    printf("\n");
}
printf("Enter the elements for second matrix: \n");
for(i=0;i<m;i++)
{   for(j=0;j<n;j++)
    {   scanf(" %d",&B[i][j]);
    }
    printf("\n");
}
for(i=0;i<m;i++)
{   for(j=0;j<n;j++)
    {   printf("%d\t",A[i][j]);
    }
    printf("\n");
}
printf("\n");
for(i=0;i<m;i++)
{   for(j=0;j<n;j++)
    {   printf("%d\t",B[i][j]);
    }
    printf("\n");
}
/*multiply*/
for(i=0;i<m;i++)
{   for(j=0;j<n;j++)
    {   C[i][j]=0;
        for(k=0;k<n;k++)
        {   C[i][j]+=A[i][k]*B[k][j];
        }
    }
}
printf("After multiplication\n");
disp(C,m,n);
}
else
printf("Enter equal no. of rows and columns");
}
/*------*/
void transp()
{       int m,n,i,j,k,A[10][10],B[10][10],C[10][10];
    printf("Enter the number of rows: ");
    scanf("%d",&m);
    printf("Enter the number of columns: ");
    scanf("%d",&n);
    printf("Enter the elements for the matrix: \n");
    for(i=0;i<m;i++)
    {   for(j=0;j<n;j++)
        {   scanf(" %d",&A[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    for(i=0;i<m;i++)
    {   for(j=0;j<n;j++)
        {   printf("%d\t",A[i][j]);
        }
        printf("\n");
    }
for(i=0;i<m;i++)
    {   for(j=0;j<n;j++)
        {   C[j][i]=A[i][j];
        }
    }
    printf("\n");
    printf("After transposing\n");
    disp(C,m,n);
}
int main()
{
    int x;
    printf("menu:\n");
    printf("addion-1\nmultiplicaton-2\ntranspose-3\nchoose one: ");
    scanf("%d",&x);
    switch(x)
    {   case 1: matadd();
                break;
        case 2: matmul();
                break;
        case 3: transp();
                break;
        default: printf("invalid");
}
return 0;
}