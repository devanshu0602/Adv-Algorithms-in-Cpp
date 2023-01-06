#include <iostream>
#include <cstdlib>
using namespace std;

// Solutions array
int X[20];
// Solutions counter
int solnCounter = 0;

void printArray(int *array, int n)
{
    if (array[1] == 0)
    {
        cout << ("There are 0 possible solutions.") << endl;
    }

    cout << ("| ");
    for (int i = 1; i <= n; i++)
    {
        cout << array[i] << (" | ");
    }
    solnCounter++;
}

bool Place(int k, int i)
{
    for (int j = 1; j <= k - 1; j++)
    {
        if ((X[j] == i) || (abs(X[j] - i) == abs(j - k)))
        {
            return false;
        }
    }
    return true;
}

void nQueens(int k, int n)
{
    for (int i = 1; i <= n; i++)
    {
        if (Place(k, i))
        {
            X[k] = i;
            if (k == n)
            {
                printArray(X, n);
                cout << endl;
            }
            else
            {
                nQueens(k + 1, n);
            }
        }
    }
}

int main()
{
    // Input
    int N;
    cout << ("\nEnter number of Queens -> ");
    cin >> N;

    // All possible solutions
    cout << ("\nSolutions:") << endl;
    nQueens(1, N); // use of Backtracking
    printf("\nThere are %d possible solutions.", solnCounter);

    // Footer
    cout << ("\n\nDevanshu Gupta [21BCE0597]\n") << endl;
    return 0;
}