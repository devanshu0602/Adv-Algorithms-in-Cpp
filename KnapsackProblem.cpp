#include <iostream>
using namespace std;

void inputSet(int n, double set[])
{
    for (int i = 0; i < n; i++)
    {
        cin >> set[i];
    }
}

void Sort(int n, double density[], double profit[], double weight[])
{
    double checker;
    for (int q = 1; q < n; q++)
    {
        checker = density[q];
        int r = q - 1;

        while (r >= 0 && density[r] <= checker)
        {
            density[r + 1] = density[r];
            swap(profit[r], profit[r + 1]);
            swap(weight[r], weight[r + 1]);
            r--;
        }
        density[r + 1] = checker;
    }
}

double KnapsackProb(int n, double capacity, double weight[], double profit[])
{
    double quantity[n];
    for (int i = 0; i < n; i++)
    {
        quantity[i] = 0;
    }

    double u = capacity;

    int j;
    for (j = 0; j < n; j++)
    {
        if (weight[j] > u)
        {
            break;
        }
        else
        {
            quantity[j] = 1;
            u = u - weight[j];
        }
    }
    if (j < n)
    {
        quantity[j] = u / weight[j];
        u = u - (weight[j] * quantity[j]);
    }

    double maxProfit = 0;
    // Maximum Profit = p1*q1 + p2*q2 + .... + pn*qn
    for (int k = 0; k < n; k++)
    {
        maxProfit = maxProfit + (profit[k] * quantity[k]);
    }

    return maxProfit;
}

int main()
{
    // Input no. of Objects and the capacity
    int noOfObj, capacity;
    cout << ("Enter the no. of Objects -> ");
    cin >> noOfObj;
    cout << ("Enter the capacity -> ");
    cin >> capacity;

    // Input the weight and profit of each object
    double weight[noOfObj], profit[noOfObj];
    cout << ("Enter the weight of each object:") << endl;
    inputSet(noOfObj, weight);
    cout << ("Enter the profit of each object:") << endl;
    inputSet(noOfObj, profit);

    // Calculating density
    double density[noOfObj];
    for (int k = 0; k < noOfObj; k++)
    {
        // density = profit / weight
        density[k] = profit[k] / weight[k];
    }

    // Sorting the density - using INSERTION SORT (Descending order)
    // And rearranging weights and profits
    Sort(noOfObj, density, profit, weight);

    // Knapsack's Problem - Greedy Technique
    double maxProfit;
    maxProfit = KnapsackProb(noOfObj, capacity, weight, profit);

    // Final Answer
    cout << ("\nMaximum Profit = ");
    cout << maxProfit << endl;

    // Footer
    cout << ("\nDevanshu Gupta [21BCE0597]") << endl;
    return 0;
}