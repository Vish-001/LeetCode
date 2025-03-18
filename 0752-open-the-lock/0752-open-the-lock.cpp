
class Solution {
public:
    int openLock(vector<string>& deadends, string target) 
    {
        unordered_set<string> deadSet(deadends.begin(), deadends.end());
        if (deadSet.count("0000")) return -1;

        queue<pair<string, int>> q;
        unordered_set<string> visited;
        q.push({"0000", 0});
        visited.insert("0000");

        while (!q.empty()) {
            auto [current, steps] = q.front();
            q.pop();

            if (current == target) return steps;

            for (int i = 0; i < 4; i++) {
                char c = current[i];
                for (int d = -1; d <= 1; d += 2) {  // Try +1 and -1
                    char newChar = (c - '0' + d + 10) % 10 + '0';
                    string newCombination = current;
                    newCombination[i] = newChar;

                    if (!deadSet.count(newCombination) && !visited.count(newCombination)) {
                        q.push({newCombination, steps + 1});
                        visited.insert(newCombination);
                    }
                }
            }
        }
        return -1;
    }
};
