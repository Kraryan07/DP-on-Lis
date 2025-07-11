class Solution {
public:
 int miniCost(int i,int j,vector<int>&cuts,vector<vector<int>>&dp){
    if(i>j) return 0;
    int mini=1e9;
    if(dp[i][j]!=-1) return dp[i][j];
    for(int ind=i;ind<=j;ind++){
        int cost=(cuts[j+1]-cuts[i-1])+miniCost(i,ind-1,cuts,dp)+miniCost(ind+1,j,cuts,dp);
        if(mini>cost) mini=cost;
    }
    return dp[i][j]=mini;
 }
    int minCost(int n, vector<int>& cuts) {
        int c=cuts.size();
        cuts.push_back(n);
        cuts.insert(cuts.begin(),0);
        sort(cuts.begin(),cuts.end());
        vector<vector<int>>dp(c+1,vector<int>(c+1,-1));
        return miniCost(1,c,cuts,dp);
    }
};

tabulation approach
#include <bits/stdc++.h> 
int maxCoins(vector<int>& arr)
{
	// Write your code here.
   int n=arr.size();
   arr.push_back(1);
   arr.insert(arr.begin(),1);
   vector<vector<int>>dp(n+2,vector<int>(n+2,0));
   for(int i=n;i>=1;i--){
      for(int j=1;j<=n;j++){
         if(i>j) continue;
         int maxi=INT_MIN;
         for(int k=i;k<=j;k++){
            int cost=(arr[k]*arr[i-1]*arr[j+1])+dp[i][k-1]+dp[k+1][j];
            maxi=max(maxi,cost);
         }
         dp[i][j]=maxi;
      }
   }
   return dp[1][n];
}
