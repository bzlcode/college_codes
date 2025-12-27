#include <stdio.h>
#include <string.h>
int n;
struct customer{
	char name[50];
	char category[5];
	int priority;
};

void remove_newline(char *str){
	int  i=0;
	while (str[i]!='\0'){
		if (str[i]=='\n'){
			str[i]='\0';
			break;
			}
		i++;
}	}

int getPriority(char category[]){
	if (strcmp(category,"DA")==0)
		return 1;
	else if (strcmp(category,"SN")==0)
		return 2;
	else if (strcmp(category,"DF")==0)
		return 3;
	else 
		return 4;
}

void sortCustomer(struct customer customer[],int n){
	int i,j;
	for (i=0;i<n-1;i++){
		for (j=0;j<n-i-1;j++){
			if (customer[j].priority>customer[j+1].priority){
				struct customer temp=customer[j];
				customer[j]=customer[j+1];
				customer[j+1]=temp;
				}
			}
		}
	}



int main(){
	int n,i,front=0,rear=n-1;
	printf("Enter the no.of customers ");
	scanf(" %d",&n);
	getchar();
	
	struct customer customers[n];
	for (i=0;i<n;i++){
		printf("Enter name of customer %d ",i+1);
		fgets(customers[i].name,sizeof(customers[i].name),stdin);
		remove_newline(customers[i].category);
		
		printf("\n");
		printf("Enter category, \nDA-disabled\nSN-senior citizen\nDF-defence  personnel\nNP-normal person ");
		fgets(customers[i].category,sizeof(customers[i].category),stdin);
		remove_newline(customers[i].category);
	
		customers[i].priority=getPriority(customers[i].category);
		printf("\n");
	}
	printf("\n");
	sortCustomer(customers,n);
	printf("priority order\n");
	for (i=0;i<n;i++){
		printf("%s (%s)\n",customers[i].name,customers[i].category);
	}
	return 0;
}
