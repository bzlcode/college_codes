#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node{
char word[10];
char meaning[20];
struct node*left;
struct node*right;
};

int ch,flag=0;
char item[10];
char mean[20];
struct node*root = NULL ;
struct node*ptr = NULL ;
struct node*parent=NULL;

struct node* createNode(char word[], char meaning[]) {
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    strcpy(newNode->word, word);
    strcpy(newNode->meaning, meaning);
    newNode->left = newNode->right = NULL;
    return newNode;
}

void insert() {
    printf("Enter the word and its meaning : ");
    scanf("%s %s", item, mean);

    if (root == NULL) {
        root = createNode(item, mean);
        return;
    }

    ptr = root;
    parent = NULL;

    while (ptr != NULL) {
        if (strcmp(ptr->word, item) == 0) {
            printf("\nThe word '%s' already exists.\n", item);
            return;
        } 
        parent = ptr;
        if (strcmp(item, ptr->word) < 0)
            ptr = ptr->left;
        else
            ptr = ptr->right;
    }

    if (strcmp(item, parent->word) < 0)
        parent->left = createNode(item, mean);
    else
        parent->right = createNode(item, mean);
}

void inorder(struct node* ptr) {
    if (ptr != NULL) {
        inorder(ptr->left);
        printf("%s : %s\n", ptr->word, ptr->meaning);
        inorder(ptr->right);
    }
}

	
void search(){
	printf("Enter the word to search: ");
	scanf("%s", item);
	ptr=root;
	while(ptr!=NULL){
		if(strcmp(ptr->word,item)==0){
			printf("word: %s , meaning: %s",ptr->word,ptr->meaning);
		return;
		}
		if (strcmp(item,ptr->word)<0){
			ptr=ptr->left;
			}
		else
			ptr=ptr->right;
	}
printf("'%s' is not found\n", item);
}	

void main() {
    while (1) {
        printf("\nBinary Search Tree Dictionary:\n");
        printf("1. Insert a Word\n");
        printf("2. Search a Word\n");
        printf("3. Display Inorder\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                insert();
                break;
            case 2:
                search();
                break;
            case 3:
                inorder(root);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
}