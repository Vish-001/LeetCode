class Solution {
public:
    static bool comp(const pair<string, string>& a, const pair<string, string>& b) {
        if (a.second == b.second)  // If contents are the same, sort by identifier
            return a.first < b.first;
        return a.second < b.second;  // Otherwise, sort by content
    }

    vector<string> reorderLogFiles(vector<string>& logs) {
        vector<pair<string, string>> letterLogs;  // Stores {identifier, content}
        vector<string> digitLogs;  // Stores digit logs as-is

        for (int i = 0; i < logs.size(); i++) {
            stringstream ss(logs[i]);  
            string str;
            getline(ss, str, ' ');  // Extract identifier
            string idf = str;
            string content = "";
            bool isDigit = false;

            while (getline(ss, str, ' ')) {  
                if (isdigit(str[0])) isDigit = true;  // If first word is a digit, it's a digit log
                if (!content.empty()) content += " ";  // Add space between words
                content += str;
            }

            if (isDigit) {
                digitLogs.push_back(logs[i]);  
            } else {
                letterLogs.push_back({idf, content});
            }
        }

        // Sort letter logs using custom comparator
        sort(letterLogs.begin(), letterLogs.end(), comp);

        // Construct result
        vector<string> ans;
        for (int i = 0; i < letterLogs.size(); i++) {
            ans.push_back(letterLogs[i].first + " " + letterLogs[i].second);
        }
        for (int i = 0; i < digitLogs.size(); i++) {
            ans.push_back(digitLogs[i]);  // Append digit logs at the end
        }

        return ans;
    }
};
