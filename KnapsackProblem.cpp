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
    for (int i = 1; i < n; i++)
    {
        checker = density[i];
        int j = i - 1;
        while (j >= 0 && density[j] <= checker)
        {
            density[j + 1] = density[j];
            swap(profit[j], profit[j + 1]);
            swap(weight[j], weight[j + 1]);
            j--;
        }
        density[j + 1] = checker;
    }
}

void calcDensity(int n, double density[], double profit[], double weight[])
{
    for (int i = 0; i < n; i++)
    {
        density[i] = profit[i] / weight[i];
    }
}

double KnapsackProb(int n, int capacity, double profit[], double weight[])
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
    // Input no. of objects and the capacity
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

    // Calculating density (density = profit/weight)
    double density[noOfObj];
    calcDensity(noOfObj, density, profit, weight);

    // Sorting the density - using INSERTION SORT (Descending order)
    // And rearranging weights and profits
    Sort(noOfObj, density, profit, weight);

    // Final Answer
    printf("\nMaximum Profit = %.2lf", KnapsackProb(noOfObj, capacity, profit, weight));

    // Footer
    cout << ("\nDevanshu Gupta [21BCE0597]\n") << endl;
    return 0;
}