#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int findMinimumMergeCost(vector<int> &file_sizes) {
    priority_queue<int, vector<int>, greater<int> > minHeap(file_sizes.begin(), file_sizes.end());

    int total_cost = 0;

    while (minHeap.size() > 1) {
        int first_smallest = minHeap.top();
        minHeap.pop();
        int second_smallest = minHeap.top();
        minHeap.pop();

        int merge_cost = first_smallest + second_smallest;
        total_cost += merge_cost;

        minHeap.push(merge_cost);
    }

    return total_cost;
}

int main() {
    int n;
    cout << "Enter the number of files: ";
    cin >> n;

    vector<int> file_sizes(n);
    cout << "Enter the sizes of the files:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> file_sizes[i];
    }

    int result = findMinimumMergeCost(file_sizes);
    cout << "Minimum Cost to merge all files: " << result << endl;

    return 0;
}
