class Solution {
public:
    // Function to check if it's possible to partition string into `k` parts with no repeating characters in any part
    bool canPartition(const string& s, int k) {
        int partitions = 1;  // Start with 1 partition
        set<char> st;  // Set to track unique characters in the current partition
        
        for (char c : s) {
            // If character is already in the set, a new partition is needed
            if (st.find(c) != st.end()) {
                partitions++;  // Start a new partition
                st.clear();  // Clear the set for the new partition
            }
            st.insert(c);  // Insert the current character
            if (partitions > k) {
                return false;  // More partitions than allowed
            }
        }
        
        return true;  // If we can partition within k parts
    }

    // Main function to find the minimum number of partitions
    int partitionString(string s) {
        int low = 1, high = s.size();
        int result = s.size();  // Max possible partitions is the size of the string
        
        // Binary search on number of partitions
        while (low <= high) {
            int mid = (low + high) / 2;
            if (canPartition(s, mid)) {
                result = mid;  // Update result
                high = mid - 1;  // Try smaller number of partitions
            } else {
                low = mid + 1;  // Try larger number of partitions
            }
        }
        
        return result;
    }
};
