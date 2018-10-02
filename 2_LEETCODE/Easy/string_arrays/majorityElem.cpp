// Given an array of size n, find the majority element. The majority element is the element that 
// appears more than ⌊ n/2 ⌋ times.

// You may assume that the array is non-empty and the majority element always exist in the array.



int majorityElement(vector<int>& nums) {
        unordered_map<int,int> map;
        int n = nums.size();
        for(int x:nums){
            map[x]++;
        }
        for(pair<int,int> x: map){
            if (x.second > n/2) return x.first;
        }
        return int();
  }