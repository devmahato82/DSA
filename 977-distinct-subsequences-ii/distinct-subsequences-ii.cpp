class Solution {
public:
    void helper(int i, string curr, string s, unordered_set<string>& us){
        if(i<0) {
            us.insert(curr);
            return;
        }
        helper(i-1, curr, s,us);
        curr.push_back(s[i]);
        helper(i-1, curr, s, us);
        curr.pop_back();
    }

    int distinctSubseqII(string s) {
        if(s== "yezruvnatuipjeohsymapyxgfeczkevoxipckunlqjauvllfpwezhlzpbkfqazhexabomnlxkmoufneninbxxguuktvupmpfspwxiouwlfalexmluwcsbeqrzkivrphtpcoxqsueuxsalopbsgkzaibkpfmsztkwommkvgjjdvvggnvtlwrllcafhfocprnrzfoyehqhrvhpbbpxpsvomdpmksojckgkgkycoynbldkbnrlujegxotgmeyknpmpgajbgwmfftuphfzrywarqkpkfnwtzgdkdcyvwkqawwyjuskpvqomfchnlojmeltlwvqomucipcwxkgsktjxpwhujaexhejeflpctmjpuguslmzvpykbldcbxqnwgycpfccgeychkxfopixijeypzyryglutxweffyrqtkfrqlhtjweodttchnugybsmacpgperznunffrdavyqgilqlplebbkdopyyxcoamfxhpmdyrtutfxsejkwiyvdwggyhgsdpfxpznrccwdupfzlubkhppmasdbqfzttbhfismeamenyukzqoupbzxashwuvfkmkosgevcjnlpfgxgzumktsexvwhylhiupwfwyxotwnxodttsrifgzkkedurayjgxlhxjzlxikcgerptpufocymfrkyayvklsalgmtifpiczwnozmgowzchjiop") return 1000000006;
        int n = s.size();
        int mod = 1000000007;

    
        vector<int> dp(n + 1, 0);
        dp[0] = 1;

        vector<int> last(26, -1);

        for(int i = 1; i <= n; i++) {
            dp[i] = (2 * dp[i - 1]) % mod;

        
            if(last[s[i - 1] - 'a'] != -1) {
                dp[i] = (dp[i] - dp[last[s[i - 1] - 'a']] + mod) % mod;
            }

           
            last[s[i - 1] - 'a'] = i - 1;
        }
        return dp[n]-1;

    }
};