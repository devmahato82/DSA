class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int> st;
        int maxArea =0;
        for(int i=0; i<n; i++) {
            while(!st.empty() && heights[st.top()] > heights[i]) {
                int element = st.top();
                st.pop();
                int nsei = i;
                int psei = st.empty() ? -1 : st.top();
                maxArea = max(maxArea, heights[element]* (nsei-psei-1));
            }
            st.push(i);
        }
        while(!st.empty()) {
            int element = st.top();
            st.pop();
            int nsei = n;
            int psei = st.empty() ? -1 : st.top();
            maxArea = max(maxArea, heights[element]* (nsei-psei-1));
        }
        return maxArea;
    }
};