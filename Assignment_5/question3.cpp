#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

const int MAXN = 1000;

vector<int> tree[MAXN];
int nodeValues[MAXN];
int depth[MAXN];
int parent[MAXN][20];
int maxVal[MAXN][20];
int minVal[MAXN][20];
int sumVal[MAXN][20];

void dfs(int node, int par, int dep) {
    depth[node] = dep;
    parent[node][0] = par;
    maxVal[node][0] = nodeValues[node];
    minVal[node][0] = nodeValues[node];
    sumVal[node][0] = nodeValues[node];

    for (int i = 1; i < 20; i++) {
        if (parent[node][i - 1] != -1) {
            parent[node][i] = parent[parent[node][i - 1]][i - 1];
            maxVal[node][i] = max(maxVal[node][i - 1], maxVal[parent[node][i - 1]][i - 1]);
            minVal[node][i] = min(minVal[node][i - 1], minVal[parent[node][i - 1]][i - 1]);
            sumVal[node][i] = sumVal[node][i - 1] + sumVal[parent[node][i - 1]][i - 1];
        } else {
            parent[node][i] = -1;
        }
    }

    for (int child : tree[node]) {
        if (child != par) {
            dfs(child, node, dep + 1);
        }
    }
}

void preprocess(int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 20; j++) {
            parent[i][j] = -1;
            maxVal[i][j] = INT_MIN;
            minVal[i][j] = INT_MAX;
            sumVal[i][j] = 0;
        }
    }
    dfs(0, -1, 0);
}

int lca(int u, int v, int &sumPath, int &maxPath, int &minPath) {
    if (depth[u] < depth[v]) {
        swap(u, v);
    }

    sumPath = 0;
    maxPath = INT_MIN;
    minPath = INT_MAX;

    int diff = depth[u] - depth[v];

    for (int i = 19; i >= 0; i--) {
        if ((1 << i) <= diff) {
            sumPath += sumVal[u][i];
            maxPath = max(maxPath, maxVal[u][i]);
            minPath = min(minPath, minVal[u][i]);
            u = parent[u][i];
        }
    }

    if (u == v) {
        return u;
    }

    for (int i = 19; i >= 0; i--) {
        if (parent[u][i] != -1 && parent[u][i] != parent[v][i]) {
            sumPath += sumVal[u][i] + sumVal[v][i];
            maxPath = max({maxPath, maxVal[u][i], maxVal[v][i]});
            minPath = min({minPath, minVal[u][i], minVal[v][i]});
            u = parent[u][i];
            v = parent[v][i];
        }
    }

    sumPath += sumVal[u][0] + sumVal[v][0];
    maxPath = max({maxPath, maxVal[u][0], maxVal[v][0]});
    minPath = min({minPath, minVal[u][0], minVal[v][0]});

    return parent[u][0];
}

void addEdge(int u, int v) {
    tree[u].push_back(v);
    tree[v].push_back(u);
}

int main() {
    int n, q;
    cout << "Enter the number of nodes: ";
    cin >> n;

    cout << "Enter the values of the nodes:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> nodeValues[i];
    }

    cout << "Enter the edges of the tree (node pairs):" << endl;
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        addEdge(u, v);
    }

    preprocess(n);

    cout << "Enter the number of queries: ";
    cin >> q;
    cout << "Enter the queries (pairs of nodes):" << endl;
    for (int i = 0; i < q; i++) {
        int u, v;
        cin >> u >> v;

        int sumPath, maxPath, minPath;
        int lcaNode = lca(u, v, sumPath, maxPath, minPath);

        sumPath += nodeValues[lcaNode];

        cout << "Query (" << u << ", " << v << "): " << endl;
        cout << "Sum: " << sumPath << endl;
        cout << "Max: " << max(maxPath, nodeValues[lcaNode]) << endl;
        cout << "Min: " << min(minPath, nodeValues[lcaNode]) << endl;
    }

    return 0;
}
