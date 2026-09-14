class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();
        vector<vector<bool>> dp(n, vector<bool> (n, false));
        int ans = 0;
        for(int i = 0; i < n; i++){
            dp[i][i] = true;
            ans++;
        }
        int start = 0;
        int maxLen = 1;
        for(int len = 2; len <= n; len++){
            for(int i = 0; i + len <= n; i++){
                int j = i + len - 1;
                if (s[i] == s[j]){
                    if (len == 2 || dp[i + 1][j - 1]){
                        ans++;
                        dp[i][j] = true;
                        
                    }
                }
            }
        }
        return ans;
    }
};
