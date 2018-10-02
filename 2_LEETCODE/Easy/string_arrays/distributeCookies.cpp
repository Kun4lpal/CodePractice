//  Assume you are an awesome parent and want to give your children some cookies. 
//  But, you should give each child at most one cookie. 

//  Each child i has a greed factor gi, which is the minimum size of a cookie that the child will be content with; 
//  and each cookie j has a size sj. If sj >= gi, we can assign the cookie j to the child i, 
//  and the child i will be content. 

//  Your goal is to maximize the number of your content children and output the maximum number.

// Note:
// You may assume the greed factor is always positive.
// You cannot assign more than one cookie to one child. 

int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        if(s.size()==0 || g.size()==0) return 0;
        int j=0;
        int count =0;
        bool val;
        for(int i=0;i<g.size();i++){
            val = false;
            while(j<s.size()){
                if(g[i] <= s[j]){
                    count++;
                    val = true;
                }
                j++;
                if(val)break;            
            }
        }
        return count;
    }