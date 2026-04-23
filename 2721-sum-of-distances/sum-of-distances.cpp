class Solution {
public:
    vector<long long> distance(vector<int>& arr) {
        int n = arr.size();
        vector<long long> ans(n,0);
        unordered_map<int, vector<long long>> mp;
        for(int i=0; i<n; i++) {
            if(mp.find(arr[i]) != mp.end()){
                mp[arr[i]].push_back(i);
            }
            else{
                mp[arr[i]].push_back(i);
            }
        }
        // for(int i=0; i<n; i++) {
        //     if(mp[arr[i]].size() == 1) continue;
        //     else {
        //         long long count =0;
        //         for(auto x : mp[arr[i]]){
        //             if(x==i) continue;
        //             else count += abs(i-x);
        //         }
        //         ans[i] = count;
        //     }
        // }
        for(auto x : mp){
            vector<long long> v = x.second;
            int k = v.size();
            vector<long long> prefix(k);
            prefix[0] = v[0];
            for(int i=1; i<k;i++){
                prefix[i] = prefix[i-1] + v[i];
            }
            for(int j=0; j<k; j++) {
                long long left =0, right =0 ;
                if(j>0) {
                    left = v[j]*j - prefix[j-1];
                }
                if(j<k-1) {
                    right = prefix[k-1] - prefix[j] - v[j]*(k-j-1);
                }
                ans[v[j]] = left+right;
            }
        }
        return ans;
    }
};