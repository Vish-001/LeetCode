#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool check(vector<int>& nums, int k, int capacity) {
        int count = 0;
        int n = nums.size();
        for (int i = 0; i < n; ) {
            if (nums[i] <= capacity) {
                count++;
                i += 2; // Skip next house
            } else {
                i += 1;
            }
        }
        return count >= k;
    }

    int minCapability(vector<int>& nums, int k) {
        int low = 1;
        int high = *max_element(nums.begin(), nums.end());
        while (low < high) {
            int mid = low + (high - low) / 2;
            if (check(nums, k, mid)) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }
        return low;
    }
};