#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;
int maxSubarraySum(int arr[], int n) {
    int mx = INT_MIN; // Global maximum
    int cs = 0;      // Local maximum

    for (int i = 0; i < n; i++) {
        cs += arr[i];
        
        if (mx < cs) {
            mx = cs;
        }

        if (cs < 0) {
            cs = 0;
        }
    }
    return mx;
}

int main() {
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;
    if (n <= 0) {
        cout << "Invalid array size." << endl;
        return 1;
    }

    int arr[n];
    cout << "Enter " << n << " elements: " << endl;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int result = maxSubarraySum(arr, n);
    cout << "The Maximum Subarray Sum is: " << result << endl;

    return 0;
}
