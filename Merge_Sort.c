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

void Merge(int *arr,int l,int m,int h)
{
    int temp[h-l+1];
    int i=l,j=m+1,k=0;
    while((i<=m)&&(j<=h))
    {
        if(arr[i]<arr[j])
        {
            temp[k]=arr[i];
            k++;
            i++;
        }
        else
        {
            temp[k]=arr[j];
            k++;
            j++;
        }
    }
    while(i<=m)
    {
        temp[k]=arr[i];
        k++;
        i++;
    }
    while(j<=h)
    {
        temp[k]=arr[j];
        k++;
        j++;
    }
    for(i=l;i<=h;i++)
    {
        arr[i]=temp[i-l];
    }


    
}
void Merge_Sort(int *arr,int low,int high)
{
    int mid = ( low + high )/2;
    
    if(low < high)
    {
        
        Merge_Sort(arr,low,mid);
        Merge_Sort(arr,mid+1,high);
        Merge(arr,low,mid,high);
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
        Merge_Sort(A,0,N-1);
        Display(A,N);
    }
    


    return 0;

}
