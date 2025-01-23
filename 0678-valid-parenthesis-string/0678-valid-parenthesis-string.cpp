#include <string>
using namespace std;

class Solution {
public:
    bool checkValidString(string s) {
        int mini = 0;  // Minimum possible '(' count
        int maxi = 0;  // Maximum possible '(' count

        for (auto c : s) {
            if (c == '(') {
                mini++;
                maxi++;
            } else if (c == ')') {
                maxi--;
                mini--;
            } else if (c == '*') {
                mini--;
                maxi++;
            }

            if (mini < 0) {
                mini = 0;  // Minimum cannot be negative
            }

            // If maximum possible '(' count is negative, return false
            if (maxi < 0) {
                return false;
            }
        }

        // If minimum possible '(' count is zero, string is valid
        return mini == 0;
    }
};
