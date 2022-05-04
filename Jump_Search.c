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
        scanf("%d", (arr + i)); /*&*(arr+i) is same as (arr+i),both of them holds the memory location of *(arr+i)*/
    }
}

int Jump(int *arr, int l, int h, int n, int X) // X is the target element in the data stream .
{
    int J = sqrt(n);
    while (arr[l] < X)
    {
        if ((arr[J] > X) || (J >= n))
        {
            break;
        }
        else
        {
            l = J;
            J = J + sqrt(n);
        }
    }
    while (arr[l] < X)
    {
        l++;
    }
    if (arr[l] == X)
    {
        return l + 1;
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
        int Target_index = Jump(A, 0, N - 1, N, Target);
        (Target_index == -1) ? printf("%d not found .\n", Target) : printf("%d found at %d position of data stream .\n", Target, Target_index);
        // Display(A,N);
    }

    return 0;
}