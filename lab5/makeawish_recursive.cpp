#include <iostream>
#include <vector>
#include <algorithm>  // For std::max

using namespace std;

int maxWishSum(const vector<int>& wishValues) {
    int maxSum = wishValues[0];
    int currentSum = wishValues[0];

    for (size_t i = 1; i < wishValues.size(); i++) {
        // Either continue the current subarray or start a new one
        currentSum = max(wishValues[i], currentSum + wishValues[i]);
        maxSum = max(maxSum, currentSum);
    }

    return maxSum;
}

int main() {
    int n;
    cin >> n;
    vector<int> wishValues(n);
    for (int i = 0; i < n; i++) {
        cin >> wishValues[i];
    }

    int maxWish = maxWishSum(wishValues);
    cout << maxWish << endl;

    return 0;
}
