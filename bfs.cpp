#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main()
{
    int n;
    cout << "Enter the number of nodes: ";
    cin >> n;

    vector<vector<int>> adj(n, vector<int>(n));
    cout << "Enter the adjacency matrix:\n";
    for (auto &row : adj)
        for (int &cell : row)
            cin >> cell;

    vector<bool> visited(n, false);
    queue<int> q;
    q.push(0);
    visited[0] = true;

    cout << "The result of BFS is: ";
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        cout << (char)(node + 'A') << " ";
        for (int i = 0; i < n; ++i)
        {
            if (adj[node][i] && !visited[i])
            {
                visited[i] = true;
                q.push(i);
            }
        }
    }
    cout << endl;
    return 0;
}
