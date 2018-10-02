// Given an integer array nums, find the sum of the elements between indices i and j (i ≤ j), inclusive.

// Example:

// Given nums = [-2, 0, 3, -5, 2, -1]

// sumRange(0, 2) -> 1
// sumRange(2, 5) -> -1
// sumRange(0, 5) -> -3


class NumArray {
public:
    NumArray(vector<int> nums) {
        if (!nums.empty()){
            for(vector<int>::iterator i=nums.begin()+1; i!=nums.end(); i++){
                *i=*i+*(i-1);
            }
        }
        total=nums;
    }
    vector<int> total;
    int sumRange(int i, int j) {
        if( !total.empty()){
            if(i==0) return total[j];
            else return total[j]-total[i-1];
        }
        return 0;
    }
};