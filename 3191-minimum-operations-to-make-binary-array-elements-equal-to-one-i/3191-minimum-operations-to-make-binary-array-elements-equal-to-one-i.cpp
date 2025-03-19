class Solution {
public:
    int minOperations(vector<int>& nums) {
        int ans = 0;
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) {  
                ans++;  // Increment operation count

                if (i + 2 >= n) return -1; // If we can't flip i+1 and i+2, return -1
                
                // Convert nums[i] to 1
                nums[i] = 1;

                // Flip nums[i+1] (0 -> 1 or 1 -> 0)
                nums[i+1] = nums[i+1] == 0 ? 1 : 0;

                // Flip nums[i+2] (0 -> 1 or 1 -> 0)
                nums[i+2] = nums[i+2] == 0 ? 1 : 0;
            }
        }
        return ans;
    }
};
