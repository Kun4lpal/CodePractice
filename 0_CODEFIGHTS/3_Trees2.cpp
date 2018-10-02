//<-------------------------------------------------------------------------------------------------------->
// Restore tree from preorder and inorder

Tree<int>* helper(vector<int>& preorder,int i,int j,vector<int>& inorder,int ii,int jj){
        if(i >= j || ii >= j)
            return NULL;

        int mid = preorder[i];
        auto f = find(inorder.begin() + ii,inorder.begin() + jj,mid);
        int dis = f - inorder.begin() - ii;
    
        Tree<int>* root = new Tree<int>(mid);
        root -> left = helper(preorder,i + 1,i + 1 + dis,inorder,ii,ii + dis);
        root -> right = helper(preorder,i + 1 + dis,j,inorder,ii + dis + 1,jj);
        return root;
}

Tree<int> * restoreBinaryTree(std::vector<int> inorder, std::vector<int> preorder) {
    return helper(preorder,0,preorder.size(),inorder,0,inorder.size());    
}
//<-------------------------------------------------------------------------------------------------------->

// You have two arrays of strings, words and parts. Return an array that contains the strings from words, 
// modified so that any occurrences of the substrings from parts are surrounded by square brackets [],
// following these guidelines:

// If several parts substrings occur in one string in words, choose the longest one. 
// If there is still more than one such part, then choose the one that appears first in the string.

// Example

// For words = ["Apple", "Melon", "Orange", "Watermelon"] and parts = ["a", "mel", "lon", "el", "An"], the output should be
// findSubstrings(words, parts) = ["Apple", "Me[lon]", "Or[a]nge", "Water[mel]on"].

// While "Watermelon" contains three substrings from the parts array, "a", "mel", and "lon", "mel" 
// is the longest substring that appears first in the string.

// 0 ≤ parts.length ≤ 105,
// 1 ≤ parts[i].length ≤ 5

std::vector<std::string> findSubstrings(std::vector<std::string> words, std::vector<std::string> parts) {
    set<string> ms[6]; // this is an array of hashSets according to size();
    for(int i=0;i<parts.size();i++)
        ms[parts[i].size()].insert(parts[i]);
    vector<string> ans;
    for(int i=0;i<words.size();i++){
        bool ok = false;
        for(int j=5;j>0 && !ok;j--){
            for(int l=0;l<= words[i].size()-j && !ok;l++){//here we are iterating only till => word[i].size()-j
                string s = words[i].substr(l,j);
                if(ms[j].find(s)!=ms[j].end()){
                    ans.push_back(words[i].substr(0,l)+"["+s+"]"+words[i].substr(l+j));
                    ok = true;
                }
            }
        }
        if(!ok) ans.push_back(words[i]);
    }
    return ans;
}


//<-------------------------------------------------------------------------------------------------------->

// A tree is considered a binary search tree (BST) if for each of its nodes the following is true:

//     The left subtree of a node contains only nodes with keys less than the node's key.
//     The right subtree of a node contains only nodes with keys greater than the node's key.
//     Both the left and the right subtrees must also be binary search trees.

// Removing a value x from a BST t is done in the following way:

//     If there is no x in t, nothing happens;
//     Otherwise, let t' be a subtree of t such that t'.value = x.
//         If t' has a left subtree, remove the rightmost node from it and put it at the root of t';
//         Otherwise, remove the root of t' and its right subtree becomes the new t's root.



Tree<int> min(Tree<int> x){
      while(x.left != null) {
         x = x.left;
      }
      return x;
}

Tree<int> max(Tree<int> x){
      while(x.right != null) {
         x = x.right;
      }
      return x;
}

Tree<int> delMin(Tree<int> x) {
      if(x.left == null) {
         return x.right;
      }
      x.left = delMin(x.left);
      return x;
}

Tree<int> delMax(Tree<int> x) {
      if(x.right == null) {
         return x.left;
      }
      x.right = delMax(x.right);
      return x;
}


Tree<int> deleteFromBST2(Tree<int> t, int key){    
     if(t == null) {
         return null;
      }
      if(t.value == key) {
         if(t.left == null) {
            return t.right;
         } else {
            Tree<int> m = max(t.left);
            m.left = delMax(t.left);
            m.right = t.right;
            return m;
         }
      } else {
         t.left = deleteFromBST2(t.left, key);
         t.right = deleteFromBST2(t.right, key);
      }

return t;
}

Tree<int> deleteFromBST(Tree<int> t, int[] queries) {
    if(t==null){
        return null;
    }
    for(int i=0;i<queries.Length;i++){        
        t = deleteFromBST2(t,queries[i]);
    }
    return t;
}

