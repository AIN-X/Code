#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int main()
{
    int n, min_cost = 0;
    cout << "Number of Nodes: ";
    cin >> n;

    vector<vector<int>> cost(n, vector<int>(n));
    cout << "Cost matrix (0 for no edge):\n";
    for (auto &row : cost)
        for (int &c : row)
            cin >> c, c = c ? c : INT_MAX;

    vector<bool> vis(n, false);
    vis[0] = true;

    cout << "Edges in MST:\n";
    for (int k = 1; k < n; k++)
    {
        int u = -1, v = -1, min_edge = INT_MAX;
        for (int i = 0; i < n; i++)
        {
            if (vis[i])
            {
                for (int j = 0; j < n; j++)
                {
                    if (!vis[j] && cost[i][j] < min_edge)
                    {
                        min_edge = cost[i][j];
                        u = i;
                        v = j;
                    }
                }
            }
        }

        if (min_edge == INT_MAX)
        {
            cout << "The graph is disconnected. MST cannot be formed.\n";
            return 0;
        }

        vis[v] = true;
        min_cost += min_edge;
        cout << "(" << u + 1 << ", " << v + 1 << ") cost=" << min_edge << "\n";
    }

    cout << "Total MST cost: " << min_cost << endl;
    return 0;
}