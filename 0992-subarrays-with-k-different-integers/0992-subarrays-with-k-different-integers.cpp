#include <vector>
#include <unordered_map>

class Solution {
public:
    int subarraysWithKDistinct(std::vector<int>& nums, int k) {
        return atMostKDistinct(nums, k) - atMostKDistinct(nums, k - 1);
    }

private:
    int atMostKDistinct(const std::vector<int>& nums, int k) {
        std::unordered_map<int, int> mp;
        int l = 0, r = 0;
        int count = 0;

        while (r < nums.size()) {
            mp[nums[r]]++;
            
            // If there are more than k distinct elements, shrink the window from the left
            while (mp.size() > k) {
                mp[nums[l]]--;
                if (mp[nums[l]] == 0) {
                    mp.erase(nums[l]);
                }
                l++;
            }

            // Count the number of subarrays with at most k distinct elements
            count += r - l + 1;
            r++;
        }

        return count;
    }
};
