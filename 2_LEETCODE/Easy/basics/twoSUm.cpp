vector<int> twoSum(vector<int>& nums, int target) {    
        unordered_map<int,int> map;
        for(int i=0;i<nums.size();i++){
            if(map.find(target-nums[i])!=map.end()){
                vector<int> vec;
                if(i<map.find(target-nums[i])->second){
                    vec.push_back(i);
                    vec.push_back(map.find(target-nums[i])->second);    
                }else{
                    vec.push_back(map.find(target-nums[i])->second);
                    vec.push_back(i);    
                }
                
                return vec;
            }
            map[nums[i]] = i;
        }
        return vector<int>();
}