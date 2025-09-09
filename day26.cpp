#include <bits/stdc++.h>
using namespace std;

class Graph {
    int V;
    vector<vector<int>> adj;

public:
    Graph(int V) {
        this->V = V;
        adj.resize(V);
    }

    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u); // undirected
    }

    bool dfs(int node, int parent, vector<bool> &visited) {
        visited[node] = true;

        for (int neigh : adj[node]) {
            if (!visited[neigh]) {
                if (dfs(neigh, node, visited)) return true;
            } else if (neigh != parent) {
                return true; // found cycle
            }
        }
        return false;
    }

    bool containsCycle() {
        vector<bool> visited(V, false);

        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                if (dfs(i, -1, visited)) return true;
            }
        }
        return false;
    }
};

int main() {
    // Test Case 1
    Graph g1(5);
    vector<vector<int>> edges1 = {{0,1},{1,2},{2,3},{3,4},{4,0}};
    for (auto &e : edges1) g1.addEdge(e[0], e[1]);
    cout << (g1.containsCycle() ? "true" : "false") << endl; // true

    // Test Case 2
    Graph g2(3);
    vector<vector<int>> edges2 = {{0,1},{1,2}};
    for (auto &e : edges2) g2.addEdge(e[0], e[1]);
    cout << (g2.containsCycle() ? "true" : "false") << endl; // false

    // Test Case 3
    Graph g3(4);
    vector<vector<int>> edges3 = {{0,1},{1,2},{2,0}};
    for (auto &e : edges3) g3.addEdge(e[0], e[1]);
    cout << (g3.containsCycle() ? "true" : "false") << endl; // true

    // Test Case 4 - parallel edges
    Graph g4(3);
    vector<vector<int>> edges4 = {{0,1},{0,1}};
    for (auto &e : edges4) g4.addEdge(e[0], e[1]);
    cout << (g4.containsCycle() ? "true" : "false") << endl; // true

    return 0;
}
