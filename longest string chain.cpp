class Solution {
public:
    bool compare(string& a, string& b) {
        int i = 0, j = 0;
        int n = a.size();
        int m = b.size();
        if (n != m + 1)
            return false;

        while (i < n) {
            if (a[i] == b[j]) {
                i++;
                j++;
            } else {
                i++;
            }
        }
        if (i == n && j == m)
            return true;
        else
            return false;
    }
   
    int longestStrChain(vector<string>& words) {
        int n = words.size();
        vector<int> dp(n, 1);
        int maxi = 1;
        sort(words.begin(), words.end(),[](const string &a,const string &b){
            return a.size()<b.size();
        });
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (compare(words[i], words[j]) && dp[j] + 1 > dp[i]) {
                    dp[i] = dp[j] + 1;
                }
            }
            if (maxi < dp[i]) {
                maxi = dp[i];
            }
        }
        return maxi;
    }
};
