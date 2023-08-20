//Link - https://www.codingninjas.com/studio/problems/printing-longest-increasing-subsequence_8360670?leftPanelTab=0

vector<int> printingLongestIncreasingSubsequence(vector<int> nums, int n) {

        vector<int> dp(n, 1), hash(n);
        int maxi = 1;
        int lastidx = 0;
        for(int i=0; i<n; i++){
            hash[i] = i;
            for(int prev=0; prev<i; prev++){
                if(nums[i] > nums[prev] and dp[i] < 1 + dp[prev]){
                    dp[i] =  1 + dp[prev];
                    hash[i] = prev;
                }
            }
            if(dp[i] > maxi){
                maxi = dp[i];
                lastidx = i;
            }
        }

        vector<int> temp;
        temp.push_back(nums[lastidx]);
        while(hash[lastidx] != lastidx){
            lastidx = hash[lastidx];
            temp.push_back(nums[lastidx]);
        }
        reverse(temp.begin(),temp.end());
        
        return temp;
}
