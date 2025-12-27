#include <stdio.h>
int n,arr[50];

int binarySearch(int low,int high ,int key){
int mid,flag =0;
while(low<=high){
	mid=(low+high)/2;
	if (arr[mid]==key){
		flag=1;
		return mid;
	}
	if (arr[mid]>key)
		high=mid-1;
	else 
		low=mid+1;
}
return 0;
}

void main(){
int key;
printf("Enter the size of the array");
printf("\n");
scanf(" %d",&n);
printf ("Enter the sorted array, one element at a time\n");
for (int i=0;i<n;i++){
	scanf("%d",&arr[i]);
}
printf("Enter the element to search: ");
scanf("%d",&key);
int low=0;
int high=n-1;
int k=binarySearch(low,high,key);
if (k==0)
	printf("Element not found");
else
	printf("Element found at index: %d",k);
}
