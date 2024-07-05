#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

struct Point {
    int x, y, z;
};

bool isValid(int x, int y, int z, int X, int Y, int Z, vector<vector<vector<int>>> &grid, vector<vector<vector<bool>>> &visited) {
    return (x >= 0 && x < X && y >= 0 && y < Y && z >= 0 && z < Z && grid[x][y][z] == 0 && !visited[x][y][z]);
}

int shortestPathIn3DGrid(int X, int Y, int Z, Point source, Point destination, vector<vector<vector<int>>> &grid) {
    if (grid[source.x][source.y][source.z] == 1 || grid[destination.x][destination.y][destination.z] == 1) {
        return -1;
    }

    vector<vector<vector<bool>>> visited(X, vector<vector<bool>>(Y, vector<bool>(Z, false)));
    queue<tuple<Point, int>> q;

    q.push({source, 0});
    visited[source.x][source.y][source.z] = true;

    vector<Point> directions = {{1, 0, 0}, {-1, 0, 0}, {0, 1, 0}, {0, -1, 0}, {0, 0, 1}, {0, 0, -1}};

    while (!q.empty()) {
        auto [current, dist] = q.front();
        q.pop();

        if (current.x == destination.x && current.y == destination.y && current.z == destination.z) {
            return dist;
        }

        for (const auto &dir : directions) {
            int newX = current.x + dir.x;
            int newY = current.y + dir.y;
            int newZ = current.z + dir.z;

            if (isValid(newX, newY, newZ, X, Y, Z, grid, visited)) {
                visited[newX][newY][newZ] = true;
                q.push({{newX, newY, newZ}, dist + 1});
            }
        }
    }

    return -1;
}

int main() {
    int X = 4, Y = 5, Z = 3;
    Point source = {0, 0, 0};
    Point destination = {3, 4, 2};

    vector<vector<vector<int>>> grid = {
        {
            {0, 1, 1},
            {0, 1, 0},
            {1, 0, 0},
            {0, 0, 0},
            {0, 0, 0}
        },
        {
            {1, 1, 0},
            {1, 1, 0},
            {0, 0, 0},
            {0, 1, 1},
            {0, 0, 0}
        },
        {
            {0, 1, 1},
            {0, 1, 0},
            {0, 1, 1},
            {0, 1, 0},
            {0, 0, 1}
        },
        {
            {0, 1, 0},
            {1, 1, 1},
            {1, 0, 0},
            {1, 1, 0},
            {0, 0, 0}
        }
    };

    int result = shortestPathIn3DGrid(X, Y, Z, source, destination, grid);

    if (result != -1) {
        cout << "The shortest path length is: " << result << endl;
    } else {
        cout << "No valid path found." << endl;
    }

    return 0;
}
