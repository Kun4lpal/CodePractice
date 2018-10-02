// For example, given the array [-2,1,-3,4,-1,2,1,-5,4],
// the contiguous subarray [4,-1,2,1] has the largest sum = 6. 

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
            int ans=nums[0],i,j,sum=0;
        for(i=0;i<nums.size();i++){
            sum+=nums[i];
            ans=max(sum,ans);
            sum=max(sum,0);
        }
        return ans;
    }
};