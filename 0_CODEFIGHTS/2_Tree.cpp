//<-------------------------------------------------------------------------------------------------------->
// 1 Check if there is a path from root to leaf with the given sum
bool findPath(Tree<int>* t, int target, int current){
    std::cout<<current<<",";
    if(current==target && t->left==NULL && t->right==NULL){
        return true;
    }
    if(t==NULL){
        return false;
    }        
    if((t->left!=NULL && findPath(t->left,target,current+(t->left->value))) || 
       (t->right!=NULL && findPath(t->right,target,current+(t->right->value)))){
        return true;
    }    
    return false;
}

bool hasPathWithGivenSum(Tree<int>* t, int s) {    
    if(t==NULL && s!=0){
        return false;
    }else if(t==NULL && s==0){
        return true;
    }
    return findPath(t,s,t->value);
}
//<-------------------------------------------------------------------------------------------------------->
// 2 Check if tree is symmetric
bool helper(Tree<int>* p, Tree<int>* q) {
        if (!p && !q) {
            return true;
        } else if (!p || !q) {
            return false;
        }
        
        if (p->value != q->value) {
            return false;
        }
        return helper(p->left,q->right) && helper(p->right, q->left); 
}

bool isTreeSymmetric(Tree<int> * root) {
    if(root==NULL){
        return true;
    }
    return helper(root->left, root->right);
}

//<-------------------------------------------------------------------------------------------------------->

std::string findProfession(int level, int pos) {
    if (level == 1)
        return "Engineer"; 
    // Recursively find parent's profession. If parent
    // is a doctar, this node will be a doctal if it is
    // at odd position and an engineer if at even position
    if (findProfession(level-1, (pos+1)/2) == "Doctor") // we did p+1 here because p starts from 1 and                     
        return (pos%2)? "Doctor" : "Engineer";          //   we want child 1 and 2 to correspond to 1 not 0 
    // If parent is an engineer, then current node will be
    // an enginner if at add position and doctor if even
    // position.
    return (pos%2)?  "Engineer" : "Doctor";
}

//<-------------------------------------------------------------------------------------------------------->
void inorder(Tree<int>* t,vector<int> &hl, int k){
    if(t==NULL || hl.size()>k){
        return;
    }
    inorder(t->left,hl,k);    
    hl.push_back(t->value);
    inorder(t->right,hl,k);
}

int kthSmallestInBST(Tree<int> * t, int k) {    
    vector<int> hl;
    inorder(t,hl,k);
    return hl[k-1];
}
//<-------------------------------------------------------------------------------------------------------->
bool isEqual(Tree<int> *t1, Tree<int> *t2){        
    if(t1==NULL && t2==NULL){
        return true;
    }
    if((t1!=NULL) ^ (t2!=NULL)){
        return false;
    }
    if((t1->value == t2->value) && isEqual(t1->left,t2->left) && isEqual(t1->right,t2->right)){
        return true;
    }
    return false;
}

bool isSubtree(Tree<int> *t1, Tree<int> *t2){
    if(t2==NULL){
        return true;
    }
    if(t1==NULL){
        return false;
    }
    queue<Tree<int>*> q;
    q.push(t1);
    while(!q.empty()){
        Tree<int> *top = q.front();
        if(isEqual(top,t2)){
            return true;
        }
        q.pop();
        if(top->left!=NULL){
            q.push(top->left);        
        }
        if(top->right!=NULL){
            q.push(top->right);
        }
    }
    return false;
}