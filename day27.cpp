#include <bits/stdc++.h>
using namespace std;

int shortestPath(int V, vector<vector<int>>& edges, int start, int end) {
    // Build adjacency list
    vector<vector<int>> adj(V);
    for (auto &e : edges) {
        int u = e[0], v = e[1];
        adj[u].push_back(v);
        adj[v].push_back(u); // undirected graph
    }

    // Edge case: start == end
    if (start == end) return 0;

    // BFS
    vector<int> dist(V, -1); // -1 means unvisited
    queue<int> q;
    dist[start] = 0;
    q.push(start);

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        for (int nei : adj[node]) {
            if (dist[nei] == -1) { // not visited
                dist[nei] = dist[node] + 1;
                if (nei == end) return dist[nei]; // found shortest path
                q.push(nei);
            }
        }
    }

    return -1; // no path
}

int main() {
    // Example test cases
    int V = 5;
    vector<vector<int>> edges1 = {{0,1},{0,2},{1,3},{2,3},{3,4}};
    cout << shortestPath(V, edges1, 0, 4) << endl; // Output: 3

    V = 3;
    vector<vector<int>> edges2 = {{0,1},{1,2}};
    cout << shortestPath(V, edges2, 0, 2) << endl; // Output: 2

    V = 4;
    vector<vector<int>> edges3 = {{0,1},{1,2}};
    cout << shortestPath(V, edges3, 2, 3) << endl; // Output: -1

    return 0;
}
