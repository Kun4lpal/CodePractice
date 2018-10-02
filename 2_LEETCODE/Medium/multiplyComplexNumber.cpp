string complexNumberMultiply(string a, string b) {
        istringstream sa(a),sb(b);        
        int r1,c1,r2,c2;
        string mid = "";
        char s1,s2;           
        sa>>r1;
        sa>>s1;        
        sa>>c1;
        mid = s1=='+'?"+":"-";        
        sb>>r2;
        sb>>s2;
        sb>>c2;        
        int r = r1*r2-(c1*c2);
        int c = r1*c2+c1*r2;                
        return to_string(r)+mid+to_string(c)+'i';
}