//Write a function to find the longest common prefix string amongst an array of strings. 

string longestCommonPrefix(vector<string>& strs) {
       
    if(strs.size() < 1) return "";    
    int tag = 0;
	for (int i = 0; i < strs.size(); ++i)
	{
		if (strs[i].size() < tag){
			tag = i;
		}
	}

	string re;
	for (int i = 0; i < strs[tag].size(); ++i){
		char c = strs[tag][i];
		for (int j = 0; j < strs.size(); ++j){
			if (strs[j][i] == c){
				continue;
			}else{
				return re;
			}
		}
        re.push_back(c);
	} 
    return re;    
}