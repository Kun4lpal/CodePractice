string optimalDivision(vector<int>& nums) {
        if (nums.empty()) return "";
        string ans = to_string(nums[0]);
        if (nums.size() == 1) return ans;
        if (nums.size() == 2) return ans + "/" + to_string(nums[1]);
        for (int i=1; i<nums.size(); i++){
            ans += ((i==1) ? "/(" : "/") + to_string(nums[i]);
            if (i==nums.size()-1) ans += ")";
        }
        return ans;
}