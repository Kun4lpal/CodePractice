
//  Given an array of integers and an integer k, you need to find the number of unique k-diff pairs in the array. 
//  Here a k-diff pair is defined as an integer pair (i, j), where i and j are both numbers in the array 
//  and their absolute difference is k.

// Example 1:

// Input: [3, 1, 4, 1, 5], k = 2
// Output: 2
// Explanation: There are two 2-diff pairs in the array, (1, 3) and (3, 5).
// Although we have two 1s in the input, we should only return the number of unique pairs.


 int findPairs(vector<int>& nums, int k) {
         if (k < 0) {
            return 0;
        }
        unordered_set<int> starters;
        unordered_map<int, int> indices;
        for (int i = 0; i < nums.size(); i++) {
            if (indices.count(nums[i] - k)) {
                starters.insert(nums[i] - k);
            }
            if (indices.count(nums[i] + k)) {
                starters.insert(nums[i]);
            }

            indices[nums[i]] += 1;
        }
        
        return starters.size();
    }