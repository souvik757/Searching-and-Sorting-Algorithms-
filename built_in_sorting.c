#include<stdio.h>
#include<stdlib.h>
int computeFunction(const void* X,const void* Y)
{
    long long int a = *(long long int*)X;
    long long int b = *(long long int*)Y;

    return (a > b) - (a < b);
}
void ip(long long int *A,int N)
{
    for(int i=0;i<N;i++)
    {
        scanf("%lld",&A[i]);
    }
}
void display(long long int *A,int N)
{
    for(int i=0;i<N;i++)
    {
        printf("%lld ",A[i]);
    }
}
int main()
{
    int n;
    long long int *A;
    scanf("%d",&n);
    A = (long long int *)malloc(sizeof(long long int)*n);
    ip(A,n);
    qsort(A,n,sizeof(long long int),computeFunction);
    display(A,n);

    return 0;

}