#include<stdio.h>
#include<malloc.h>
long long int k=0;
long long int a[500005];
void Merge(long long int *R,long long int low,long long int m,long long int high)
{
    long long int i=low,j=m+1,p=0;
    long long int *R1;
    R1=(long long int *)malloc((high-low+1)*sizeof(long long int));
    while(i<=m&&j<=high)
    {
        if(R[i]<=R[j])
        {
            R1[p++]=R[i++];
        }
        else
        {
            R1[p++]=R[j++];
            k+=(m-i+1);
        }
    }
    while(i<=m)
        R1[p++]=R[i++];
    while(j<=high)
    {
        R1[p++]=R[j++];
    }

    for(p=0,i=low; i<=high; p++,i++)
        R[i]=R1[p];
    free(R1);
}
void MergeSortDC(long long int *R,long long int low,long long int high)
{
    long long int mid;
    if(low<high)
    {
        mid=(low+high)/2;
        MergeSortDC(R,low,mid);
        MergeSortDC(R,mid+1,high);
        Merge(R,low,mid,high);
    }
}
int main()
{
    long long int i,N;
    while(scanf("%lld",&N)&&N)
    {
        k=0;
        for(i=0; i<N; i++)
            scanf("%lld",&a[i]);
        MergeSortDC(a,0,N-1);
        printf("%lld\n",k);
    }
    return 0;
}
