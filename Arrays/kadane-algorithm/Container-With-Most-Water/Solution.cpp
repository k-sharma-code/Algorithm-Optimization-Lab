#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int maxArea(vector<int>& height) {
    int n=height.size();
    int maxwater = 0;
    int i = 0, j = n - 1;

    while (i < j) {
        int w = j - i;
        int ht = min(height[i], height[j]);
        int currwater = w * ht;
        maxwater = max(maxwater, currwater);

        // Move the pointer pointing to the shorter line
        height[i]<height[j] ? i++:j--;
    }
    return maxwater;
}

int main() {
    int n;
    cout << "Enter the number of vertical lines: ";
    cin >> n;

    if (n < 2) {
        cout << "Invalid input. Need at least 2 lines." << endl;
        return 1;
    }

    vector<int> height(n);
    cout << "Enter the heights: " << endl;
    for (int i = 0; i < n; i++) {
        cin >> height[i];
    }

    int ans = maxArea(height);
    cout << "Maximum water container capacity = " << ans << endl;

    return 0;
}
