#include <iostream>
using namespace std;

static int noOfVertices, m;
static int count = 0, checker = 0;
int graph[10][10];
int X[10];

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

        for (j = 1; j <= noOfVertices; j++)
        {
            if (graph[k][j] == 1 && X[k] == X[j])
            {
                break;
                // due to adjacency with same color
            }
        }

        // check if previous loop was completed or broken
        if (j == (noOfVertices + 1))
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
            checker = 1;

            // increment min. colors required
            count++;
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
    cin >> noOfVertices;

    // Input the Edges
    cout << ("\nEnter 1 if edge is present. Else enter 0.") << endl;
    for (int i = 1; i <= noOfVertices; i++)
    {
        for (int j = 1; j <= noOfVertices; j++)
        {
            // Avoiding self loops
            if (i == j)
            {
                graph[i][j] = 0;
            }
            else
            {
                printf("Between V[%d] & V[%d]: ", i, j);
                cin >> graph[i][j];
            }
        }
    }

    // Check possibilities of coloring
    for (m = 1; m <= noOfVertices; m++)
    {
        if (checker == 1)
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