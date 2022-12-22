#include <stdio.h>

void Merge(int array[], int low, int mid, int high)
{
    int i, j, k, array2[20], index;
    i = low;
    j = mid + 1;
    k = low;

    while (i <= mid && j <= high)
    {
        if (array[i] < array[j])
        {
            array2[k] = array[i];
            i++;
            k++;
        }
        else
        {
            array2[k] = array[j];
            j++;
            k++;
        }
    }
    while (i <= mid)
    {
        array2[k] = array[i];
        i++;
        k++;
    }
    while (j <= high)
    {
        array2[k] = array[j];
        j++;
        k++;
    }

    for (index = low; index <= high; index++)
    {
        array[index] = array2[index];
    }
}

void MergeSort(int array[], int low, int high)
{
    int mid;
    if (low < high)
    {
        mid = (low + high) / 2;
        MergeSort(array, low, mid);      // sorting 1st half
        MergeSort(array, mid + 1, high); // sorting 2nd half
        Merge(array, low, mid, high);    // merging both halves
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

    printf("Enter 10 numbers to sort using MergeSort:\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &array[i]);
    }

    Display(array, n);
    MergeSort(array, 0, n - 1);
    Display(array, n);

    printf("\n");
    printf("Devanshu Gupta 21BCE0597");
    return 0;
}