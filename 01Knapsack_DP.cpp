#include <iostream>
using namespace std;

int numOfObj = 7;
int capacity = 15;
int weight[] = {2, 3, 5, 7, 1, 4, 1};
int profit[] = {10, 5, 15, 7, 6, 18, 3};
int selectedItems[] = {0, 0, 0, 0, 0, 0, 0};
int knapsackTableDP[8][16];

void printSelectedItems()
{
    int i;

    cout << ("{ ");
    for (i = 0; i < numOfObj; i++)
    {
        cout << selectedItems[i] << (" ");
    }

    cout << ("} -> ");

    for (i = 0; i < numOfObj; i++)
    {
        if (selectedItems[i] == 1)
        {
            cout << ("| ") << ("Obj ") << i + 1 << (" ");
        }
    }
    cout << ("|") << endl;
}

void ascendingSort()
{
    int checker;

    for (int i = 1; i < numOfObj; i++)
    {
        checker = weight[i];
        int j = i - 1;
        
        while ((j >= 0) && (weight[j] >= checker))
        {
            weight[j + 1] = weight[j];
            swap(profit[j], profit[j + 1]);
            j--;
        }
        
        weight[j + 1] = checker;
    }
}

int knapsackDP(int n, int capacity, int weight[], int profit[])
{
    // Building the table in bottom-up manner
    for (int i = 0; i <= n; i++)
    {
        for (int w = 0; w <= capacity; w++)
        {
            if (i == 0 || w == 0)
            {
                knapsackTableDP[i][w] = 0;
            }
            else if (weight[i - 1] <= w)
            {
                knapsackTableDP[i][w] = max(profit[i - 1] + knapsackTableDP[i - 1][w - weight[i - 1]], knapsackTableDP[i - 1][w]);
            }
            else
            {
                knapsackTableDP[i][w] = knapsackTableDP[i - 1][w];
            }
        }
    }

    // Finding the selected items
    int row = n, col = capacity;

    while (row != 0)
    {
        if (knapsackTableDP[row][col] != knapsackTableDP[row - 1][col])
        {
            selectedItems[row - 1] = 1;
            col = col - weight[row - 1];
        }
        row--;
    }

    // Maximum profit
    return knapsackTableDP[n][capacity];
}

int main()
{
    int index;

    // Problem description
    cout << ("\nGiven:") << endl;
    for (index = 0; index < numOfObj; index++)
    {
        printf("Obj %d -> {Weight = %d : Profit = %d}\n", index + 1, weight[index], profit[index]);
    }
    cout << endl;

    // Sort Weight in asscending order
    ascendingSort();
    
    cout << ("Re-arranged Values:") << endl;
    for (index = 0; index < numOfObj; index++)
    {
        printf("Obj %d -> {Weight = %d : Profit = %d}\n", index + 1, weight[index], profit[index]);
    }
    cout << endl;

    // Maximum profit
    cout << ("Maximum Profit = ");
    cout << knapsackDP(numOfObj, capacity, weight, profit) << endl;

    // List of selected items
    cout << ("\nThe selected items are: ") << endl;
    printSelectedItems();

    // Footer
    cout << ("\nDevanshu Gupta [21BCE0597]\n") << endl;
    return 0;
}