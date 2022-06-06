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

void swap(int *a,int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}
int Quick(int *arr,int l,int h)
{
    int pivot = arr[h];
    int i = l -1;
    for(int j = l;j<h;j++)
    {
        if(arr[j]<=pivot)
        {
            i++;
            swap(&arr[i],&arr[j]);
        }
    }
    swap(&arr[i+1],&arr[h]);

    return i+1;


    
}
void Quick_Sort(int *arr,int low,int high)
{
    
    
    if(low < high)
    {
        int pivot_index = Quick(arr,low,high);
        
        Quick_Sort(arr,low,pivot_index-1);
        Quick_Sort(arr,pivot_index+1,high);
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
        Quick_Sort(A,0,N-1);
        Display(A,N);
    }
    


    return 0;

}
