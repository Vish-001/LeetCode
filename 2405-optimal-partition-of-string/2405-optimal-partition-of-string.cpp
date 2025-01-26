class Solution {
public:
    int partitionString(string s) {
        int partitions = 1;  // At least one partition is needed
        set<char> st;  // To track characters in the current partition

        for (char ch : s) {
            if (st.find(ch) != st.end()) {
                partitions++;  // Start a new partition
                st.clear();  // Clear the set for the new partition
            }
            st.insert(ch);  // Add the current character to the set
        }

        return partitions;
    }
};
