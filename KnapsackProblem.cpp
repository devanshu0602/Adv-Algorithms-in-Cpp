#include <iostream>
using namespace std;

double Knapsack(double capacity, int n, double weight[], double profit[])
{
    int i;
    double quantity[n];
    for (i = 0; i < n; i++)
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
    int k;
    // Maximum Profit = p1*q1 + p2*q2 + .... + pn*qn
    for (k = 0; k < n; k++)
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
    cout << ("Enter the capacity of the sack -> ");
    cin >> capacity;

    // Input the weight and profit of each object
    double weight[noOfObj], profit[noOfObj];
    cout << ("Enter the weight of each object:") << endl;
    for (int i = 0; i < noOfObj; i++)
    {
        cin >> weight[i];
    }
    cout << ("Enter the profit of each object:") << endl;
    for (int j = 0; j < noOfObj; j++)
    {
        cin >> profit[j];
    }

    // Calculating density
    double density[noOfObj];
    for (int k = 0; k < noOfObj; k++)
    {
        // density = profit / weight
        density[k] = profit[k] / weight[k];
    }

    // Sorting the density - using INSERTION SORT (Ascending order)
    // And rearranging weights and profits
    double checkerD, initialP, initialW;
    int r;
    for (int q = 1; q < noOfObj; q++)
    {
        checkerD = density[q];
        initialP = profit[q];
        initialW = weight[q];
        r = q - 1;

        while (r >= 0 && density[r] > checkerD)
        {
            density[r + 1] = density[r];
            weight[r + 1] = weight[r];
            profit[r + 1] = profit[r];
            r = r - 1;
        }

        density[r + 1] = checkerD;
        profit[r + 1] = initialP;
        weight[r + 1] = initialW;
    }
    // Reversing the arrays for the Descending order
    int start = 0;
    int end = noOfObj - 1;
    while (start < end)
    {
        swap(density[start], density[end]);
        swap(profit[start], profit[end]);
        swap(weight[start], weight[end]);
        start++;
        end--;
    }

    // Knapsack Greedy Technique
    double maxProfit;
    maxProfit = Knapsack(capacity, noOfObj, weight, profit);
    // Final Answer
    cout << ("") << endl;
    cout << ("Maximum Profit = ");
    cout << maxProfit << endl;

    // Footer
    cout << ("\nDevanshu Gupta [21BCE0597]") << endl;
    return 0;
}