#include <bits/stdc++.h>
using namespace std;

int knapsack(int N, int W, vector<int>& weights, vector<int>& values, vector<int>& dependencies, vector<int>& categories, vector<int>& limits) {
    vector<vector<int>> dp(N + 1, vector<int>(W + 1, 0));
    unordered_map<int, bool> used_categories;
    
    for (int i = 0; i < N; ++i) {
        if (limits[i] == 0) continue;
        for (int j = W; j >= weights[i]; --j) {
            if (categories[i] != -1 && used_categories[categories[i]]) continue;

            int max_value = 0;
            for (int k = 1; k <= limits[i]; ++k) {
                if (j >= k * weights[i]) {
                    dp[i + 1][j] = max(dp[i + 1][j], dp[i][j - k * weights[i]] + k * values[i]);
                    max_value = max(max_value, dp[i + 1][j]);
                }
            }

            dp[i + 1][j] = max_value;
            used_categories[categories[i]] = true;
        }
    }
    
    return dp[N][W];
}

int main() {
    int N = 10;
    int W = 100;
    vector<int> weights = {10, 20, 30, 40, 15, 25, 35, 45, 55, 50};
    vector<int> values = {60, 100, 120, 240, 150, 90, 200, 170, 250, 300};
    vector<int> dependencies = {-1, 0, -1, 2, -1, -1, 1, 4, -1, 7}; 
    vector<int> categories = {1, 0, 0, 1, 2, 2, 3, 3, 4, 4}; 
    vector<int> limits = {1, 2, 1, 1, 1, 1, 1, 1, 1, 1}; 
    
    int result = knapsack(N, W, weights, values, dependencies, categories, limits);
    cout << "Maximum Knapsack Value: " << result << endl;
    
    return 0;
}
