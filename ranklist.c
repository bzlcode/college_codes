#include<stdio.h>
struct stud
{
    char name[10];
    int no;
    float mark;
}s[50],temp;

int i;

int bsort(struct stud s[i],int n)
{
    for (int j=0;j<n;j++)
    {
        for (int k=0;k<n-j-1;k++)
        {
            if ( s[k].mark < s[k+1].mark)
            {
                temp= s[k];
                s[k]=s[k+1];
                s[k+1]=temp;
            }
        }
    }
}

void main()
{
    int n;
    printf ("Enter the no.of students: ");
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        printf("Details of student %d\n",i+1);
        printf ("Enter roll no.: ");
        scanf ("%d",&s[i].no);
        printf("Enter name:");
        scanf ("%s",s[i].name);
        printf ("Enter mark: ");
        scanf("%f",&s[i].mark);
    }   
    bsort(s,n);
    printf ("rank\troll no.\tname\tmark\n");
    for (i=0;i<n;i++)
    {
        printf("%d\t%d\t\t%s\t%f\n",i+1,s[i].no,s[i].name,s[i].mark);
    }
}