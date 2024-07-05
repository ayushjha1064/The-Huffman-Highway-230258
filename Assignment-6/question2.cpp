#include <iostream>
#include <vector>

using namespace std;

class Graph {
    int V;
    vector<vector<int>> adj;

    bool isHamiltonianPathUtil(int v, vector<bool> &visited, vector<int> &path, int pathCount) {
        visited[v] = true;
        path.push_back(v);

        if (pathCount == V) {
            visited[v] = false;
            path.pop_back();
            return true;
        }

        for (int i = 0; i < V; i++) {
            if (adj[v][i] && !visited[i]) {
                if (isHamiltonianPathUtil(i, visited, path, pathCount + 1)) {
                    return true;
                }
            }
        }

        visited[v] = false;
        path.pop_back();
        return false;
    }

    bool isHamiltonianCircuitUtil(int v, vector<bool> &visited, vector<int> &path, int pathCount, int start) {
        visited[v] = true;
        path.push_back(v);

        if (pathCount == V) {
            if (adj[v][start]) {
                visited[v] = false;
                path.pop_back();
                return true;
            }
        } else {
            for (int i = 0; i < V; i++) {
                if (adj[v][i] && !visited[i]) {
                    if (isHamiltonianCircuitUtil(i, visited, path, pathCount + 1, start)) {
                        return true;
                    }
                }
            }
        }

        visited[v] = false;
        path.pop_back();
        return false;
    }

public:
    Graph(int V);
    void addEdge(int u, int v);
    void addEdgeFromMatrix(const vector<vector<int>>& matrix);
    bool hasHamiltonianPath();
    bool hasHamiltonianCircuit();
};

Graph::Graph(int V) {
    this->V = V;
    adj.resize(V, vector<int>(V, 0));
}

void Graph::addEdge(int u, int v) {
    adj[u][v] = 1;
    adj[v][u] = 1; // This is an undirected graph.
}

void Graph::addEdgeFromMatrix(const vector<vector<int>>& matrix) {
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            adj[i][j] = matrix[i][j];
        }
    }
}

bool Graph::hasHamiltonianPath() {
    vector<bool> visited(V, false);
    vector<int> path;

    for (int i = 0; i < V; i++) {
        if (isHamiltonianPathUtil(i, visited, path, 1)) {
            return true;
        }
    }
    return false;
}

bool Graph::hasHamiltonianCircuit() {
    vector<bool> visited(V, false);
    vector<int> path;

    for (int i = 0; i < V; i++) {
        if (isHamiltonianCircuitUtil(i, visited, path, 1, i)) {
            return true;
        }
    }
    return false;
}

int main() {
    int V = 5;
    vector<vector<int>> matrix = {
        {0, 1, 1, 1, 1},
        {1, 0, 1, 1, 1},
        {1, 1, 0, 1, 1},
        {1, 1, 1, 0, 1},
        {1, 1, 1, 1, 0}
    };

    Graph g(V);
    g.addEdgeFromMatrix(matrix);

    cout << "The graph has a Hamiltonian Path: " << (g.hasHamiltonianPath() ? "Yes" : "No") << endl;
    cout << "The graph has a Hamiltonian Circuit: " << (g.hasHamiltonianCircuit() ? "Yes" : "No") << endl;

    return 0;
}
