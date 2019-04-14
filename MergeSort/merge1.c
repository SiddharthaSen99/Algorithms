#include"merge1.h"

int mergeSort(int *a,int size)
{
	if(size<=1)
		return 0;
	int mid=size/2;
	int L[mid],R[size-mid];
	int i,j,x,y,z;
	for(i=0;i<mid;i++)
		L[i]=a[i];
	for(i=mid,j=0;i<size;i++,j++)
		R[j]=a[i];
	x=mergeSort(L,mid);				//Merge and sort left sub-array
	y=mergeSort(R,size-mid);		//Merge and sort right sub-array
	z=merge(L,mid,R,size-mid,a);	//Merge both sub-arrays
	return x+y+z;
}

int merge(int *L,int Lsize,int *R,int Rsize,int *a)
{
	int k,i,j,x=0;
	i=j=k=0;
	while(i<Lsize && j<Rsize)
	{
		x++;			//No of comparisons
		if(L[i]<=R[j])
			a[k]=L[i++];
		else
			a[k]=R[j++];
		k++;
	}
	//COpy remaining elements from sub-arrays if any 
	while(i<Lsize)
	{
		a[k]=L[i];
		k++; i++;
	}
	while(j<Rsize)
	{
		a[k]=R[j];
		k++; j++;
	}
	return x;
}

	
void display(int *a, int size)
{
	for(int i=0;i<size;i++)
		printf("%d ",a[i]);
	printf("\n");
}
	
