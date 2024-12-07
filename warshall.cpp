#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int main()
{
    int V;
    cout << "Enter the total number of nodes: ";
    cin >> V;

    vector<vector<int>> graph(V, vector<int>(V));
    cout << "Enter the adjacency matrix values (use a large value like 999 for INF):" << endl;
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            cin >> graph[i][j];
            if (graph[i][j] == 999)
                graph[i][j] = INT_MAX;
        }
    }

    for (int k = 0; k < V; k++)
    {
        for (int i = 0; i < V; i++)
        {
            for (int j = 0; j < V; j++)
            {
                if (graph[i][k] != INT_MAX && graph[k][j] != INT_MAX)
                    graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
            }
        }
    }

    cout << "\nShortest path matrix after Floyd-Warshall:" << endl;
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            if (graph[i][j] == INT_MAX)
                cout << "INF ";
            else
                cout << graph[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
