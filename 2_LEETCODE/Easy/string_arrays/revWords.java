public string ReverseWords(string s) {
        var c = s.ToCharArray();
        
        for (int i = 0, j = 0; i < c.Length; i++) {
            if (i+1 == c.Length || c[i+1] == ' ') {
                var l = j;
                var r = i;
                
                while (l < r) {
                    var temp = c[l];
                    c[l] = c[r];
                    c[r] = temp;
                    l++;
                    r--;
                }
                
                j = i+2;
            }
        }
        
        return new String(c);
}