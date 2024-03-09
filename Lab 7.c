#include <stdio.h>

void bubbleSort(int arr[], int n)
{
    int i, j, temp, swaps[n], totalSwaps=0;
    for (i = 0; i < n; i++)
    {
        swaps[i] = 0;
    }
    for (i = 0; i < n-1; i++)
    {
        for (j = 0; j < n-i-1; j++)
        {
            if (arr[j] > arr[j+1])
            {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                swaps[j]++;
                totalSwaps++;
            }
        }
    }
    for (i = 0; i < n; i++)
    {
       printf("%d: %d\n", arr[i], swaps[i]);
    }
    printf("%d\n", totalSwaps);
}

void selectiveSort(int arr[], int n) 
{
    int swaps = 0;
    int swapCount[100] = {0};

    for (int i = 0; i < n-1; i++) 
    {
        int minIndex = i;
        for (int j = i+1; j < n; j++)
        {
            if (arr[j] < arr[minIndex])
            {
                minIndex = j;
            }
        }
        if (minIndex != i) 
        {
            swapCount[arr[i]]++;
            swapCount[arr[minIndex]]++;
            int temp = arr[minIndex];
            arr[minIndex] = arr[i];
            arr[i] = temp;
            swaps++;
        }
    }
    for (int i = 0; i < n; i++)
    {
        printf("%d: %d\n", arr[i], swapCount[arr[i]]);
    }
    printf("%d\n", swaps);
}

int main()
{
    int array1[] = {97, 16, 45, 63, 13, 22, 7, 58, 72};
    int array2[] = {90, 80, 70, 60, 50, 40, 30, 20, 10};
    int n1 = sizeof(array1)/sizeof(array1[0]);
    int n2 = sizeof(array2)/sizeof(array2[0]);
    printf("Array1 bubble sort:\n");
    bubbleSort(array1, n1);
    printf("Array2 bubble sort:\n");
    bubbleSort(array2, n2);

    //had to recreate the arrays to get the sort to work
    int array3[] = {97, 16, 45, 63, 13, 22, 7, 58, 72};
    int array4[] = {90, 80, 70, 60, 50, 40, 30, 20, 10};

    printf("Array1 selective sort:\n");
    selectiveSort(array3, n1);
    printf("Array2 selective sort:\n");
    selectiveSort(array4, n2);
    return 0;
}
