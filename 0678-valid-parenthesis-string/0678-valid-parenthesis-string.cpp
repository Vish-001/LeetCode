class Solution {
public:
    /**
     * @brief Checks if the given string of parentheses can be valid.
     * @param s The string to check for validity
     * @return bool Returns true if the string can be valid, false otherwise
     */
    bool checkValidString(string s) {
        int minOpen = 0;  // Minimum count of unmatched '('
        int maxOpen = 0;  // Maximum count of unmatched '(' including '*' as '('

        for (char c : s) {
            if (c == '(') {
                minOpen++;
                maxOpen++;
            } else if (c == ')') {
                minOpen = max(0, minOpen - 1);  // Decrease if possible, else it's invalid
                maxOpen--;
                if (maxOpen < 0) return false;  // If we have more ')' than possible '(' or '*', it's invalid
            } else { // c == '*'
                // '*' can be '(', ')', or nothing
                minOpen = max(0, minOpen - 1);  // Treat '*' as ')' if possible to balance
                maxOpen++;
            }
        }

        // After processing all characters, if all '(' can be matched, it's valid
        return minOpen == 0;
    }
};