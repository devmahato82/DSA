class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        int ans=0;
        vector<int> freq(10,0);
        for(int d : digits) {
            freq[d]++;
        }
        bool flag = true;
        for(int num=100; num<999; num += 2){
            int a = num/100;
            int b = (num/10)%10;
            int c = num%10;

            vector<int> need(10,0) ;
            need[a]++;
            need[b]++;
            need[c]++;

            bool flag = true;
            for(int d=0; d<10;d++) {
                if(need[d]> freq[d]) {
                    flag = false;
                }
            }
            if(flag==true) ans++;

        }
        return ans;
    }
};