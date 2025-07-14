#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <cmath>
#include <climits>
#include <algorithm>
#include <string>
using namespace std;

// ----------------------------- Node Struct -----------------------------
struct Node {
    string name;
    pair<int, int> coordinates;

    Node() = default;
    Node(string n, int x, int y) : name(n), coordinates({x, y}) {}
};

// ----------------------------- Graph Class -----------------------------
class Graph {
public:
    unordered_map<string, Node> nodes;
    unordered_map<string, vector<string>> adjList;

    void addNode(const string& name, int x, int y) {
        nodes[name] = Node(name, x, y);
    }

    void addEdge(const string& from, const string& to) {
        adjList[from].push_back(to);
    }

    double euclideanDistance(const string& a, const string& b) const {
        const auto& p1 = nodes.at(a).coordinates;
        const auto& p2 = nodes.at(b).coordinates;
        return sqrt(pow(p1.first - p2.first, 2) + pow(p1.second - p2.second, 2));
    }
};

// ------------------------- Dijkstra Algorithm Class -------------------------
class DijkstraSolver {
public:
    static vector<string> findShortestPath(const Graph& graph, const string& start, const string& end) {
        unordered_map<string, double> distances;
        unordered_map<string, string> previous;

        auto compare = [&distances](const string& a, const string& b) {
            return distances[a] > distances[b];
        };

        priority_queue<string, vector<string>, decltype(compare)> pq(compare);

        for (const auto& pair : graph.nodes) {
            distances[pair.first] = INT_MAX;
            previous[pair.first] = "";
        }

        distances[start] = 0;
        pq.push(start);

        while (!pq.empty()) {
            string current = pq.top(); pq.pop();
            if (current == end) break;

            for (const auto& neighbor : graph.adjList.at(current)) {
                double newDist = distances[current] + graph.euclideanDistance(current, neighbor);
                if (newDist < distances[neighbor]) {
                    distances[neighbor] = newDist;
                    previous[neighbor] = current;
                    pq.push(neighbor);
                }
            }
        }

        vector<string> path;
        for (string at = end; at != ""; at = previous[at]) {
            path.push_back(at);
        }
        reverse(path.begin(), path.end());

        if (path.empty() || path.front() != start) return {}; // no path
        return path;
    }
};

// ------------------------- Application Interface -------------------------
class NavigatorApp {
private:
    Graph graph;

    void buildMap() {
        graph.addNode("Hall 11", 0, 0);
        graph.addNode("Events Ground", 160, 0);
        graph.addNode("Pronite Ground", 320, 0);
        graph.addNode("New Shopping Complex", 400, 0);
        graph.addNode("Health Centre", 700, 0);
        graph.addNode("Hall 6", 800, 0);
        graph.addNode("Hall 10", 0, 200);
        graph.addNode("Hall 9", 0, 380);
        graph.addNode("Hall 13", 0, 660);
        graph.addNode("Hall 12", 120, 750);
        graph.addNode("Hall 8", 160, 80);
        graph.addNode("Hall 7", 160, 160);
        graph.addNode("Counselling Service", 820, 180);
        graph.addNode("Kargil Chowk", 820, 570);
        graph.addNode("Hall 2", 400, 570);
        graph.addNode("Girls Hostel 1", 570, 320);
        graph.addNode("Open Air Theatre", 240, 80);
        graph.addNode("Hall 4", 400, 220);
        graph.addNode("Hall 3", 400, 320);
        graph.addNode("Hall 1", 400, 495);
        graph.addNode("Hall 5", 320, 457);

        graph.addEdge("Hall 11", "Events Ground");
        graph.addEdge("Hall 11", "Hall 10");
        graph.addEdge("Events Ground", "Hall 11");
        graph.addEdge("Events Ground", "Pronite Ground");
        graph.addEdge("Events Ground", "Hall 8");
        graph.addEdge("Events Ground", "Hall 7");
        graph.addEdge("Events Ground", "Open Air Theatre");
        graph.addEdge("Pronite Ground", "Events Ground");
        graph.addEdge("Pronite Ground", "New Shopping Complex");
        graph.addEdge("Pronite Ground", "Hall 5");
        graph.addEdge("New Shopping Complex", "Pronite Ground");
        graph.addEdge("New Shopping Complex", "Health Centre");
        graph.addEdge("New Shopping Complex", "Hall 4");
        graph.addEdge("Health Centre", "New Shopping Complex");
        graph.addEdge("Health Centre", "Hall 6");
        graph.addEdge("Hall 6", "Health Centre");
        graph.addEdge("Hall 6", "Counselling Service");
        graph.addEdge("Hall 10", "Hall 11");
        graph.addEdge("Hall 10", "Hall 9");
        graph.addEdge("Hall 9", "Hall 10");
        graph.addEdge("Hall 9", "Hall 13");
        graph.addEdge("Hall 13", "Hall 9");
        graph.addEdge("Hall 13", "Hall 12");
        graph.addEdge("Hall 12", "Hall 13");
        graph.addEdge("Hall 8", "Events Ground");
        graph.addEdge("Hall 8", "Open Air Theatre");
        graph.addEdge("Hall 8", "Hall 7");
        graph.addEdge("Hall 7", "Events Ground");
        graph.addEdge("Hall 7", "Hall 8");
        graph.addEdge("Counselling Service", "Hall 6");
        graph.addEdge("Counselling Service", "Kargil Chowk");
        graph.addEdge("Kargil Chowk", "Counselling Service");
        graph.addEdge("Kargil Chowk", "Hall 2");
        graph.addEdge("Hall 2", "Kargil Chowk");
        graph.addEdge("Hall 2", "Hall 1");
        graph.addEdge("Hall 2", "Hall 3");
        graph.addEdge("Hall 2", "Hall 5");
        graph.addEdge("Hall 3", "Hall 5");
        graph.addEdge("Girls Hostel 1", "Hall 1");
        graph.addEdge("Open Air Theatre", "Events Ground");
        graph.addEdge("Open Air Theatre", "Hall 8");
        graph.addEdge("Hall 4", "New Shopping Complex");
        graph.addEdge("Hall 3", "Hall 2");
        graph.addEdge("Hall 1", "Hall 2");
        graph.addEdge("Hall 1", "Girls Hostel 1");
        graph.addEdge("Hall 5", "Pronite Ground");
    }

public:
    void run() {
        buildMap();
        string start, end;
        cout << "Enter start location: ";
        getline(cin, start);
        cout << "Enter end location: ";
        getline(cin, end);

        if (graph.nodes.find(start) == graph.nodes.end() || graph.nodes.find(end) == graph.nodes.end()) {
            cout << "Invalid location entered.\n";
            return;
        }

        vector<string> path = DijkstraSolver::findShortestPath(graph, start, end);
        if (path.empty()) {
            cout << "No path found from " << start << " to " << end << ".\n";
        } else {
            cout << "Shortest path: ";
            for (const string& location : path)
                cout << location << " ";
            cout << endl;
        }
    }
};

// ----------------------------- Main Function -----------------------------
int main() {
    NavigatorApp app;
    app.run();
    return 0;
}
