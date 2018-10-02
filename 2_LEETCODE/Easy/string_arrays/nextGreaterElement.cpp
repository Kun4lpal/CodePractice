 vector<int> nextGreaterElement(vector<int>& findNums, vector<int>& nums) {
      vector<int> stack;
      stack.reserve(nums.size());
      unordered_map<int,int> gt;
      if (nums.size()) stack.push_back(*nums.begin());
      
      for (auto i = 1; i < nums.size(); ++i) {
          cout<<"i: "<<i<<" ";
          while (stack.size() && nums[i] > stack.back()) {
              int val = stack.back();
            gt[val] = nums[i];
            cout<<"gt: "<<val<<":"<<nums[i]<<" ";
            stack.pop_back();
          } 
          stack.push_back(nums[i]);
      }
      
      while(stack.size()) {
            gt[stack.back()] = -1;
            stack.pop_back();
      }
      
      for (auto & i : findNums) {
        i = gt[i];
      }
            return findNums;        
}