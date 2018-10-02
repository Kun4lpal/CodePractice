 vector<int> countBits(int num) {
        vector<int> dp(num+1);
        dp[0] = 0;
        dp[1] = dp[0]+1;
        for(int i=2;i<dp.size();i++){
             if(i%2==1)
                dp[i] = (dp[i-1]+1);
             else
                dp[i] = (dp[i/2]);
        }
        return dp;
}