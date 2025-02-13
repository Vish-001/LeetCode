class Solution {
public:
    int minOperations(vector<int>& a, int k) {
        sort(a.begin(), a.end());
        for (int i = 0, j = 0, g = 0, count = 0, x, y; ; ++count) {
            if (i < a.size() && (j >= g || a[i] <= a[j])) x = a[i++];
            else x = a[j++];
            if (x >= k) return count;
            if (i < a.size() && (j >= g || a[i] <= a[j])) y = a[i++];
            else y = a[j++];
            long t = 2L * x + y; // test overflow
            a[g++] = t < k ? (int)t : k;
        }
        return -1;
    }
};