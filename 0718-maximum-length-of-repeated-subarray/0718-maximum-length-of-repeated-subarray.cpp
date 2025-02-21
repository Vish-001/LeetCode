class Solution {
public:
    // Check if there exists a substring of length 'size' in s1 that appears in s2.
    bool Chk(string &s1, string &s2, int size) {
        // If size is 0, it's trivially true.
        if(size == 0) return true;
        // Ensure we don't go out of range.
        for(int i = 0; i <= s1.size() - size; i++) {
            string chk = s1.substr(i, size);
            // string::find returns string::npos if not found.
            if(s2.find(chk) != string::npos) {
                return true;
            }
        }
        return false;
    }
    
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int low = 0;
        int high = min(nums1.size(), nums2.size());
        int ans = 0;
        
        // Convert the vectors of ints to strings.
        // We assume that each number is a single digit.
        string s1, s2;
        for (auto c : nums1) {
            s1.push_back(char(c + '0'));
        }
        for (auto c : nums2) {
            s2.push_back(char(c + '0'));
        }
        
        // Binary search for the maximum common subarray length.
        while(low <= high) {
            int mid = (low + high) / 2;
            if (Chk(s1, s2, mid)) {
                ans = mid;        // A common subarray of length mid exists.
                low = mid + 1;    // Try to find a longer common subarray.
            } else {
                high = mid - 1;   // Try a shorter subarray.
            }
        }
        return ans;
    }
};
