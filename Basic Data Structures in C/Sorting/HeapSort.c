#include <stdio.h>

void Swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void Heapify(int heap[], int N, int i)
{
    // Find largest among root, left child and right child
    // Initialize largest as root
    int largest = i;

    int left = (2 * i) + 1;
    int right = (2 * i) + 2;

    // If left child is larger than root
    if (left < N && heap[left] > heap[largest])
    {
        largest = left;
    }
    // If right child is larger than largest so far
    if (right < N && heap[right] > heap[largest])
    {
        largest = right;
    }
    // Swap and continue heapifying if root is not largest
    // If largest is not root
    if (largest != i)
    {
        Swap(&heap[i], &heap[largest]);

        // Recursively Heapify the affected
        // sub-tree
        Heapify(heap, N, largest);
    }
}

// Main function to do heap sort
void heapSort(int heap[], int N)
{
    // Build max heap
    for (int i = N / 2 - 1; i >= 0; i--)
    {
        Heapify(heap, N, i);
    }
    // Heap sort
    for (int i = N - 1; i >= 0; i--)
    {
        Swap(&heap[0], &heap[i]);

        // Heapify root element to get highest element at
        // root again
        Heapify(heap, i, 0);
    }
}

// A utility function to print array of size n
void Display(int heap[], int N)
{
    for (int i = 0; i < N; i++)
    {
        printf("%d ", heap[i]);
    }
    printf("\n");
}

int main()
{
    int heap[] = {12, 11, 13, 5, 6, 7};
    int N = sizeof(heap) / sizeof(heap[0]);
    int i;

    printf("The given array is:\n");
    for (i = 0; i < N; i++)
    {
        printf("%d ", heap[i]);
    }
    printf("\n");

    heapSort(heap, N);
    printf("Sorted array is:\n");
    Display(heap, N);

    printf("\nDevanshu Gupta 21BCE0597\n");
    return 0;
}