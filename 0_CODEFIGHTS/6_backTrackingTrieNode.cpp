class TrieNode{
public:
    vector<TrieNode*> next = vector<TrieNode*>(26,NULL);
    string word = "NULL";
};

std::vector<std::string> wordBoggle(std::vector<std::vector<char>> board, std::vector<std::string> words) {    
    vector<string> result;
    TrieNode *root = buildTrie(words);
    for(int i=0;i<board.size();i++){
        for(int j=0;j<board[0].size();j++){
            dfs(board,i,j,root,result);
        }
    }
    sort(result.begin(),result.end());
    return result;
}

void dfs(std::vector<std::vector<char>> &board, int i, int j, TrieNode* p, vector<string> &res) {
    char c = (char)board[i][j];
    if (c == '#' || p->next[(int)(c - 'A')] == NULL) 
        return;
    p = p->next[(int)(c - 'A')];
    if (p->word != "NULL") {   // found one
        res.push_back(p->word);
        p->word = "NULL";     // de-duplicate
    }    
    board[i][j] = '#';    //making sure to make visited in this dfs search so that no repitions
    //can move to any of the 8 neighbours
    if (i > 0) dfs(board, i - 1, j ,p, res); 
    if (i > 0 && j>0) dfs(board, i - 1, j-1 ,p, res); 
    if (i > 0 && (j<board[0].size()-1)) dfs(board, i - 1, j+1 ,p, res);         
    if (j > 0) dfs(board, i, j - 1, p, res);        
    if (j < board[0].size() - 1) dfs(board, i, j + 1, p, res);     
    if (i < board.size() - 1) dfs(board, i + 1, j, p, res); 
    if (i < board.size() - 1 && (j<board[0].size()-1)) dfs(board, i + 1, j+1, p, res); 
    if (i < board.size() - 1 && j>0) dfs(board, i + 1, j-1, p, res);     
    board[i][j] = c;
}


TrieNode* buildTrie(vector<string> &words){
    TrieNode* root = new TrieNode();
    for(auto it:words){
        TrieNode* p = root;
        for(auto c:it){
            int i = (int) (c-'A');
            if(p->next[i] == NULL){
                p->next[i] = new TrieNode();
            }
            p = p->next[i];
        }
        p->word = it;
    }
    return root;
}

