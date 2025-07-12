class Solution {
public:
    int findmax(int i,int k,vector<int>&arr,vector<int>&dp){
        int n=arr.size();
        if(i==n) return 0;
        if(dp[i]!=-1) return dp[i];
         int maxi=INT_MIN;
         int sum=INT_MIN;
         int len=0;
        for(int j=i;j<min(n,i+k);j++){
             len++;
             maxi=max(maxi,arr[j]);

            int cost=maxi*len+findmax(j+1,k,arr,dp);
            sum=max(sum,cost);
        }
        return dp[i]=sum;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n=arr.size();
        vector<int>dp(n,-1);
        return findmax(0,k,arr,dp);
    }
};

tabulation meathod
int maximumSubarray(vector<int> &arr, int k){
    // Write your code here.
    int n=arr.size();
     vector<int>dp(n+1,0);
        for(int i=n-1;i>=0;i--){
            int maxele=INT_MIN;
            int l=0;
            int maxsum=INT_MIN;
            for(int j=i;j<min(n,i+k);j++){
                l++;
                maxele=max(maxele,arr[j]);
                int cost=maxele*l+dp[j+1];
                maxsum=max(maxsum,cost);
            }
            dp[i]=maxsum;
        }
        return dp[0];
}
