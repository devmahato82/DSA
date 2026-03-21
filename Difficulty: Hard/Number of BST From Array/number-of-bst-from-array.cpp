
class Solution{
    
public:
    int countBST(vector<int>& nodes) {
        int n = nodes.size();
        if (n <= 1) return 1; 
        
        int total = 0;
        
        for (int i = 0; i < n; i++) {
            vector<int> left(nodes.begin(), nodes.begin() + i);
            vector<int> right(nodes.begin() + i + 1, nodes.end());
            
            int leftCount = countBST(left);
            int rightCount = countBST(right);
            
            total += leftCount * rightCount;
        }
        return total;
    }
    
    vector<int> countBSTs(vector<int>& arr) {
        int n = arr.size();
        vector<int> sortedArr = arr;
        sort(sortedArr.begin(), sortedArr.end());
        
        unordered_map<int,int> pos;
        for (int i = 0; i < n; i++) pos[sortedArr[i]] = i;
        
        vector<int> ans(n);
        for (int i = 0; i < n; i++) {
            int idx = pos[arr[i]];
            vector<int> left(sortedArr.begin(), sortedArr.begin() + idx);
            vector<int> right(sortedArr.begin() + idx + 1, sortedArr.end());
            
            ans[i] = countBST(left) * countBST(right);
        }
        return ans;
    }

};