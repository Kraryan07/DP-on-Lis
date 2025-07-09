#include<bits/stdc++.h>
int longestBitonicSubsequence(vector<int>& arr, int n)
{
	// Write your code here.
	vector<int>dp(n,1);
	for(int i=0;i<n;i++){
		for(int j=0;j<i;j++){
			if(arr[i]>arr[j] && dp[i]<dp[j]+1){
				dp[i]=dp[j]+1;
			}
		}
	}

	vector<int>dp2(n,1);
	int maxi=0;
	for(int i=n-1;i>=0;i--){
		for(int j=n-1;j>i;j--){
			if(arr[i]>arr[j] && dp2[i]<dp2[j]+1){
				dp2[i]=dp2[j]+1;
			}
		}
		maxi=max(maxi,dp[i]+dp2[i]-1);
	}
	return maxi;
}
