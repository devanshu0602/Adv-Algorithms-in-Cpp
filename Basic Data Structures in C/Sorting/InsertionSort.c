#include <stdio.h>

int main()
{
    float array[100], checker;
    int i, n, j, k, l;
    printf("Devanshu Gupta\n");

    printf("Number of elements:\n");
    scanf("%d", &n);

    printf("Elements:\n");
    for (i = 0; i < n; i++)
    {
        scanf("%f", &array[i]);
    }
    for (j = 1; j < n; j++)
    {
        checker = array[j];
        k = j - 1;
        while (k >= 0 && array[k] > checker)
        {
            array[k + 1] = array[k];
            k = k - 1;
        }
        array[k + 1] = checker;
    }
    for (l = 0; l < n; l++)
    {
        printf("%f ", array[l]);
    }
    return 0;
}