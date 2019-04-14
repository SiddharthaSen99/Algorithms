#include "merge1.h"

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
		int no_c = mergeSort(arr,n);
		printf("Sorted array: ");
		display(arr,n);
		printf("\nNumber of comparisions: %d\n",no_c);
	}
	else if(ch == 2)
	{
		int n = 8,*arr;
		printf("\n%10c %10s %10s %10s %10s %10s %10s %10s %10s\n",'n',"n^2","nlogn","asc","nlogn/asc","des","nlogn/des","rd","nlogn/rd");
		while(n <= 16384)
		{
			int g = n*log(n);
			int asc,des,rd;
			arr = (int*)malloc(sizeof(int)*n);
			for(int i=0;i<n;i++)
				arr[i] = i;
			asc = mergeSort(arr,n);
			for(int i=n-1;i>=0;i--)
				arr[i] = i;
			des = mergeSort(arr,n);
			for(int i=0;i<n;i++)
				arr[i] = rand();
			rd = mergeSort(arr,n);
			printf("%10d %10d %10.3f %10d %10.3f %10d %10.3f %10d %10.3f\n",n,(n*n),(float)g,asc,(float)g/asc,des,(float)g/des,rd,(float)g/rd);
			n *= 2;
		}
	}

	return 0;
}
