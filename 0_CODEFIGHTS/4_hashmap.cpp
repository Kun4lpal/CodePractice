
//coins and their corresponding quantities.
//Find all possible sums

// question 1 : try this with the coin change 1 solution where we dont use unordered set but a dp array
int possibleSums(std::vector<int> coins, std::vector<int> quantity) {
     unordered_set<int> p;
     p.insert(0);
     
     for(int i=0; i<coins.size(); ++i) {
          auto tmp = p;
          for(int f=1; f<=quantity[i]; ++f) {
               for(int elt: tmp)
                    p.insert(elt+f*coins[i]);
          }
     }
     return p.size()-1;
}

//Given a string str and array of pairs that indicates which indices in the string can be 
//swapped, return the lexicographically largest string that results from doing the allowed swaps.
//You can swap indices any number of times.

// Example
// For str = "abdc" and pairs = [[1, 4], [3, 4]], the output should be
// swapLexOrder(str, pairs) = "dbca".
// By swapping the given indices, you get the strings: "cbda", "cbad", "dbac", "dbca". 
// The lexicographically largest string in this list is "dbca".
// Input/Output
//     [execution time limit] 3 seconds (cs)
//     [input] string str
//     A string consisting only of lowercase English letters.
//     Guaranteed constraints:
//     1 ≤ str.length ≤ 104.
//     [input] array.array.integer pairs
//     An array containing pairs of indices that can be swapped in str (1-based). 
//     This means that for each pairs[i], you can swap elements in str that have the indices 
//     pairs[i][0] and pairs[i][1].
//
//     Guaranteed constraints:
//     0 ≤ pairs.length ≤ 5000,
//     pairs[i].length = 2.

//     [output] string




std::string swapLexOrder(std::string str, std::vector<std::vector<int>> pairs) {
    vector<bool> visited(str.size(),false);
    vector<set<int>> edge(str.size(),set<int>());
    for(int i=0;i<pairs.size();i++){
        edge[pairs[i][0]-1].insert(pairs[i][1]-1);
        edge[pairs[i][1]-1].insert(pairs[i][0]-1);
    }
    bool allExplore = true;
    do{
        int init=-1;
        for(int i=0;i<visited.size();i++){
            if(!visited[i]){
                if(edge[i].size()!=0){
                    init=i;
                    allExplore=false;
                    break;
                }else
                    visited[i]=true;
            }
        }
        if(init==-1)//when we have visited all the nodes
            break;
       //looks like bfs
        vector<int> toBeVisited{init};
        vector<int> position;
        vector<char> letters;
        while(toBeVisited.size()!=0){
            vector<int> tmp;
            for(int i=0;i<toBeVisited.size();i++){
                int cur=toBeVisited[i];
                if(!visited[cur]){
                    visited[cur]=true;
                    position.push_back(cur);//pushing all possible switches in positions we can make 
                    letters.push_back(str[cur]);//pushing all possible letters we can switch to
                    for(set<int>::iterator it=edge[cur].begin();it!=edge[cur].end();it++){
                        if(!visited[*it])
                            tmp.push_back(*it);
                    }
                }
            }
            toBeVisited=tmp;
        }
        
        sort(position.begin(),position.end());
        sort(letters.begin(),letters.end());
        
        for(int i=0;i<position.size();i++){
            str[position[i]]=letters[position.size()-1-i];
        }
    }while(!allExplore);
    return str;
}