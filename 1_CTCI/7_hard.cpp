//1) Add without plus
int add(int a,int b){
	if(b==0) return a;
	int sum = a^b;
	int carry = (a&b)<<1;
	return add(sum,carry);
}

int add(int a,int b){
	while(b!=0){
		int sum =a^b;
		int carry = (a&b)<<1;
		a=sum;
		b=carry;
	}
	return a;
}
//<---------------------------------------------------------------------------------------------------->
vector<int> shuffle(vector<int> arr,int i){ // i = arr.size() at the beginning
	if(i==0) return arr;
	shuffle(arr,i-1);
	int k = rand()%i;
	swap(arr[k],arr[i]);
	return arr;
}
//<-------------------------------------------------------------------------------------------------------->
void shuffle(vector<int> arr){
	for(int i=0;i<arr.size();i++){
		int k = rand()%i;
		swap(arr[i],arr[k]);
	}
}
//<---------------------------------------------------------------------------------------------------->
int kthMagicNumber(int k){ // kth number with 2,5,7 as factors, great way to build numbers we want
	if(k<0) return 0;
	int val=0;
	queue<int> q3;
	queue<int> q5;
	queue<int> q7;
	q3.push(1);
	for(int i=0;i<k;i--){
		int v3 =  q3.size()?q3.top():INT_MAX;//we dont pop we just peek
		int v5 =  q5.size()?q5.top():INT_MAX;
		int v7 =  q7.size()?q7.top():INT_MAX;
		val = min(v3,min(v5,v7));
		if(val==v3){
			q3.pop();
			q3.push(val*3);
			q5.push(val*5);
		}else if(val==v5){
			q5.pop();
			q5.push(val*5);
		}else if(val==v7){
			q7.pop();
		}
		q7.push(val*7);
	}
	return val;
}
//<---------------------------------------------------------------------------------------------------->
// 1 2 5 9 5 9 5 5 5
int majorityElement(vector<int> arr){	
	int count=0,major=0;
	for(auto it:arr){
		if(count==0) major=it;
		if(it==major) count++;
		else if(it!=major) count--;
	}
	return validate(major)?major:-1;
}

//<---------------------------------------------------------------------------------------------------->
//3,4,6
//5,10,22
//now find pair with min diff
//optimize by check if key is avaliable and then find val nearest to the point 1

vector<int> findMin(vector<int> arr1, vector<int> arr2){
	int index1=0,index2=0;
	vector<int> v{arr1[index1],arr2[index2]};
	int diff = abs(arr1[index1]-arr2[index2]);
	while(index1<arr1.size() && index2<arr2.size()){
		diff = min(diff,abs(arr1[index1]-arr2[index2]));
		if(arr1[index1]>arr2[index2]){
			index2++;
		}else{
			index1--;
		}
	}
	return diff;
}
//<---------------------------------------------------------------------------------------------------->
//BiNode can be use to reperesent a binary tree or a doubly linked list
BiNode convert(BiNode bin){
	Binode left = convert(bin->left);
	BiNode right = convert(bin->right);
	mergeLists(left,bin,right);
	return left;
}
//<---------------------------------------------------------------------------------------------------->
//Selection rank better than heap sort
int findKthSmallest(vector<int> arr, int k){	
	return rank(arr,0,arr.size()-1,k);
}
// whats different in this partition method is that we are performing swaps only if values found in the wrong side
int rank(vector<int> arr, int l, int r, int k){
	int pivot = l+ rand()%(r-l/2);
	int leftEnd = parition(arr,l,r,pivot);//leftIndex is the index after which all values are greater than pivot
	// Note: partitioning will be harder in case of repitions. In that case we have middle index as well which we 
	// increase as we find values equal to arr[middle]
	int leftsize = leftEnd - l + 1;
	if(rank==leftsize-1){
		return max(arr,l,leftEnd);
	}else if(rank<leftsize){
		return rank(arr,l,leftEnd,rank);
	}else{
		return rank(arr,l+1,leftEnd,rank-leftsize);
	}
}

//After getting this Kth value we can find the rest as they are less than the kth element.
//<---------------------------------------------------------------------------------------------------->
//q) print longest word in arr that can be build using other words
string printLongestWord(vector<string> arr){
	map<string,bool> map;
	for(auto it: arr){map[it]=true;}
	sort(arr.begin(),arr.end());
	for(auto str:arr){
		if(canbuildArray(str,true,map)){
			return s;
		}
	}
	return "";
}

bool canbuildArray(string str, bool original, map<string,bool> &map){
	if(map.find(str)!=map.end()){
		return map[str];
	}
	for(int i=0;i<str.length();i++){
		string left = str.substr(0,i);
		string right = str.substr(i);
		if(map.find(left)!=map.end() && map[left] && canbuildArray(right,false,map)){
			return true;
		}
	}
	map[str]=false;
	return false;
}


//<---------------------------------------------------------------------------------------------------->
//q) allocate max time for schedules

int maxMinutes(vector<int> massages){
	int memo[] = new int[massages.size()+2];
	memo[massages.size()]=0;
	memo[massages.size()+1]=0;
	for(int i=massages.size()-1;i>=0;i--){
		int bestWith = massages[i]+memo[i+2];
		int bestWithout = memo[i+1];
		memo[i] = max(bestWithout,bestWith);		
	}
	return memo[0];
	// we can optimized this by using only two integers to track last 2
}

//<---------------------------------------------------------------------------------------------------->
// q)
// search locations of strings inside an array of strings inside a word - We can use a trie or hashmap here
//<---------------------------------------------------------------------------------------------------->
// q)
// find shortest subsequence in longer array with all numbers in shorter array
// vector<int> short;
// vector<int> longer;
// 
// My approach: Find the indexes at which they ocuur and find the minimum range

string findShortest(vector<int> short, vector<int> long){
	return "";
}

string findShortestRange(unordered_map<int,set<int>> map){
	// the index values are already sorted
}

//<---------------------------------------------------------------------------------------------------->
// q)

// Find missing number from 1 to n;
// find sum of n and subract it with the current sum, the difference is the missing number
// find two missing numbers =>
// x+y = sum, x^2 + y^2 = t;
// y=sum-x;
// use this and solve quadratic equation:
// x =  (-b +- (b^2 - 4ac)^(1/2))/2*a;


//<---------------------------------------------------------------------------------------------------->
// q)
int continousMedian(int n){
	// n is passed to a list here and we need to maintain the median
	// build a max heap and min heap. 
	// if n> maxHeap.size()== minHeap.size() {return average of two tops}
	// else return maxHeap.top();
}
//<---------------------------------------------------------------------------------------------------->
// q)
int computeHistogramVol(vector<int> histo){
	vector<int> leftMax(histo.size()),rightMax(histo.size()),minDelta(histo.size());
	int lm=0;
	for(int i=0;i<histo.size();i++){
		lm = max(lm,histo[i]);
		leftMax[i] = lm;
	}
	int sum=0;
	int rm=0;	//do same for rightMax

	for(auto it=0;it<histo.size();it++){
		int sec = min(leftMax[i],rightMax[i]);
		if(sec>histo[i])
			sum+=sec-histo[i];
	}
	return sum;
}
//<---------------------------------------------------------------------------------------------------->
// q) Word transformation
	// WORD1->word2
	// string of words in middle
// use bfs here
int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
	unordered_set<string> s;
	for(auto it:wordList){
		s.insert(it);
	}
	if(s.find(endWord) == s.end()) return {};
	unordered_set<string> head({beginWord}), tail({endWord});        
    // if the current head is the starting head, reverse is false, otherwise true
    bool reverse = false, finish = false;
    // delete begin and end words from the set s since we don't want to find them as a "neighbor" 
    s.erase(beginWord); s.erase(endWord);
    int count = 2;
    while (!head.empty() && !tail.empty() && !finish){
    	if (head.size() > tail.size()) {
    		reverse = !reverse;
    		swap(head, tail);                
    	}            
    	unordered_set<string> temp;            
    	for (auto item : head){
    		for (int l = 0; l < item.size(); ++l){
    			string ori = item;             
    			for (char c = 'a'; c <= 'z'; ++c){ 
    				item[l] = c;
    				if (tail.find(item) != tail.end()) {                            
    					finish = true;
    					return count;
    				}
    				else if (s.find(item) != s.end()){
    					temp.insert(item);                                        
    				}
    			}
    			item = ori;
    		}
    	}
    	for (auto item : temp){
    		s.erase(item); // removing items form the unordered_list
    	}
    	count++;
    	head = temp;
    }
    return 0;        
}

//<---------------------------------------------------------------------------------------------------->
// in this solution we return the path
void backtrack(vector<vector<string>> &ret, unordered_map<string, unordered_set<string>> &backtrace, 
	vector<string> &temp, string endWord, string beginWord){
        if (endWord == beginWord){
            vector<string> rev = temp;
            reverse(rev.begin(), rev.end());
            ret.push_back(rev);
            return;
        }        
        // we are backtracing to all possible paths from backword to beginword
        // Note this is very similar to the matrix problem where we want to find path from NxN to 0X0
        // In the matrix question are possibilites are governed by 0 and 1s (allowed blocks)
        for (auto item : backtrace[endWord]) {
            temp.push_back(item);
            backtrack(ret, backtrace, temp, item, beginWord);
            temp.pop_back();
        }
}    

/*
    Idea :
    1. use two-end bfs to iteratively find the shortest path
    2. use a map of [nextNode, curNodeList] to record all possible paths to the nextNode for the purpose of backtracing
    3. use a boolean to represent the end of bfs, a boolean to represent the swap of head and tail
    4. use dfs to recursivlely backtrace
    
    Caution and more ideas : see comments
*/
vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> s;
        for (auto item : wordList)
        {
            s.insert(item);
        }
        // if the endWord is not in the wordList
        if (s.find(endWord) == s.end()) return {};
        // record all possible paths from the current node to the next node for the purpose of backtracing
        unordered_map<string, unordered_set<string>> backtrace; // GRAPH Adjacency lists
        unordered_set<string> head({beginWord}), tail({endWord});
        // if the current head is the starting head, reverse is false, otherwise true
        bool reverse = false, finish = false;
        // delete begin and end words from the set s since we don't want to find them as a "neighbor" 
        s.erase(beginWord); s.erase(endWord);
        while (!head.empty() && !tail.empty() && !finish)
        {
            // two-end bfs : swap head and tail to reach balance of two sets for optimized performance
            if (head.size() > tail.size()) 
            {
                reverse = !reverse;
                swap(head, tail);
            }
            // temp will contain neighbors of the current level nodes
            unordered_set<string> temp;
            for (auto item : head)
            {
                for (int l = 0; l < item.size(); ++l) 
                {
                    string ori = item;
                    // O(26 * size of item)
                    for (char c = 'a'; c <= 'z'; ++c)
                    {
                        item[l] = c;
                        if (tail.find(item) != tail.end()) 
                        {
                            if (!reverse) backtrace[item].insert(ori);// item here is the next step and orignal is ori
                            else backtrace[ori].insert(item);
                            finish = true;
                        }
                        else if (s.find(item) != s.end())
                        {
                            temp.insert(item);
                            if (!reverse) backtrace[item].insert(ori);
                            else backtrace[ori].insert(item);
                        }
                    }
                    item = ori;
                }
            }
            // only delete items after we finish iterating the current level
            // if we delete while iterating, it is possible that we delete a node which has two sources to reach it
            for (auto item : temp)
            {
                s.erase(item);
            }
            head = temp;
        }
        
        vector<vector<string>> ret;
        vector<string> temp({endWord});
        backtrack(ret, backtrace, temp, endWord, beginWord);
        
        return ret;
 }


//<---------------------------------------------------------------------------------------------------->
 //q)

// find possible square with grids
// we transfrom the grid to a matrix with 
// max possible square size is n for NxN matrix. Then we find all possible square at each node
 // we look at the two corenrs and compare the length with size of current possible square
0 1 0   	00 13 00
1 1 0 		22 12 00
1 1 0 		21 11 00

//<---------------------------------------------------------------------------------------------------->
 //q)
vector<vector<int>> maxSubMatrix(vector<vector<int>> M){
	//build arrays of all a continuous sequence of rows and columns
	//we have row start, row end, col start, col end
}

// we find sums for each row start and row end && column start and column end

//-1,2,3,-1

int maxSumbarrySum(vector<int> arr){
	int maxGlobal=arr[0],maxLocal=arr[0];
	for(int i=1;i<arr.size();i++){
		maxLocal = max(arr[i],arr[i]+maxLocal);
		maxGlobal = max(maxLocal,maxGlobal);
	}
	return maxGlobal;
}

//<---------------------------------------------------------------------------------------------------->
 //q)
// find list of words that can form a rectangle
// First we do some pre processing and group words based on their sizes
// Now we can check if the words in vertical direction make sense in horizontal ordering and vice versa
// We can make use of a trie to check for valid words.

// Also we know the max length and height of the rectangle
// So we try to form all possible rectangles of a specific length or height and we start from max
//<---------------------------------------------------------------------------------------------------->
//q)
// Find intersection across documents
DOC: ITEMS
12: {1, 5, 9}
13: {5, 3, 1, 8}
14: {4, 3, 2}
15: {1, 5, 9, 8}
17: {1, 6}

Hash table with all common items;
int 1 has is available in the following docs
we just increase the count of pair 12,13 
1 -> {12, 13, 15, 17}
5 -> {12, 13, 15}
9 -> {12, 15}

Then we just build pairs with same common values, track commons in each pair;