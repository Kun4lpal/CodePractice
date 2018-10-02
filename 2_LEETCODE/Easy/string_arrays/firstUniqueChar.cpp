 const int firstUniqChar(register string &s) const {
        register int c[26]{};
        for(register int i = 0; s[i]; i++) c[s[i] - 'a']++;
        for(register int i = 0; s[i]; i++) if(c[s[i] - 'a'] == 1) return i;
        return -1;
}


// check if vec contains duplicates

bool containsDuplicate(vector<int>& nums) {
        if(nums.size()<=1) return false;
        sort(nums.begin(), nums.end());
        for(int i=1; i<nums.size(); i++)
        {
            if(nums[i-1]==nums[i])
                return true;
        }
        return false;
    }