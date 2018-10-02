// Given a sorted array nums, remove the duplicates in-place such that each element appear only once and return the new length.

// Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1) extra memory.

int removeDuplicates(vector<int>& A) {
        int count = 0;
        int n = A.size();
        for(int i = 1; i < n; i++){
            if(A[i] == A[i-1]) count++;
            else A[i-count] = A[i];
        }
        return n-count;
    }