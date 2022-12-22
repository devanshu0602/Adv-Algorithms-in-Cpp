#include <stdio.h>

int Partition(int array[], int low, int high)
{
    int pivot = array[low], i = low + 1, j = high, temp;

    do
    {
        while (array[i] <= pivot)
        {
            i++;
        }
        while (array[j] > pivot)
        {
            j--;
        }
        if (i < j)
        {
            /* Swapping */
            temp = array[i];
            array[i] = array[j];
            array[j] = temp;
        }
    } while (i < j);

    temp = array[low];
    array[low] = array[j];
    array[j] = temp;
    return j;
}

void QuickSort(int array[], int low, int high)
{
    int pivot; /* index of pivot after partitioning */
    if (low < high)
    {
        pivot = Partition(array, low, high);
        QuickSort(array, low, pivot - 1);  /* sorting 1st half */
        QuickSort(array, pivot + 1, high); /* sorting 2nd half */
    }
}

void Display(int *array, int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
}

int main()
{
    int array[10], n = 10, i;

    printf("Enter 10 numbers to sort using QuickSort:\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &array[i]);
    }

    Display(array, n);
    QuickSort(array, 0, n - 1);
    Display(array, n);

    printf("\n");
    printf("Devanshu Gupta 21BCE0597");
    return 0;
}