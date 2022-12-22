#include <stdio.h>

int main()
{
    int n, i, j, x, y, temp, z;
    int array[100];

    printf("Number of elements: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &array[i]);
    }

    printf("Given array:\n");
    for (j = 0; j < n; j++)
    {
        printf("%d ", array[j]);
    }

    for (x = 0; x < n - 1; x++)
    {
        for (y = 0; y < n - x - 1; y++)
        {
            if (array[y + 1] < array[y])
            {
                temp = array[y + 1];
                array[y + 1] = array[y];
                array[y] = temp;
            }
        }
    }

    printf("\nSorted array using BUBBLE SORT:\n");
    for (z = 0; z < n; z++)
    {
        printf("%d ", array[z]);
    }

    return 0;
}



// #include <stdio.h>
// #include <string.h>

// int main()
// {
//     int n, i, choice, x, y, z;
//     char names[15][100], tempS[100];
//     char regno[15][9], tempR[9];
//     int marks[15], tempM;

//     printf("Number of students:\n");
//     scanf("%d", &n);

//     printf("Enter name, regno, marks:\n");
//     for (i = 0; i < n; i++)
//     {
//         printf("Name: ");
//         scanf("%s", names[i]);
//         printf("Reg. No.: ");
//         scanf("%s", regno[i]);
//         printf("Marks: ");
//         scanf("%d", &marks[i]);
//     }

//     printf("Sort on basis of (1-Name, 2-RegNo, 3-Marks):\n");
//     scanf("%d", &choice);

//     if (choice == 1)
//     {
//         for (x = 0; x < n; x++)
//         {
//             for (y = x + 1; y < n; y++)
//             {
//                 if (strcmp(names[x], names[y]) > 0)
//                 {
//                     strcpy(tempS, names[x]);
//                     strcpy(names[x], names[y]);
//                     strcpy(names[y], tempS);
//                     strcpy(tempR, regno[x]);
//                     strcpy(regno[x], regno[y]);
//                     strcpy(regno[y], tempR);
//                     tempM = marks[x];
//                     marks[x] = marks[y];
//                     marks[y] = tempM;
//                 }
//             }
//         }
//     }
//     else if (choice == 2)
//     {
//         for (x = 0; x < n; x++)
//         {
//             for (y = x + 1; y < n; y++)
//             {
//                 if (strcmp(regno[x], regno[y]) > 0)
//                 {
//                     strcpy(tempR, regno[x]);
//                     strcpy(regno[x], regno[y]);
//                     strcpy(regno[y], tempR);
//                     strcpy(tempS, names[x]);
//                     strcpy(names[x], names[y]);
//                     strcpy(names[y], tempS);
//                     tempM = marks[x];
//                     marks[x] = marks[y];
//                     marks[y] = tempM;
//                 }
//             }
//         }
//     }
//     else if (choice == 3)
//     {
//         for (x = 0; x < n; x++)
//         {
//             for (y = x + 1; y < n; y++)
//             {
//                 if (marks[x] < marks[y])
//                 {
//                     tempM = marks[x];
//                     marks[x] = marks[y];
//                     marks[y] = tempM;
//                     strcpy(tempR, regno[x]);
//                     strcpy(regno[x], regno[y]);
//                     strcpy(regno[y], tempR);
//                     strcpy(tempS, names[x]);
//                     strcpy(names[x], names[y]);
//                     strcpy(names[y], tempS);
//                 }
//             }
//         }
//     }

//     printf("Sorted list:\n");
//     for (z = 0; z < n; z++)
//     {
//         printf("%s , %s , %d\n", names[z], regno[z], marks[z]);
//     }
//     return 0;
// }