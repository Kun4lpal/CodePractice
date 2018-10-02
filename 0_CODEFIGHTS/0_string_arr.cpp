#include <string>
#include <iostream>
#include <vector>

using namespace std;

// array contains numbers only in the range 1 to n
int firstDuplicate(vector<int> vec){
	for(int i=0;i<vec.size();i++){
		int t = abs(vec[i]);
		if(vec[t-1]<0){
			return t;
		}
		vec[t-1] *= -1;		
	}
	return -1;
}

int firstNotRepeatingCharacter(string s){
	int len = s.length();
	for(int i=0;i<s.length();i++){
		if(s.find_first_of(s[i])==s.find_last_of(s[i])){
			return s[i];
		}
	}
	return '_';
}

vector<vector<int>> rotateImage(vector<vector<int>> a){
	int m = a.size();
	int a1 = 0;
	int b1 = m-1;
	while(a1<b1){
		for(int i=0;i<(b1-a1);i++){
			swap(a[a1][a1+i],a[a1+i][b1]);
			swap(a[a1][a1+i],a[b1][b1-i]);
			swap(a[a1][a1+i],a[b1-i][a1]);
		}
		++a1;
		--b1;
	}
	return a;
}


bool sudoku(vector<vector<char>> grid){
	// we can use a  vector of bitvectors as well
	vector<vector<bool>> row(9,vector<int>(9,false));	
	vector<vector<bool>> column(9,vector<int>(9,false));
	vector<vector<bool>> block(9,vector<int>(9,false));
	for(int i=0;i<9;i++){
		for(int j=0;j<9;j++){
			if(grid[i][j]!='.'){
				int num = (grid[i][j]-'0'-1); int k = (i/3)*3+(j/3);
				if(row[i][num] || col[j][num] || block[k][num]){					
					return false;
				}
				row[i][num] = true; col[j][num] = true; block[j][num] = true;
			}
		}
	}
	return true;
}

// word1 + word2 = word3

bool isCryptSolution(std::vector<std::string> crypt, std::vector<std::vector<char>> solution){
    unordered_map<char,char> map;
    for(int i=0;i<solution.size();i++){
        map[solution[i][0]] = solution[i][1];
    }
    vector<string> nums;
    for(int i=0;i<crypt.size();i++){
        string cur = "";
        for(int j=0;j<crypt[i].length();j++){
            cur += map[crypt[i][j]];            
        }
        if(cur[0]=='0' && cur.length()>1)
            return false;
        nums.push_back(cur);
    }
    return stol(nums[2]) == (stol(nums[1]) + stol(nums[0]));
}
