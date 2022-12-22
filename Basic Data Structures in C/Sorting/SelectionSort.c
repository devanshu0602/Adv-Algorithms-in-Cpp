#include <stdio.h>

int main()
{
    int n, d, i, j, smallest, k, z;
    char letters[] = {'c', 'b', 'e', 'y', 'a', 'x'};
    char temp;
    n = sizeof(letters) / sizeof(letters[0]);
    printf("Devanshu Gupta\n");
    printf("\n");

    printf("Given array:\n");
    for (d = 0; d < n; d++)
    {
        printf("%c ", letters[d]);
    }
    printf("\n");

    printf("Sorted array:\n");
    for (j = 0; j < n - 1; j++)
    {
        smallest = j;
        for (k = j + 1; k < n; k++)
        {
            if (letters[smallest] > letters[k])
            {
                smallest = k;
            }
        }
        temp = letters[j];
        letters[j] = letters[smallest];
        letters[smallest] = temp;
    }

    for (z = 0; z < n; z++)
    {
        printf("%c ", letters[z]);
    }

    return 0;
}
