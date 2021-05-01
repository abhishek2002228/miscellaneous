#include <stdio.h>

void QuickSort(int arr[], int start, int end);
int Partition(int arr[], int start, int end);
void swap(int arr[], int i, int j);

int main(void)
{
    int arr[] = {7, 2, 1, 6, 8, 5, 3, 4};
    int len = sizeof(arr) / sizeof(arr[0]);
    int i;
    QuickSort(arr, 0, len - 1);

    for (i = 0; i < len; i++)
    {
        printf("%d", arr[i]);
    }
    printf("\n");
    return 0;
}

void QuickSort(int arr[], int start, int end)
{
    int pIndex;
    if (start >= end)
    {
        return;
    }
    pIndex = Partition(arr, start, end);
    QuickSort(arr, start, pIndex - 1);
    QuickSort(arr, pIndex + 1, end);

    return;
}

int Partition(int arr[], int start, int end)
{
    int pivot = arr[end];
    int pIndex = start;
    int i;
    for (i = start; i < end; i++)
    {
        if (arr[i] <= pivot)
        {
            swap(arr, i, pIndex);
            pIndex++;
        }
    }

    swap(arr, pIndex, end);
    return pIndex;
}

void swap(int arr[], int i, int j)
{
    int temp;
    temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;

    return;
}