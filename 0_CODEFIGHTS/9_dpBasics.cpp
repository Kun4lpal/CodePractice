int climbingStairs(int n){
	vector<int> dp(n+);
	dp[0] = 1;
	dp[1] = 2;	
	for(int i=2;i<n;i++){
		dp[i] = dp[i-1]+dp[i-2];
	}
	return dp[n-1];
}
//<-------------------------------------------------------------------------------------------------------->
int houseRobber(vector<int> nums){
	if(nums.size()==0) return 0;
	else if(nums.length()==1) return nums[0];
	else if(nums.length()==2) return max(nums[0],nums[1]);

	int res = INT_MAX;
	vector<int> dp(nums.size());
	dp[0] = nums[0];
	dp[1] = max(nums[0],nums[1]);
	for(int i=2;i<dp.size();i++){
		dp[i] = max(dp[i-1],dp[i-2]+nums[i]);
	}
	return dp[nums.size()-1];
}	

int tryRob(TreeNode* root, int& l, int& r) {
        if (!root)
            return 0;            
        int ll = 0, lr = 0, rl = 0, rr = 0;
        l = tryRob(root->left, ll, lr);
        r = tryRob(root->right, rl, rr);
        
        return max(root->val + ll + lr + rl + rr, l + r);
}

int rob(TreeNode* root) {
        int l, r;
        return tryRob(root, l, r);
}
//<-------------------------------------------------------------------------------------------------------->

std::vector<std::string> composeRanges(std::vector<int> nums) {
    if (nums.empty()) return {};
    int p = nums[0];
    int k = nums[0];
    vector<string> r;
    for (int i = 1; i < nums.size(); ++i) {
        if (nums[i] == k + 1) {
            k++;
        } else {
            if (p == k) {
                r.push_back(to_string(p));
            } else {
                r.push_back(to_string(p) + "->" + to_string(k));
            }
            p = nums[i];
            k = nums[i];
        }
    }
    if (p == k) {
                r.push_back(to_string(p));
            } else {
                r.push_back(to_string(p) + "->" + to_string(k));
            }
    return r;
}
//<-------------------------------------------------------------------------------------------------------->

int mapDecoding(String message) { // 123 - > 3 ways => 1,2,3 || 12,3 || 1,23
    int prev = 0, count = 0, curr = 1;    
    for (int i = 0; i < message.length(); i++) {           
        // We set the digit and the number if we are after indice 0
        int digit = message.charAt(i) - 48;
        int number = 0;
        if(i > 0) number = (message.charAt(i - 1) - 48) * 10 + digit;        
        // if the current digit is valid as well, we keep the current total
        if(digit > 0) count = curr;            
        // And if the number is within the boundaries we also add the previous 
        // number of possibilities
        // number > 9 check if the previous digit was not 0
        if(number <= 26 && number > 9) count += prev;            
        // Here count will be 0 if there is no possibility to have proper numbers with 0
        // Therefore all the variables will be set to 0, there is no solution
        // We save the previous number of possibilities
        prev = curr;        
        // We calculate the current total using the modulo as asked
        curr = count % 1000000007;            
        // We set back to 0 to check the new digits
        count = 0;     
    }
    return curr;
}
//<-------------------------------------------------------------------------------------------------------->
//given a 4xn block, how many ways can you fill it?
int fillingBlocks(int n){    
    int[] dp = new int[n+1];
        dp[0] = 1;        
        for(int i=1;i<=n;i++){            
            if (i==1){
                dp[i] = 1;
            }else if (i==2){
                dp[i] = 5;
            }else if (i==3){
                dp[i] = 11;
            }
            else{                                   
                    dp[i] = dp[i-1] + (5*dp[i-2]) + dp[i-3] - dp[i-4];                    
            }
        }
        return dp[n];
}