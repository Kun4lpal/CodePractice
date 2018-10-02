bool checkUnique(vector<int> v){
	//use map
	//iterate and return true if value already exists
	int bitvec = 0;
	for(int i=0;i<v.size();i++){
		if(bitvec & (1<<v[i]) >0)
			return false;
		bitvec |= 1<<v[i];
	}
	return true;
}
//<-------------------------------------------------------------------------------------------------------->
bool checkPermutation(string s1,string s2){
	if(comparelength(s1,s2))return false;
	char arr[26];
	for(int i=0;i<s1.length;i++){
		arr[s1[i]-'a']++;
	}

	for(int i=0;i<s2.length;i++){
		arr[s2[i]-'a']--;		
	}
	for(auto it: arr){
		if(it!=0)
			return false;
	}
	return true;
}
//<-------------------------------------------------------------------------------------------------------->
// "My John Smith   ", 13
//replace spaces with %20;
string URLify(string str, int val){
	return ""
}
//<-------------------------------------------------------------------------------------------------------->
string palindromePermutation(string str){
	char arr[26];
	int countOdd = 0;
	for(auto it:str){
		arr[it-'a']++;		
		(arr[it-'a']%2==0)?countOdd++:countOdd--;
	}
	return countOdd<=1;
}
//<-------------------------------------------------------------------------------------------------------->
bool oneWay(string s1,string s2){
	//assuming s1 is greater length;
	int index1=0,index2=0;
	bool once = false;
	while(index1!=s1.length() && index2!=s2.length()){
		if(s1[index1] != s2[index2]){
			if(once){
				return false;
			}		
			once = true;
			if(s1.length() == s2.length()){index2++;}
		}else{
			index2++;
		}				
		index1++;
	}
	return true;
}
//<-------------------------------------------------------------------------------------------------------->
string stringCompression(string str){

}
//<-------------------------------------------------------------------------------------------------------->
void rotateMatrix(vector<vector<int>> grid){
	int m = grid.size();
	int a = 0;
	int b = m-1;	
	while(a<b){
		for(int i=0;i<b-a;i++){
			swap(grid[a][a+i],grid[a+i][b]);
			swap(grid[a][a+i],grid[b][b-i]);
			swap(grid[a][a+i],grid[b-i][a]);
		}
		a++;
		b--;
	}	
}
//<-------------------------------------------------------------------------------------------------------->
void zeroMatrix(vector<vector<int>> v){
	//set row[0] as 0 if 0 found
	//set col[0] as 0 if 0 si found
	// then reset col and row depending on zeroes
}
//<-------------------------------------------------------------------------------------------------------->
bool stringRotation(string s1,string s2){
	return s2.substr(s1+s1);
}
//<-------------------------------------------------------------------------------------------------------->