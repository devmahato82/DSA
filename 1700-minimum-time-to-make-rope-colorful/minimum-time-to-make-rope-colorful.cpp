class Solution {
public:
    int minCost(string s, vector<int>& neededTime) {
        int n = s.size();
        int totalTime =0;
        for(int i=0; i<n;) {
            char c = s[i];
            int maxTime =0;
            int sum =0;
            while(i<n && s[i] == c) {
                sum += neededTime[i];
                maxTime = max(maxTime, neededTime[i]);
                i++;
            }
            totalTime += (sum-maxTime);
        }
        return totalTime;
    }
};