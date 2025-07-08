class Solution {
  public:
    int findlongest(int ind,int prev,vector<int>&arr,int n,vector<vector<int>>&dp){
        if(ind==n) return 0;
        if(dp[ind][prev+1]!=-1) return dp[ind][prev+1];
        int len=findlongest(ind+1,prev,arr,n,dp);
        if(prev==-1||arr[ind]>arr[prev]){
            len=max(len,1+findlongest(ind+1,ind,arr,n,dp));
        }
        return dp[ind][prev+1]=len;
    }
    int lis(vector<int>& arr) {
        // code here
        int n=arr.size();
        vector<vector<int>>dp(n,vector<int>(n+1,-1));
        return findlongest(0,-1,arr,n,dp);
    }
};

optimised approach
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n,1);
        for(int i=n-1;i>=0;i--){
            for(int j=i+1;j<n;j++){
                if(nums[j]>nums[i]){
                    dp[i]=max(dp[i],1+dp[j]);
                }
            }
        }
        int ans=0;
        for(int i:dp){
            ans=max(ans,i);
        }
        return ans;
    }
};
