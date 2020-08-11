//Linear Search: iteration and recursion
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int iteration(int arr[], int n, int val)
{
    int i;
    for (i = 0; i < n; i++)
    {
        if (arr[i] == val)
        {
            return i;
        }
    }
    return -1;
}
int recursion(int arr[], int l, int r, int val)
{
    if (r < l)
        return -1;
    if (arr[l] == val)
        return l;
    if (arr[r] == val)
        return r;
    return recursion(arr, l + 1, r - 1, val);
}
int main(int argc, char const *argv[])
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int val, n = 10, x, i;
    int index1, index2;
    time_t start, end;
    start = time(NULL);

    printf("\n Elements in an array: \n");
    for (i = 0; i < n; i++)
    {
        printf("%d\t", arr[i]);
    }
    do
    {
        printf("\n ++++Linear Search Program++++");
        printf("\n 1.Iteration Search");
        printf("\n 2.Recursion Search");
        printf("\n 3.Exit");
        printf("\n Enter your choice: ");
        scanf("%d", &x);
        switch (x)
        {
        case 1:
            printf("\n Enter the value to search : ");
            scanf("%d", &val);
            index1 = iteration(arr, n, val);
            if (index1 != -1)
                printf("\n Element %d is present at index %d and at position %d", val, index1, index1 + 1);
            else
                printf("\n Element %d is not present", val);
            break;
        case 2:
            printf("\n Enter the value to search : ");
            scanf("%d", &val);
            index2 = recursion(arr, 0, n - 1, val);
            if (index2 != -1)
                printf("\n Element %d is present at index %d and at position %d", val, index2, index2 + 1);
            else
                printf("\n Element %d is not present", val);
            break;
        case 3:
            exit(0);
            break;
        }
        end = time(NULL);
        printf("\n Time taken by the program is %.3f seconds \n", difftime(end, start));
    } while (1);
    return 0;
}
