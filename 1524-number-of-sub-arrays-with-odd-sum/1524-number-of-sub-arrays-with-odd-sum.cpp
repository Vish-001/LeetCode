#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int numOfSubarrays(vector<int>& arr) 
    {
        unordered_map<int, int> freq;
        freq[0] = 1; 
        int xorSum = 0, count = 0;
        const int MOD = 1e9+7;  

        for (int num : arr) 
        {
            xorSum ^= num;  // XOR update directly on 0/1

            // If xorSum is odd, add number of even XORs seen before
            if (xorSum % 2 == 1) {
                count = (count + freq[0]) % MOD;
            } 
            else {
                count = (count + freq[1]) % MOD;
            }

            freq[xorSum % 2]++;
        }

        return count;
    }
};
