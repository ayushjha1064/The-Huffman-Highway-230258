#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int findMinimumPlatforms(vector<int> &arrival, vector<int> &departure) {
    sort(arrival.begin(), arrival.end());
    sort(departure.begin(), departure.end());

    int n = arrival.size();
    int platform_needed = 1;
    int max_platforms = 1;
    int i = 1;
    int j = 0;

    while (i < n && j < n) {
        if (arrival[i] <= departure[j]) {
            platform_needed++;
            i++;
        } else {
            platform_needed--;
            j++;
        }
        if (platform_needed > max_platforms)
            max_platforms = platform_needed;
    }

    return max_platforms;
}

int main() {
    int n;
    cout << "Enter the number of trains: ";
    cin >> n;

    vector<int> arrival(n);
    vector<int> departure(n);

    cout << "Enter the arrival times (in 24-hour format, without colon):" << endl;
    for (int i = 0; i < n; i++) {
        cin >> arrival[i];
    }

    cout << "Enter the departure times (in 24-hour format, without colon):" << endl;
    for (int i = 0; i < n; i++) {
        cin >> departure[i];
    }

    int result = findMinimumPlatforms(arrival, departure);
    cout << "Minimum Platforms needed: " << result << endl;

    return 0;
}
