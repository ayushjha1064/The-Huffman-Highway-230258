#include <iostream>
#include <vector>
#include <list>

using namespace std;

class Graph {
    int V;
    list<int> *adj;

    void findAllPathsUtil(int u, int v, vector<bool> &visited, vector<int> &path, vector<vector<int>> &allPaths) {
        visited[u] = true;
        path.push_back(u);

        if (u == v) {
            allPaths.push_back(path);
        } else {
            for (int i : adj[u]) {
                if (!visited[i]) {
                    findAllPathsUtil(i, v, visited, path, allPaths);
                }
            }
        }

        path.pop_back();
        visited[u] = false;
    }

public:
    Graph(int V);
    void addEdge(int u, int v);
    void findAllPaths(int u, int v);
};

Graph::Graph(int V) {
    this->V = V;
    adj = new list<int>[V];
}

void Graph::addEdge(int u, int v) {
    adj[u].push_back(v);
}

void Graph::findAllPaths(int u, int v) {
    vector<bool> visited(V, false);
    vector<int> path;
    vector<vector<int>> allPaths;

    findAllPathsUtil(u, v, visited, path, allPaths);

    for (const auto &p : allPaths) {
        for (int vertex : p) {
            cout << vertex << " ";
        }
        cout << endl;
    }
}

int main() {
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(0, 3);
    g.addEdge(2, 0);
    g.addEdge(2, 1);
    g.addEdge(1, 3);

    int u = 2, v = 3;
    cout << "Following are all different paths from " << u << " to " << v << ":\n";
    g.findAllPaths(u, v);

    return 0;
}
