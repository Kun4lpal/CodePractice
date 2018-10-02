//q1) 

//Directed graph route between two nodes
//this enum belongs to the Node itself
enum State {Unvisited, Visited, Visiting;}

bool checkRoute(Graph g, Node* t1, Node*t2){
	//do bfs and check if current node is equal to t2;
	if(t1==t2){return true;}
	for(v:g){v.State = State.Unvisited;}
	t1.State = State.Visiting;
	q.add(t1);	
	while(!q.size()){
		Node* curr = q.top();q.pop();		
		for(Node* v:curr.adjacent()){
			if(v.State == State.Unvisited){
				if(v==end){return true;}
				v.State = State.Visiting;
				q.add(v);
			}
		}
		curr.state = State.Visited;
	}
}

 	myqueue.push (myint);
 	myqueue.empty();
    myqueue.front();
    myqueue.pop()

//q2) 
//given a sorted array create a BST;

Tree<int>* buildTree(vector<int> arr,int l, int r){
	int mid = (l+r)/2;
	Tree<int>* root = new Tree<int>(mid);
	root->left = buildTree(arr,0,m);
	root->right = buildTree(arr,m,r);
	return root;
}


//q3)

vector<vector<int>> createLevelList(Tree<int>* root){
	//do bfs
	//for dfs=?   createLists(result,temp,root,0);
}


//q4) 

int getHeight(Tree<int>* root){
	if(root==NULL) return -1;
	return max(getHeight(root->left),getHeight(root->right))+1;
}

int checkHeight(Tree<int>* root){
	if(root = NULL) return -1;
	int lh = checkHeight(root->left);
	if(lh == INT_MIN){return INT_MIN;}

	int rh = checkHeight(root->right);
	if(rh == INT_MIN){return INT_MIN;}

	int diff = abs(lh-rh);
	if(diff>1){
		return INT_MIN;
	}else{
		return max(lh,rh)+1;
	}
}

int checkBalanced(Tree<int>* root){
	return checkHeight(root)!=INT_MIN;
}

//q5 validate bst
//build inorder array and check if its sorted

bool checkBST(Tree<int>* root){
	return check(root,NULL,NULL);
}

bool check(Tree<int>* root, int min, int max){
	if(root==NULL){return true;}
	if(min!=NULL && root->value<=min || max!=NULL && root->value>max){
		return false;
	}
	if(!check(root->left,min,root->value) || !check(root->right, root->value,max)){return false;}
	return true;
}

//q6 In order successor
Tree<int>* inOrderSuccessor(Tree<int>* root){
	if(root == NULL) return NULL;
	if(root->right!=NULL){
		return leftMostChild(root->right);
	}else{
		Tree<int> *curr = root;
		Tree<int> *p = curr->parent;		
		while(p->left!=curr){
			curr = p;
			p = p->parent;			
		}
	}
	return p;
}

//q7 buildOrder
string buildOrder(vector<string> list){
	map<char,std::vector<char>> g;
	for(auto it:list){
		g[it[1]].push_back(it[3]); //(a,b)
	}
	char c = map.begin().first;
	return findOrder(g,c);
}

string findOrder(map<char,std::vector<char>> &g, char current){
	string ss = "";
	if(!map[current].size()){
		ss+=current;
		recalibrate(map,current); //remove current from map;
	}else{
		for(auto it: g[current]){
			ss+=findOrder(g,it);
		}
	}
}

//--------------------------------------------------------------------------------------------------

stack<char> orderProjects(std::vector<char> projects){
	stack<char> s;
	for(auto p: projects){
		if(p.getState()==state.BLANK){
			if(!dfs(p,s)){return NULL;}
		}
	}
	return s;
}

bool dfs(char p, stack<int> s){
	if(p.getState == state.Parital){return false;//CYCLE}
	if(p.getState == state.BLANK){
		p.setState = state.Parital;
		for(auto child:p){
			if(!dfs(child,s)){return false;}
		}
		p.setState(state.Complete);// THE lowert level will be the one whose state will be completed first
		s.push(p);
	}
	return true;
}

//--------------------------------------------------------------------------------------------------

// q8) find common ancestor

// classic way is to check if root covers p and q then check if p and q are on opposite side, if true return root

Tree<int>* commonAncestor(Tree<int>* root,Tree<int>* p, Tree<int>* q){
	if(root == NULL) return new Result(NULL,false);
	if(root == p && root==q){return new Result(root,true);}

	Result x = commonAncestor(root->left,p,q);
	if(x.isAncestor){return x;}

	Result y = commonAncestor(root->right,p,q);
	if(y.isAncestor){return y;}

	// x is null if p or q is not found on left same with y on right
	if(x.node!=NULL && y.node!=NULL){ // both are not null and each side has p or a q
		return new Result(root,true);
	}else if(root == p || root==q){ // 
		bool isAncestor = (x.node!=NULL) || (y.node!=NULL);
		return new Result(root,isAncestor);
	}
	return new Result(x.node!=NULL?x.node:y.node,false);//return the non null value
}





//10 check subtree

//11 Extract Random Node

Tree<int>* getRandomNode(Tree<int>* head){
	int i = rand()%100;
	return getNumber(head,i);
}

Tree<int>* getNumber(Tree<int>* head, int i){
	int ls = size(head->left);
	if(ls>i){
		return getNumber(head->left,i);
	}else if(i==ls){
		return head;
	}else{
		return getNumber(head->right,i);
	}
}


//12  Count paths with sum;


int countPathsWithSUm(Tree<int>* root,int target, int curr, unordered_map<int,int> pc){
	if(root == NULL) return 0;
	
	curr+=root->value;
	int sum = curr-target;
	int result = pc[sum];
	if(curr==target){
		result++;
	} 

	pc[curr]++;
	result += countPathsWithSUm(root->left,target,curr,pc);
	result += countPathsWithSUm(root->right,target,curr,pc);
	pc[curr]--;
	return result;
}