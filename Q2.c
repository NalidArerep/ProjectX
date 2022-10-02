#include<stdio.h>
int main()
{
    unsigned long n;
    scanf("%lu",&n);
    unsigned long scoreArr[n],maskArr[n],i,totalMasks=0;

    for(i=0;i<n;i++)
    {
        scanf("%lu",&scoreArr[i]);
        maskArr[i]=1;
    }
     /* Check left to right in scoreArray and give extra mask for student with hegier score than previous one.*/
    for(i=n-1;i>0;i--)if(scoreArr[i]<scoreArr[i-1])maskArr[i-1]=maskArr[i]+1;
    /* Check right to left in scoreArray and give extra mask for student with hegier score and lesser masks than next one.*/
    for(i=0;i<n-1;i++)if(scoreArr[i]<scoreArr[i+1] && maskArr[i] >= maskArr[i+1])maskArr[i+1]=maskArr[i]+1;
    /*calculate the total masks needed*/
    for(i=0;i<n;i++)totalMasks+=maskArr[i];
    printf("%lu",totalMasks);
    return 0;
}
