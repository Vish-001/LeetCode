#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

class Solution {
public:
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int> current = nums;

        // Check if the array is already all zeros.
        if (all_of(current.begin(), current.end(), [](int x) { return x == 0; })) {
            return 0;
        }

        // Lambda to check if the first 'k' queries can make the array all zeros.
        auto canMakeZero = [&](int k) {
            vector<int> diff(n + 1, 0); // Difference array for range updates
            for (int i = 0; i < k; ++i) {
                int l = queries[i][0];
                int r = queries[i][1];
                int val = queries[i][2]; // Decrement value for the range
                diff[l] += val;
                if (r + 1 < n) {
                    diff[r + 1] -= val;
                }
            }

            // Apply the difference array and check if all elements become zero
            int total = 0;
            for (int i = 0; i < n; ++i) {
                total += diff[i];
                if (current[i] - total > 0) {
                    return false; // Current value cannot be zeroed with these queries
                }
            }
            return true;
        };

        // Binary search to find the minimum number of queries.
        int left = 0, right = queries.size(), ans = -1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (canMakeZero(mid)) {
                ans = mid;
                right = mid - 1; // Try fewer queries
            } else {
                left = mid + 1; // Try more queries
            }
        }
        return ans;
    }
};
