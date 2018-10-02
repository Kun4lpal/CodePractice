//Q1
int combinationSteps(int n){
	if(n<0){
		return 0;
	}else if(n==1){
		return 1;
	}
	return combinationSteps(n-1)+combinationSteps(n-2)+combinationSteps(n-3);
}
//<-------------------------------------------------------------------------------------------------------->
//Q2
// instead of starting from the top we start from bottom

int main()
{
  std::vector<std::pair<int, int>> v = {{1,2}, {3,4}, {5,6}};
  auto p = std::make_pair(3, 4);
 
  if(std::find(v.begin(), v.end(), p) != v.end())
      std::cout << "yes\n";
}

vector<vector<int>> findPathGrid(vector<vector<int>> grid){
	vector<vector<int>> result;
	unordered_set<Point> failedPoints;
	if(findG(grid,grid.size(),grid[0].size(),failedPoints)){
		return result;
	}
	return NULL;
}

bool findG(vector<vector<int>> &grid,vector<vector<int>> &result, int i, int j,unordered_set<pair<int,int>> failedPoints){
	if(i<0 && i>=grid.size() && j<0 && j>=grid[0].size() && grid[i][j]!=0){
		return false;
	}
	if(failedPoints.find({i,j})!=failedPoints.end()){return false;}
	if(i==0 && j==0 || findG(grid,i,j-1,result,failedPoints) || findG(grid,i-1,j,result,failedPoints)){		
		result.push_back(vector<int>({i,j}));		
		return true;
	}
	failedPoints.insert(vector<int>{i,j});
	return false;
}
//<-------------------------------------------------------------------------------------------------------->
//Q3
//distinct integers
int findMagicIndex(vector<int> arr){
	return findM(arr,0,arr.size());
}

int findM(vector<int> arr, int l, int r){
	int mid = (l+r)/2;
	if(arr[mid]>mid){
		return findM(arr,l,mid);		
	}else if(arr[mid]<mid){
		return findM(arr,mid,r);
	}
	return mid;
}
//<-------------------------------------------------------------------------------------------------------->
//Q4
// it will start from index = 0 and then go towards n-1. When it reaches the end it is the base cae 
// this is where we add the empty block
vector<vector<int>> findSubSets(vector<int> arr, int index){
	//we can do this iteratively as well by starting with empty vector and then including the val at i=0 to all
	// subsets before it and adding them together with the main
	std::vector<std::vector<int>> result;
	if(arr.size() == index){
		std::vector<int> v;
		result.push_back(v);
	}else{
		result = getSubSets(arr,index+1);
		int item = arr[index];
		for(auto it: result){
			std::vector<int> temp(it);
			it.push_back(item);
			result.push_back(temp);
		}
	}
	return result;
}
//Solution 2: if n is the total items there are 2^n possible combinations
// for(int i=0; i< 2^n;i++) {operation(i);}
//<-------------------------------------------------------------------------------------------------------->
//Q5) 
// INCLUDE memotization by using vector<int> m(a+1);
int multiply(int a,int b,std::vector<int> memo){
	if(a==0) return 0;
	else if(a==1) return b;
	else if(memo[a]>1) return memo[a];
	int as = a>>1;
	int side1 = multiply(as,b,memo);
	int side2 = side1;
	if(a%2==1){
		side2 = multiply(a-as,b,memo);
	}
	memo[a] = side1+side2;
	return side1 + side2;
}
//<-------------------------------------------------------------------------------------------------------->
// Q6) 
void move(stack<int> source, stack<int> desination, stack<int> buffer,int n){
	if(n<=0)
		return;
	move(source,buffer,desination,n-1);
	move2(source,desination);
	move(buffer,desination,source,n-1);
}
//<-------------------------------------------------------------------------------------------------------->
//Q7) findPermutations
// use unordered_map<char,int> freq; as a freq table
void findPermutations(string s,string prefix,std::vector<int> v){
	if(s.length()==0){
		v.push_back(prefix);
	}else{		
		for(int i=0;i<s.length();i++){			
			string s = s.substr(0,i)+s.substr(i+1,s.length());
			findPermutations(s,prefix+s[i],v);
		}
//<-------------------------------------------------------------------------------------------------------->
		//or do this in case of repitions
		for(auto it: feqTable){			
			int count = feqTable[it.first];
			if(count>0){
				map[it.first]--;				
				findPermutations(map,r-1,prefix+s[i],v);// r = length of main string
				map[it.first]++;
			}			
		}
	}
}
//<-------------------------------------------------------------------------------------------------------->
//Q8)

std::vector<std::vector<int>> generateResults(int count){
	string str = "";
	std::vector<std::vector<int>> result;
	printValidCombinations(0,count,count,result,str);
	return result;
}

// this way is very useful to build other similar strings with rules
void printValidCombinations(int index, int open, int close, 
	vector<string> results, string str){

	if(close>open){
		return;
	}
	if(open==0 && close==0){
		results.push_back(str);
	}else{
		str[index] = '(';
		printValidCombinations(index+1,open-1,close,results,str);
		str[index] = ')';
		printValidCombinations(index+1,open,close-1,results,str);
	}
}
//Q9) <--------------------------------------------------------------------------------------------------->
enum Color {b,w,r,g,y}
bool paintFill(vector<vector<int>> grid, int row, int col, Color ncolor){
	if(grid[row][col]==ncolor){return false;}
	return paintFill(grid,row,col,grid[row][col],ncolor);
}

bool paintFill2(std::vector<std::vector<int>> grid, int r, int c, Color ocolor, Color ncolor){
	if(r<0||r>=grid.size()||c<0|| c>=grid[0].size()){return false;}
	if(grid[r][c] == ocolor){
		grid[r][c] = ncolor;
		paintFill2(grid,r+1,c,ocolor,ncolor);
		paintFill2(grid,r,c+1,ocolor,ncolor);
		paintFill2(grid,r,c-1,ocolor,ncolor);
		paintFill2(grid,r-1,c,ocolor,ncolor);
	}
	return true;
}


<--------------------------------------------------------------------------------------------------->
//Q10) total number of combinations that make that amount
// here we can use these denoms any number of times
int makeChange(int denoms[], int n){
	vector<int> v(n+1);
	v[0]=1;
	for(int i=0;i<denoms.size();i++){
		for(int j=0;j<v.size();j++){
			if(denoms[i]>=j){
				v[j] += v[j-denoms[i]];
			}		
		}
	}
	return v[n+1];
}
// total possible ways to reach target n
int makeChange(int n){
	int denoms[] = {25,10,5,1};
	int map[][] = new int[n+1][denoms.length()];
	return make2(n,denoms,0,map);
}

int make2(int n, int denoms[], int index, int map[][]){
	if(amount == 0) return 1;
	if(map[n][index]>0){return map[n][index];}
	if(index==denoms.length()){
		return 0;
	}
	int demomAmount = denoms[index];
	int ways=0;
	for(int i=0;i*demomAmount<=n;i++){
		ways+=make2(n-i*demomAmount,denoms,index+1,map);
	}
	map[n][index] = ways;
	return ways;
}

<--------------------------------------------------------------------------------------------------->
DP solution; maxpossible combinations to reach that sum;

int change(int amount, vector<int>& coins) {        
         if(amount == 0)
            return 1;
        if(coins.size() == 0)
            return 0;
        vector<int> dp(amount + 1, 0);
        dp[0] = 1;
        for(int i = 0; i < coins.size(); ++ i){
            for(int j = coins[i]; j <= amount; ++ j){
                dp[j] += dp[j - coins[i]];
            }
        }
        return dp[amount];  
}

<--------------------------------------------------------------------------------------------------->

DP minpossible coins needed to reach an amount;

int coinChange(vector<int>& coins, int amount) {
        int Max = amount + 1;
        vector<int> dp(amount + 1, Max);
        dp[0] = 0;
        for (int i = 1; i <= amount; i++) {
            for (int j = 0; j < coins.size(); j++) {
                if (coins[j] <= i) {
                    dp[i] = min(dp[i], dp[i - coins[j]] + 1);
                }
            }
        }
        return dp[amount] > amount ? -1 : dp[amount];        
    }

  <--------------------------------------------------------------------------------------------------->
//Q11) 

NQueens

void placeQueens(vector<vector<int>> results, int row, vector<int> cols){
	if(row==8){
		results.push_back(cols);		
	}else{
		for(int col=0;col<8;col++){
			if(checkValid(row,col,cols)){
				cols[row] = col;
				placeQueens(results,row+1,cols);
			}
		}
	}
}


<--------------------------------------------------------------------------------------------------->

//Q12)
// IMPLEMETNT MEMOTIZATION WHERE KEY IS INDEX
int createStack(vector<Box> boxes){
	sort(boxes.begin(),boxes.end(),[](Box a, Box b){return a.h>b.h;});
	int maxHeight = 0;
	for(int i=0;i<boxes.size();i++){ // find max height for a starting base box
		int h = createStack(boxes,i);
		maxHeight = max(h,maxHeight);
	}
	return maxHeight;
}

int createStack(std::vector<Box> boxes,int index){
	Box bottom = boxes[index];
	int mh=0;
	for(int i=index+1;i<boxes.size();i++){
		if(box[index].canBeAbove(bottom)){ // find max height with the bottom box defined
			int h = createStack(boxes,i);
			mh = max(h,mh);
		}
	}
	mh+=bottom.height;
	return mh;
}

<--------------------------------------------------------------------------------------------------->

//q14) boolean evaluation:

//(a&a&a&1A1Ia", true) -> 1a
int countEval(string s,bool result, map<string,int> memo){
	//leftEval & rightEval == result?
	//LeftEval | rightEval == result?
	if(s.length()==0){return 0;}
	if(s.length()==1){return (s[0]-'0')==result?1:0;}
	if(memo.find(result + s)!=memo.end()){return memo[result+s];}

	int ways=0;
	for(int i=1;i<s.length();i+=2){
		char c = s[i];
		string left = s.substr(0,i);
		string right = s.substr(i+1,s.length());
		int leftTrue = countEval(left,true,memo);
		int leftFalse = countEval(left,false,memo);
		int rightTrue = countEval(right,true,memo);
		int rightFalse = countEval(right,false,memo);

		int total = (leftTrue+leftFalse)*(rightTrue+rightFalse);
		int totalTrue = 0;
		if(c=='^'){
			totalTrue = leftTrue*rightFalse + leftFalse*rightTrue;
		}else if(c=='&'){
			totalTrue = leftTrue*rightTrue;
		}else if(c=='|'){
			totalTrue = leftTrue*rightTrue + leftTrue*rightFalse + leftFalse*rightTrue;
		}

		int subWays = result?totalTrue:total-totalTrue;
		ways+=subWays;
	}
	memo[result+s] = ways;
	return ways;
} 
//<-------------------------------------------------------------------------------------------------------->