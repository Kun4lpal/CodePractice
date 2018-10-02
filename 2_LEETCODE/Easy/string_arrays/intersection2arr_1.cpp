// result should have numbers repeated as many times as the intersection

vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        if(nums1.size()<nums2.size()) return intersect(nums2,nums1);
        if(nums1.size() == 0 || nums2.size() == 0) return res;
        
        unordered_map<int,int> map1;
        unordered_map<int,int> map2;
        for(int a:nums1){
            map1[a]++;
        }
        for(int b:nums2){
            map2[b]++;
        }
        
        for(int i:nums2){
            while(map2[i]){
                if(map1[i] ==0 ){break;}
                else{
                    res.push_back(i);
                    map1[i]--;
                    map2[i]--;
                }
            }
        }
        
        return res;
    }