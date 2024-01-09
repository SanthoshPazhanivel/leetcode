#include<stdio.h>
#include<stdlib.h>
void findMatrix(int *arr,int size)
{
	int i,**ptr=NULL,j,k=0,sum=0,l=0;
label: 
	ptr=(int**)realloc(ptr,((l*1)+1)*sizeof(int *));
	for(i=0;i<size;i++)
	{
		if(arr[i]==0)
			continue;
		else
		{
			for(j=0;j<i;j++)
			{
				if(arr[i]==arr[j]) 
					break;
			}	
			if(j==i)
			{
				if(k==0)
					ptr[l]=NULL;
				ptr[l]=(int *)realloc(ptr[l],((k*1)+1)*sizeof(int));
				ptr[l][k]=arr[i];
				k=k+1;
			}
		}
	}
	sum=sum+k;
	for(i=0;i<k;i++)
		for(j=0;j<size;j++)
			if(ptr[l][i]==arr[j])
			{
				arr[j]=0;
				break;
			}
	for(i=0;i<k;i++)
		printf("%d ",ptr[l][i]);
	printf("\n");
	if(size!=sum)
	{
		l=l+1;
		k=0;
		goto label;
	}
}
int main()
{
	int arr[]={1,3,4,2,3,4,5,5,7,1,2,5},size;
	size = sizeof(arr)/sizeof(arr[0]);
	findMatrix(arr,size);
}
