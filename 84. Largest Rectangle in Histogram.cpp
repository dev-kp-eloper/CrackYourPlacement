//Link - https://leetcode.com/problems/largest-rectangle-in-histogram/description/

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int> s;
        int maxA = 0;
        for(int i=0; i<=n; i++){
            while(!s.empty() and (i==n or heights[s.top()] >= heights[i])){
                int h = heights[s.top()];
                s.pop();
                int width;
                if(s.empty()) width = i;
                else width = i - s.top() - 1;
                maxA = max(maxA, width * h);
            }
            s.push(i);
        }
        return maxA;
    }
};
