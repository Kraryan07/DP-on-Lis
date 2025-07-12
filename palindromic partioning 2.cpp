class Solution {
public:
    bool ispalindrome(int i,int j,string &s){
       while(i<j){
        if(s[i]!=s[j]){
            return false;
        }
        i++;
        j--;
       }
       return true; 
    }
    int minpart(int i,string &s,int n,vector<int>&dp){
        if(i==n) return 0;
        // string temp="";
        int cost=0;
        if(dp[i]!=-1) return dp[i];
        int mini=INT_MAX;
        for(int j=i;j<n;j++){
            // temp+=s[j];
            if(ispalindrome(i,j,s)){
                cost=1+minpart(j+1,s,n,dp);
                 mini=min(mini,cost);
            } 
        }
        return dp[i]=mini;
    }
    int minCut(string s) {
        int n=s.size();
        vector<int>dp(n,-1);
        return minpart(0,s,n,dp)-1;
    }
};

tabulation
// User function Template for C++

class Solution {
  public:
     bool ispalindrome(int i,int j,string &s){
       while(i<j){
        if(s[i]!=s[j]){
            return false;
        }
        i++;
        j--;
       }
       return true; 
    }
    int palPartition(string &s) {
        // code here
        int n=s.size();
        vector<int>dp(n+1,0);
        // int cost=0;
        for(int i=n-1;i>=0;i--){
            int mini=INT_MAX;
            for(int j=i;j<n;j++){
                if(ispalindrome(i,j,s)){
                   int cost=1+dp[j+1];
                    mini=min(mini,cost);
                }
            }
            dp[i]=mini;
        }
        return dp[0]-1;
    }
};
