#include<stdio.h>
#include<stdlib.h>
#include<math.h>

void display(int *a, int size)
{
	for(int i=0;i<size;i++)
		printf("%d ",a[i]);
    printf("\n");
}

void swap(int *a, int *b)
{
	int c=*a;
	*a=*b;
	*b=c;
}

int quickSort(int *a, int start, int end)
{
    int pivot=start;
    int i=start+1, j=end;
    if(start>=end)
    {
        return 0;
    }
    int x=0,y=0,z=0;
    while(1)
    {
        while(i<=end && a[i]<=a[pivot])
        {
            i++;x++;
        }
        while(a[j]>a[pivot])
        {
            j--;x++;
        }
        if(i>j)
        	break;
        swap(&a[i],&a[j]);
    }
    if(j!=pivot)
    	swap(&a[j],&a[pivot]);
    y = quickSort(a, start, j-1);
    z = quickSort(a, j+1, end);
    return x+y+z;
}

int main()
{
	int ch;
	printf("1.Sort\n2.Complexity\nEnter your choice: ");
	scanf("%d",&ch);
	
	if(ch == 1)
	{
		int n,*arr,i;
		printf("Enter size of array: ");
		scanf("%d",&n);
		printf("Enter array elements: ");
		arr = (int*)malloc(sizeof(int)*n);
		for(i=0;i<n;i++)
			scanf("%d",&arr[i]);
		int no_c = quickSort(arr,0,n-1);
		printf("Sorted array: ");
		display(arr,n);
		printf("\nNumber of comparisions: %d\n",no_c);
	}
	else if(ch == 2)
	{
		int n = 8,*arr;
		printf("\n%9c %9s %9s %9s %9s %9s %9s %9s %9s\n",'n',"n^2","asc","n^2/asc","des","n^2/des","nlogn","rd","nlogn/rd");
		while(n <= 16384)
		{
			int g = n*log2(n);
			int asc,des,rd;
			arr = (int*)malloc(sizeof(int)*n);
			for(int i=0;i<n;i++)
				arr[i] = i;
			asc = quickSort(arr,0,n-1);
			for(int i=n-1;i>=0;i--)
				arr[i] = i;
			des = quickSort(arr,0,n-1);
			for(int i=0;i<n;i++)
				arr[i] = rand();
			rd = quickSort(arr,0,n-1);
			printf("%9d %9d %9d %9.3f %9d %9.3f %9d %9d %9.3f\n",n,(n*n),asc,(float)(n*n)/asc,des,(float)(n*n)/des,g,rd,(float)g/rd);
			n *= 2;
		}
	}

	return 0;
}
