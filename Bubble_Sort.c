/*Using just pointer array

Input   ::
Number of test case
dataSetSize(N)
(N)Number of data's

Output  ::
(N)Number of data's in Sorted form(ascending order) .
*/
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<math.h>


void Input(int *arr,int n)
{
    for(int i=0;i<n;i++)
    {
        scanf("%d",(arr+i));/*&*(arr+i) is same as (arr+i),both of them holds the memory location of *(arr+i)*/
    }
}
void swap(int* X, int* Y)
{
    int temp = *X;
    *X = *Y;
    *Y =temp;
}

int Bubble(int *arr,int n)
{
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-i-1;j++)
        {
            if( *(arr+j) > *(arr+j+1))//for descending order *arr+j < *arr+j+1
            {
                swap((arr+j),(arr+j+1));
            }
        }
    }
    
}

void Display(int *arr,int n)
{
    for(int i=0;i<n;i++)
    {
        printf("%d ",*(arr+i));
    }
    printf("\n");
}

int main()
{
    int No_of_test_case;
    scanf("%d\n",&No_of_test_case);
    for(int index=0;index<No_of_test_case;index++)
    {
        int *A,N;
        scanf("%d",&N);
        Input(A,N);
        Bubble(A,N);
        Display(A,N);
    }
    


    return 0;

}