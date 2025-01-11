class Solution {
public:
    //helper function to check if any point in the check set lies inside the rectangle formed by -> (points[i], points[i+1], points[j], points[j+1])
    bool helper(set<pair<int,int>> &check, int i, int j, vector<vector<int>> &points) {
        int x1= points[i][0], x2 = points[j][0]; 
        int y1 = points[i][1], y2 = points[i+1][1]; 

        for (auto it : check) {
            int x = it.first, y = it.second; 
            //if the point lies inside the rectangle -> return true
            if ((x >= x1 && x <= x2) && (y >= y1 && y <= y2)) return true;
        }
        return false;
    }

    int maxRectangleArea(vector<vector<int>>& points) {
        int n = points.size();
        sort(points.begin(), points.end());
        int maxarea = -1, prevmax = -1; //to store the max area and prev max area
        set<pair<int,int>> check; //set to track points outside the rectangle

        for (int i = 0; i < n - 3; i++) {
            if (points[i][0] != points[i+1][0]) continue; //ensuring points[i] and points[i+1] form a vertical edge

            //loop to identify opposite vertical edge
            for (int j = i + 2; j < n - 1; j++) {
                if (points[j][1] != points[i][1]) { 
                    //if points[j] doesn't share the same ycoord as points[i] add it to check 
                    check.insert({points[j][0], points[j][1]});
                    continue;
                }
                if (points[j+1][1] != points[i+1][1]) {
                    //if points[j+1] doesn't share the same ycoord as points[i+1] add it to check
                    check.insert({points[j][0], points[j][1]});
                    continue;
                }

                //calculate area of the rectangle if valid
                int area = (points[i+1][1] - points[i][1]) * (points[j][0] - points[i+1][0]);
                if (area > maxarea) { 
                    prevmax = maxarea; 
                    maxarea = area; 

                    if (!check.empty() && helper(check, i, j, points)) {
                        maxarea = prevmax;
                    }
                }
            }
            check.clear(); //clear the check after each iteration
        }
        return maxarea;
    }
};
