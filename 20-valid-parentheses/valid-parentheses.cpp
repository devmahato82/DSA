class Solution {
public:
    bool isValid(string s) {
        int n = s.length();
        stack<char> st;
        for(int i=0; i<n; i++) {
            char ch = s[i];
            if(ch == '(' || ch == '{' || ch =='[') {
                st.push(ch);
            }
            else{
                char front;
                if(!st.empty()) front = st.top();
                else  return false;
                if((front == '(' && ch == ')')
                || (front == '{' && ch == '}')
                || (front == '[' && ch == ']')
                ) st.pop();
                else return false;
            }
        }
        if(st.size() == 0) return true;
        else return false;
    }
};