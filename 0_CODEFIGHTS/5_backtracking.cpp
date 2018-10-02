//<-------------------------------------------------------------------------------------------------------------->
// 2 : can take upto k steps at a time

vector<vector<int>> climbingStaircase(int n, int k){
	vector<vector<int>> result;
	vector<int> temp;
	findWays(result,temp,n,k);
    return result;
}

void findWays(vector<vector<int>> &result,vector<int> &temp,const int target, int k){ 
    if(target<0){
        return;
    }
	if(target==0){                
        result.push_back(temp);                 
    }else{
        for(int i=1;i<=k;i++){//here we use 1 instead of order because we can use it any number of times
            if(target-i>=0){
                temp.push_back(i);            
		        findWays(result,temp,target-i,k);
		        temp.pop_back();
            }		
	    }
    }			
}

//<-------------------------------------------------------------------------------------------------------------->
// 3 : Place NQueens
std::vector<std::vector<int>> nQueens(int n){
    vector<vector<int>> results;
    vector<int> temp(n,0); // temp index corresponds to row and j corresponds to column
    findPaths(0,results,temp,n);
    return results;
}
void findPaths(int row, vector<vector<int>> &results, vector<int> &temp, int n){
    if(row == n){
        results.push_back(vector<int>(temp));           
    }else{
        for(int i=1;i<=temp.size();i++){
            if(isValid(row,i,temp)){
                temp[row] = i;
                findPaths(row+1,results,temp,n);            
            }
        }
    }
}

bool isValid(int row, int col, vector<int> temp){
    for(int r=0;r<row;r++){ // check if any preceeding row has a column value which makes this place invalid
        int c = temp[r];
        if(c==col) return false;
        int cd = abs(c-col);
        int rd = abs(r-row);
        if(cd==rd) return false;
    }
    return true;
}
//<-------------------------------------------------------------------------------------------------------------->
// 4 : Find all possible combinations in lexographical order

std::vector<std::vector<int>> sumSubsets(std::vector<int> arr, int num) {
    vector<vector<int>> results;
    sort(arr.begin(),arr.end());
    vector<int> temp;        
    for(auto it:arr){cout<<it<<" ";}
    findSubsets(results,temp,arr,0,num);
    return results;
}

void findSubsets(vector<vector<int>> &results, vector<int> &temp, const vector<int> &arr,
                 const int order,const int target){    
    if(target==0){//<-------------------------------------------------------------------------------------------------------------->
        results.push_back(temp);
        return;
    }else{
        for(int j=order;j<arr.size();j++){
            if(arr[j]>target) return;
            if( j && arr[j-1]==arr[j] && j>order) continue;
            temp.push_back(arr[j]);
            findSubsets(results,temp,arr,j+1,target-arr[j]);
            temp.pop_back();
        }
    }
}                
//<-------------------------------------------------------------------------------------------------------------->