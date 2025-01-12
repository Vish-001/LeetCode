class Solution {
public:
    int takeCharacters(string s, int k) {
        int n = s.size();

        // Count total occurrences of 'a', 'b', and 'c'
        int totalA = count(s.begin(), s.end(), 'a');
        int totalB = count(s.begin(), s.end(), 'b');
        int totalC = count(s.begin(), s.end(), 'c');

        // If any character appears less than k times, it's impossible
        if (totalA < k || totalB < k || totalC < k) {
            return -1;
        }

        // Variables to track counts within the sliding window
        int left = 0, right = 0;
        int countA = 0, countB = 0, countC = 0;
        int maxValidLength = 0;

        while (right < n) {
            // Add the character at `right` to the window
            if (s[right] == 'a') countA++;
            if (s[right] == 'b') countB++;
            if (s[right] == 'c') countC++;

            // While removing this window is invalid, shrink it from the left
            while ((totalA - countA < k) || (totalB - countB < k) || (totalC - countC < k)) {
                if (s[left] == 'a') countA--;
                if (s[left] == 'b') countB--;
                if (s[left] == 'c') countC--;
                left++;
            }

            // Update the maximum valid window length
            maxValidLength = max(maxValidLength, right - left + 1);
            right++;
        }

        // Minimum characters to remove = total size - max valid substring length
        return n - maxValidLength;
    }
};
