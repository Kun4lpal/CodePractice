bool isAnagram(string s, string t) {
        if(s.size()!=t.size())
            return false;
        int chCount[26]={0};
        for(int i=0;i<s.size();i++){
            chCount[s[i]-'a']++;
            chCount[t[i]-'a']--;
        }
        for (int i=0;i<26;i++){
            if(chCount[i]!=0)
                return false;
        }
        return true;
    }