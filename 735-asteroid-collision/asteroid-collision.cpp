class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        for(int num : asteroids) {
            if(st.empty() || st.top()<0){
                st.push(num);
            }
            else if(num < 0) {
                if(st.top()>0 && abs(num) == st.top()) st.pop();
                else{
                    while(!st.empty() && st.top()>0 && abs(num) > abs(st.top()) ) {
                        st.pop();
                    }
                    if(st.empty()) st.push(num);
                    else if(abs(num) == st.top()) st.pop();
                    else if(st.top()<0) st.push(num);
                }
            }
            else st.push(num);
        }
        int n = st.size();
        vector<int> ans(n,-1);
        for(int i=n-1; i>=0; i--) {
            ans[i] = st.top();
            st.pop();
        }
        return ans;
    }
};