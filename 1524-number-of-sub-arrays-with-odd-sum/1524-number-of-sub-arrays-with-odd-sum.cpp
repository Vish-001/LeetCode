class Solution {
public:
    // subarray with odd no of 1
    int numOfSubarrays(vector<int>& arr) 
    {
        vector<int>nums;
        for(auto c:arr)
        {
            if(c%2==0)
            {
                nums.push_back(0);
            }
            else
            {
                nums.push_back(1);
            }
        }
        unordered_map<int, int> freq;
        freq[0] = 1;  // Base case: empty prefix with even XOR
        int xorSum = 0, count = 0;

        for (int num : nums) {
            xorSum ^= num;  // Update prefix XOR

            // If xorSum is odd, add number of even XORs seen before
            if (xorSum % 2 == 1) {
                count += freq[0];
            } 
            // If xorSum is even, add number of odd XORs seen before
            else {
                count += freq[1];
            }

            // Update frequency map
            freq[xorSum % 2]++;
        }

        return count;
    }
};