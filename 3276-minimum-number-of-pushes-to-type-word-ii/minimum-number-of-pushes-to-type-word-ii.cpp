class Solution {
public:
    int minimumPushes(string word) {
        vector<int> freq(26,0);
        for(char ch:word) freq[ch-'a']++;
        sort(freq.begin(),freq.end(), greater<int>());
        int count =0;
        for(int i=0; i<26; i++) {
            if(i<8) count+= freq[i];
            else if(i<16) count+= freq[i]*2;
            else if(i<24) count+= freq[i]*3;
            else count += freq[i]*4;
        }
        return count;
    }
};