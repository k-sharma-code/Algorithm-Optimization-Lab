#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
    // Sorting is MANDATORY for two-pointer approach
    sort(nums.begin(), nums.end());

    int st = 0 ,end = nums.size() - 1;

    while (st < end) {
        int currentSum = nums[st] + nums[end];

        if (currentSum == target) {
            return {nums[st], nums[end]}; // Return the values
        } else if (currentSum < target) {
            st++; // Need a larger sum
        } else {
            end--; // Need a smaller sum
        }
    }

    return {}; // Return empty vector if no pair exists
}

int main() {
    int n, target;
    cout << "Enter number of elements = ";
    cin >> n;

    if (n < 2) {
        cout << " Array must have at least 2 elements." << endl;
        return 0;
    }

    vector<int> nums(n);
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++){
        cin >> nums[i];
    } 

    cout << "Enter target = ";
    cin >> target;

    vector<int> result = twoSum(nums, target);

    if (!result.empty()) {
        cout << " The pair = " << result[0] << " + " << result[1] << " = " << target << endl;
    } else {
        cout << "The pair does not exist " << endl;
    }

    return 0;
}
