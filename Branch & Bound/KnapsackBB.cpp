#include <iostream>
using namespace std;

int itemSelection[10];

void inputArray(int n, double array[])
{
    for (int i = 0; i < n; i++)
    {
        cin >> array[i];
    }
}
void printArray(int n, double Profit[], double Weight[], double Density[])
{
    for (int i = 0; i < n; i++)
    {
        printf("Item %d: {W = %.2f, P = %.2f, D = %.2f}\n", i + 1, Weight[i], Profit[i], Density[i]);
    }
}

void calcDensity(int n, double p[], double w[], double d[])
{
    for (int i = 0; i < n; i++)
    {
        d[i] = p[i] / w[i];
    }
}
void descendSort(int n, double Profit[], double Weight[], double Density[])
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (Density[j + 1] > Density[j])
            {
                double temp = Density[j + 1];
                Density[j + 1] = Density[j];
                Density[j] = temp;

                swap(Profit[j], Profit[j + 1]);
                swap(Weight[j], Weight[j + 1]);
            }
        }
    }
}

double calcLowerBound(int n, double currentProfit, double currentWeight, int item, double capacity, double Weight[], double Profit[])
{
    double cp = currentProfit;
    double cw = currentWeight;

    for (int i = item; i < n; i++)
    {
        cw = cw + Weight[i];

        if (cw <= capacity)
        {
            cp = cp - Profit[i];
        }
        else
        {
            // cp = cp - (1 - (cw - capacity) / weight) * profit
            cp = cp - (1 - (cw - capacity) / Weight[i]) * Profit[i];
        }
    }

    return cp;
}
double calcUpperBound(int n, double currentProfit, double currentWeight, int item, double capacity, double Weight[], double Profit[])
{
    double cp = currentProfit;
    double cw = currentWeight;

    for (int i = item; i < n; i++)
    {
        if ((cw + Weight[i]) <= capacity)
        {
            cw = cw + Weight[i];
            cp = cp - Profit[i];
        }
    }

    return cp; // returns profit (-ve)
}

double knapsack(int n, double currentProfit, double currentWeight, int item, double capacity, double Weight[], double Profit[])
{
    while (item < n)
    {
        printf("Item %d {W = %.2f, P = %.2f}:\n", item + 1, Weight[item], Profit[item]);

        double LB_withItem = calcLowerBound(n, currentProfit - Profit[item], currentWeight + Weight[item], item + 1, capacity, Weight, Profit);
        cout << "LB with item " << item + 1 << " = " << LB_withItem << endl;

        double UB_withItem = calcUpperBound(n, currentProfit - Profit[item], currentWeight + Weight[item], item + 1, capacity, Weight, Profit);
        cout << "UB with item " << item + 1 << " = " << UB_withItem << endl;

        double LB_withoutItem = calcLowerBound(n, currentProfit, currentWeight, item + 1, capacity, Weight, Profit);
        cout << "LB without item " << item + 1 << " = " << LB_withoutItem << endl;

        double UB_withoutItem = calcUpperBound(n, currentProfit, currentWeight, item + 1, capacity, Weight, Profit);
        cout << "UB without item " << item + 1 << " = " << UB_withoutItem << endl;

        if (currentWeight + Weight[item] <= capacity)
        {
            if ((UB_withItem < UB_withoutItem) || (UB_withItem == UB_withoutItem && LB_withItem < LB_withoutItem))
            {
                itemSelection[item] = 1;
                cout << "Item " << item + 1 << " is selected." << endl;
                currentProfit = currentProfit - Profit[item];
                currentWeight = currentWeight + Weight[item];
            }
        }
        else
        {
            cout << "Item " << item + 1 << " is not selected." << endl;
        }

        cout << "Current Knapsack weight = " << currentWeight << endl;
        cout << endl;

        item++;
    }

    return abs(currentProfit);
}

int main()
{
    // ----- Inputs -----
    int numberOfObj;
    cout << "Enter number of Objects: ";
    cin >> numberOfObj;

    int capacity;
    cout << "Enter Capacity of Knapsack: ";
    cin >> capacity;

    double profit[numberOfObj];
    cout << "Enter Profit of each object: ";
    inputArray(numberOfObj, profit);

    double weight[numberOfObj];
    cout << "Enter Weight of each object: ";
    inputArray(numberOfObj, weight);
    // ------------------

    // Initializing the selection of items
    for (int i = 0; i < numberOfObj; i++)
    {
        itemSelection[i] = 0;
    }
    cout << endl;

    // Calculating the densities
    double density[numberOfObj];
    calcDensity(numberOfObj, profit, weight, density);

    cout << ("Given:") << endl;
    printArray(numberOfObj, profit, weight, density);

    // Sorting densities in descending order
    cout << ("Re-arranging gives:") << endl;
    descendSort(numberOfObj, profit, weight, density);
    printArray(numberOfObj, profit, weight, density);

    cout << endl;

    // Knapsack calculations
    cout << ("\nCalculations:\n") << endl;
    double maxProfit = knapsack(numberOfObj, 0, 0, 0, capacity, weight, profit);

    // Printing the array of item selection
    cout << "Selected items are: [ ";
    for (int i = 0; i < numberOfObj; i++)
    {
        cout << itemSelection[i] << " ";
    }
    cout << "]" << endl;

    // Printing Maximum Profit
    cout << "Maximum Profit = " << maxProfit << endl;

    // Footer
    cout << ("\nDevanshu Gupta 21BCE0597\n") << endl;
    return 0;
}