class Solution {
public:
    static bool comp(const pair<string, vector<string>>& a, const pair<string, vector<string>>& b) {
        if (a.second == b.second)  // If contents are the same, sort by identifier
            return a.first < b.first;  
        return a.second < b.second;  // Otherwise, sort by content
    }

    vector<string> reorderLogFiles(vector<string>& logs) {
        vector<pair<string, vector<string>>> vec1;  // Letter logs
        vector<string> vec2;  // Digit logs (stored as strings)
        
        for (int i = 0; i < logs.size(); i++) {
            stringstream ss(logs[i]);
            string idf, word;
            ss >> idf;  // Extract identifier
            vector<string> content;
            while (ss >> word) content.push_back(word);
            
            if (isdigit(content[0][0]))  // If first word is a digit, it's a digit log
                vec2.push_back(logs[i]);
            else
                vec1.push_back({idf, content});
        }

        // Sort letter logs using the custom comparator
        sort(vec1.begin(), vec1.end(), comp);

        // Convert sorted letter logs back to string format
        vector<string> ans;
        for (auto& p : vec1) {
            string s = p.first;
            for (auto& word : p.second) {
                s += " " + word;
            }
            ans.push_back(s);
        }

        // Append digit logs in original order
        for (auto& log : vec2) {
            ans.push_back(log);
        }

        return ans;
    }
};
