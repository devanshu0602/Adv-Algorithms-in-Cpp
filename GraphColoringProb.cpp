#include <iostream>
using namespace std;

static int v; // v = no. of vertices
static int m; // m = chromatic number
static int count = 0;
bool checker = false;
int graph[20][20];
int X[20];

void nextValue(int k)
{
    int j;
    while (1)
    {
        X[k] = (X[k] + 1) % (m + 1); // next highest node

        if (X[k] == 0)
        {
            // colors exhausted
            return;
        }

        for (j = 1; j <= v; j++)
        {
            if ((graph[k][j] == 1) && (X[k] == X[j]))
            {
                break; // due to adjacency with same color
            }
        }

        // check if previous loop was completed or broken
        if (j == (v + 1))
        {
            return;
        }
    }
}

void graphColoring(int k)
{
    while (1)
    {
        nextValue(k);
        if (X[k] == 0)
        {
            return;
        }

        if (k == noOfVertices)
        {
            checker = true;
            count++; // increment min. colors required
        }
        else
        {
            graphColoring(k + 1);
        }
    }
}

int main()
{
    // Input the no. of Vertices
    cout << ("\nEnter no. of Vertices -> ");
    cin >> v;

    // Adjacency Matrix
    cout << ("\nEnter the Adjacency matrix.") << endl;
    for (int i = 1; i <= v; i++)
    {
        for (int j = 1; j <= v; j++)
        {
            cin >> graph[i][j];
        }
    }

    // Check possibilities of coloring
    for (m = 1; m <= v; m++)
    {
        if (checker)
        {
            break;
        }
        graphColoring(1);
    }

    // Print chromatic number
    printf("\nChromatic number = %d", m - 1);

    // Footer
    cout << ("\n\nDevanshu Gupta [21BCE0597]\n") << endl;
    return 0;
}