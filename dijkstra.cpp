#include <iostream>
#include <queue>
#include <climits>
using namespace std;

const int MAX = 1000;
pair<int, int> graph[MAX][MAX];
int edges[MAX];

void dijkstra(int V, int source) {
    int dist[MAX], visited[MAX] = {0};
    for (int i = 0; i < V; i++) dist[i] = INT_MAX;
    dist[source] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> minHeap;
    minHeap.push({0, source});

    while (!minHeap.empty()) {
        int u = minHeap.top().second;
        minHeap.pop();
        if (visited[u]) continue;
        visited[u] = 1;

        for (int i = 0; i < edges[u]; i++) {
            int v = graph[u][i].first, w = graph[u][i].second;
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                minHeap.push({dist[v], v});
            }
        }
    }

    for (int i = 0; i < V; i++)
        cout << "Vertex " << i << ": " << (dist[i] == INT_MAX ? "INF" : to_string(dist[i])) << endl;
}

int main() {
    int V, E, u, v, w, source;
    cin >> V >> E;
    for (int i = 0; i < V; i++) edges[i] = 0;
    while (E--) {
        cin >> u >> v >> w;
        graph[u][edges[u]++] = {v, w};
        graph[v][edges[v]++] = {u, w};
    }
    cin >> source;
    dijkstra(V, source);
    return 0;
}
