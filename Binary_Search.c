/*Using just pointer array

Input format ::
Number of test case
dataStreamSize(N)
(N)Number of data's
TargetElement

Output format ::
TargetElement found at __ position of data stream .
TargetElement not found .
*/
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <math.h>

void Input(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &*(arr + i)); /*&*(arr+i) is same as (arr+i),both of them holds the memory location of *(arr+i)*/
    }
}

int Binary(int *arr, int l, int n, int X) // X is the target element in the data stream .
{

    if (n >= 1) // this case holds the condition where datastream is empty or targetelement is not found .
    {
        int mid = (l + (n - 1)) / 2;
        if (arr[mid] == X)
            return mid;

        if (arr[mid] > X)
            return Binary(arr, l, mid - 1, X);

        return Binary(arr, mid + 1, n, X);
    }

    return -1;
}

void Display(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", *(arr + i));
    }
    printf("\n");
}

int main()
{
    int No_of_test_case;
    scanf("%d\n", &No_of_test_case);
    for (int index = 0; index < No_of_test_case; index++)
    {
        int *A, N, Target;
        scanf("%d", &N);
        Input(A, N);
        scanf("%d", &Target);
        int Target_index = Binary(A, 0, N - 1, Target);
        (Target_index == -1) ? printf("%d not found .\n", Target) : printf("%d found at %d position of data stream .\n", Target, Target_index+1);

        // Display(A,N);
    }

    return 0;
}