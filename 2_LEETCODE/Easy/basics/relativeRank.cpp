// Given scores of N athletes, find their relative ranks and the people with the top three highest scores, who will 
// be awarded medals: "Gold Medal", "Silver Medal" and "Bronze Medal".


// Input: [5, 4, 3, 2, 1]
// Output: ["Gold Medal", "Silver Medal", "Bronze Medal", "4", "5"]
// Explanation: The first three athletes got the top three highest scores, so they got "Gold Medal", "Silver Medal" and "Bronze Medal". 
// For the left two athletes, you just need to output their relative ranks according to their scores.



class Solution {
public:
    string rankString(int rank) {
        if (rank == 1) return "Gold Medal";
        if (rank == 2) return "Silver Medal";
        if (rank == 3) return "Bronze Medal";
        return to_string(rank);
    }
    
    vector<string> findRelativeRanks(vector<int>& nums) {
        if (nums.size() == 0) return vector<string>();
        
        int m = nums[0];
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > m) m = nums[i];
        }
        
        vector<int> index(m + 1, -1);//m is the max value
        
        for (int i = 0; i < nums.size(); i++) {
            index[nums[i]] = i;// 
        }
        
        vector<string> rank(nums.size());
        int current_rank = 1;
        
        for (int j = index.size() - 1; j >= 0; --j) {
            if (index[j] >= 0) {
                rank[index[j]] = rankString(current_rank);
                current_rank++;
            }
        }
        
        return rank;
    }
};