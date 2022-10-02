# include<stdio.h>
# define maxWeight 10001
/*Find the minimum of array */
int min(int * arr,int lenArr)
{
	int i,minimum=maxWeight;
	for (i=0;i<lenArr;i++) if (arr[i] < minimum ) minimum=arr[i];
	return minimum;
}
/*Set maxWeight as value in given value range of array*/
void set(int * arr,int lenArr,int from,int to)
{
	int i;
	for (i=0;i<lenArr;i++) if (arr[i] <= to && arr[i] >= from) arr[i]=maxWeight;
}
int main()
{
	// Get N and weights as weightArr
	int n,i=0,count=0;
	scanf("%d",&n);
	int weightArr[n];
	for (i=0;i<n;i++)scanf("%d",&weightArr[i]);
	
	/* Algorithm */
	int minimum=min(weightArr,n);
	/*find the minimum repeat the process untill all elements are visited*/
	while(minimum < maxWeight) 
	{
		/*make all values are visited weighing within 4 units*/
		set(weightArr,n,minimum,minimum+4);
		minimum=min(weightArr,n);
		count++;//increment count
	}

	printf("%d",count); 
	return 0;
}
