#include <iostream>
#define INFINITE 999999
using namespace std;

int **createMatrix(int verticesCount)
{
    int **graph = new int *[verticesCount];
    for (int i = 0; i < verticesCount; i++)
    {
        graph[i] = new int[verticesCount];
    }

    // Initializing all edges as 0
    for (int j = 0; j < verticesCount; j++)
    {
        for (int k = 0; k < verticesCount; k++)
        {
            graph[j][k] = 0;
        }
    }

    return graph;
}

void initializeGraph(int **graph)
{
    graph[0][1] = 12;
    graph[0][2] = 3;
    graph[0][3] = 20;
    graph[1][4] = 6;
    graph[1][6] = 5;
    graph[2][4] = 4;
    graph[2][5] = 4;
    graph[3][5] = 5;
    graph[3][8] = 10;
    graph[4][6] = 3;
    graph[4][7] = 3;
    graph[5][7] = 5;
    graph[5][8] = 3;
    graph[6][9] = 13;
    graph[7][9] = 10;
    graph[8][9] = 12;
}

void printGraph(int **graph, int verticesCount)
{
    for (int i = 0; i < verticesCount; i++)
    {
        for (int j = 0; j < verticesCount; j++)
        {
            cout << graph[i][j] << " ";
        }
        cout << endl;
    }
}

int augmentedPath(int fromVertex, int *vertexVisited, int **flowMatrix, int **graph, int verticesCount)
{
    // Mark vertex as visited (visited = 1)
    vertexVisited[fromVertex] = 1;

    // Check if sink vertex is reached
    if (fromVertex == verticesCount - 1)
    {
        return 1; // => augmented path exists
    }

    // Traversing the graph (DFS)
    for (int toVertex = verticesCount - 1; toVertex >= 0; toVertex--)
    {
        if ((graph[fromVertex][toVertex] != 0) && (vertexVisited[toVertex] == 0))
        {
            flowMatrix[fromVertex][toVertex] = 1;

            if (augmentedPath(toVertex, vertexVisited, flowMatrix, graph, verticesCount))
            {
                return 1;
            }

            flowMatrix[fromVertex][toVertex] = 0;
        }
    }
    vertexVisited[fromVertex] = 0;

    return 0;
}

void selectedAugPath(int **flowMatrix, int verticesCount)
{
    cout << "Augmented Path: ";
    for (int i = 0; i < verticesCount; i++)
    {
        for (int j = 0; j < verticesCount; j++)
        {
            if (flowMatrix[i][j] == 1)
            {
                cout << char(i + 65) << " -> ";
                break;
            }
        }
    }
    cout << char((verticesCount - 1) + 65) << endl;
}

int flowThroughPath(int **flowMatrix, int **graph, int verticesCount)
{
    int flow = INFINITE;

    for (int fromVertex = 0; fromVertex < verticesCount; fromVertex++)
    {
        for (int toVertex = 0; toVertex < verticesCount; toVertex++)
        {
            if (flowMatrix[fromVertex][toVertex] == 1)
            {
                flow = (flow < graph[fromVertex][toVertex]) ? flow : graph[fromVertex][toVertex];
            }
        }
    }

    return flow;
}

void updateGraphFlow(int flow, int **graph, int **flowMatrix, int verticesCount)
{
    for (int fromVertex = 0; fromVertex < verticesCount; fromVertex++)
    {
        for (int toVertex = 0; toVertex < verticesCount; toVertex++)
        {
            if (flowMatrix[fromVertex][toVertex] == 1)
            {
                graph[fromVertex][toVertex] = graph[fromVertex][toVertex] - flow;
                graph[toVertex][fromVertex] = graph[fromVertex][toVertex] + flow;
            }
        }
    }
}

void FordFulkerson(int verticesCount)
{
    // Creating the graph matrix
    int **graph = createMatrix(verticesCount);

    // Adding weights of edges -> Weight matrix
    initializeGraph(graph);

    // Printing the weight matrix
    cout << "\nWeight matrix of graph:" << endl;
    printGraph(graph, verticesCount);

    cout << endl;

    // Creating the flow matrix
    int **flowMatrix = createMatrix(verticesCount);

    // Array to keep track of visited vertices
    int *vertexVisited = new int[verticesCount];
    for (int i = 0; i < verticesCount; i++)
    {
        vertexVisited[i] = 0;
    }

    // Initializing the flow and maximum flow
    int flow = 0, maxFlow = 0;

    // Finding augmented paths
    while (augmentedPath(0, vertexVisited, flowMatrix, graph, verticesCount))
    {
        selectedAugPath(flowMatrix, verticesCount);
        flow = flowThroughPath(flowMatrix, graph, verticesCount);
        cout << "Flow through Augmented path = " << flow << endl;

        cout << endl;

        maxFlow = maxFlow + flow;

        updateGraphFlow(flow, graph, flowMatrix, verticesCount);

        // Resetting values of flowMatrix and vertexVisited arrays
        for (int fromVertex = 0; fromVertex < verticesCount; fromVertex++)
        {
            vertexVisited[fromVertex] = 0;

            for (int toVertex = 0; toVertex < verticesCount; toVertex++)
            {
                flowMatrix[fromVertex][toVertex] = 0;
            }
        }
    }

    // Finding Maximum flow
    cout << "Adding flows of all Augemented paths, gives the maximum flow." << endl;
    cout << "Maximum Flow = " << maxFlow << endl;
}

int main()
{
    int verticesCount = 10;

    cout << "Number of Vertices = " << verticesCount << endl;

    FordFulkerson(verticesCount);

    cout << "\nDevanshu Gupta 21BCE0597" << endl;
    return 0;
}