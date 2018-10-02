//<-------------------------------------------------------------------------------------------------------------->
//traverse tree - level-order traversal
vector<int> bfs(Tree<int> *root){
	vector<int> res;
	queue<Tree<int>*> q;
	q.push(root);
	while(q.size()){
		Tree<int> *curr = q.top();
		q.pop();
		res.push_back(curr->value);
		if(curr->left!=NULL) q.push(curr->left);
		if(curr->right!=NULL) q.push(curr->right);
	}
	return res;
}
//<-------------------------------------------------------------------------------------------------------------->
//largest value in each row in tree
vector<int> largest(Tree<int> *root){
	vector<int> res;	
	vector<Tree<int>*> current;
	current.push_back(root);	
	while(current.size()){
		int val = INT_MIN;
		for(auto it:current){
			val = max(it->value);
		}
		res.push_back(val);
		vector<Tree<int>*> parent(current);
		current.clear();
		for(auto it : parent){
			if(curr->left!=NULL) current.push_back(curr->left);
			if(curr->right!=NULL) current.push_back(curr->right);
		}		
	}
	return res;
}

//<-------------------------------------------------------------------------------------------------------------->

// DEPTH FIRST SEARACH EXAMPLE: FIND THE SUMS FROM ROOT TO LEAVES
long digitTreeSum(Tree<int> t) {
    //dfs to leftmost
    //reach top and start new sum    
    return digitTreeSum2(t,0,0);
}

long digitTreeSum2(Tree<int> t, long res, long sum){
    res = res*(long)10+t.value; // res is tracking the sums through the tree 
    if(t.left==null && t.right==null){
        sum+= res;
    }    
    if(t.left!=null)
        sum = digitTreeSum2(t.left,res,sum);    
    if(t.right!=null)
        sum = digitTreeSum2(t.right,res,sum);
    return sum;
}


//<-------------------------------------------------------------------------------------------------------------->
//<-------------------------------------------------------------------------------------------------------------->
//<-------------------------------------------------------------------------------------------------------------->
// LONGEST PATH IN A FILESYSTEM
// "user\n\tpictures\n\t\tphoto.png\n\t\tcamera\n\tdocuments\n\t\tlectures\n\t\t\tnotes.txt" 
struct Node{
    int len;
    int tab;
    bool file;
    std::vector<Node*> children;
    Node(int len,int tab,bool f){
        this->len = len;
        this->tab = tab;
        this->file = f;
    }
};

int dfs(Node * root){
    if(root->file) return root->len;
    int res = 0;
    for(Node* v : root->children){
        int t = dfs(v);// t is the length of longest subtree in v
        if(t > 0){
            res = max(res,t+1+root->len);
        }
    }
    return res;
}

int longestPath(std::string fileSystem) {
    int t = 0,l=0;
    bool f = false;
    int i = 0;
    std::stack<Node*> st;
    std::stack<Node*> parents;
    while(i < fileSystem.size()){
        t = 0;
        l = 0;
        f = false;
        while(fileSystem[i] == '\t') i++,t++;
        cout << i << ' ' << t << '\n';
        while(i < fileSystem.size() && fileSystem[i] != '\f') {
            l++;
            if(fileSystem[i] == '.') f = true;
            i++;
        }
        cout << i << ' ' << t << '\n';
        Node * parent = nullptr;
        while(st.size() > 0 && (st.top())->tab >= t){
            st.pop(); // these are popped when once depth traversal is over we move on the next item which is at upper level
        }
        if(st.size() > 0) parent = st.top();
        Node * node = new Node(l,t,f); // first root created and its the base folder
        if(t==0) parents.push(node);
        if(parent != nullptr) { // if this is the second step it is the child of node at the top of st or new parent
            (parent->children).push_back(node);
        }
        st.push(node); // child are now added to st 
        i++;
    }
    //USING DFS algo to find the max length
    int ans = 0;
    while(!parents.empty()){
        ans = max(ans,dfs(parents.top()));
        parents.pop();
    }
    return ans;
}

//<-------------------------------------------------------------------------------------------------------------->

//SHORTEST PATH IN A GRAPH from s vertice to all the other vertices

vector<int> shortestPath(vector<vector<int>> graph,int V, int s){
	vector<int> dist(V,INT_MAX);
	dist[s]=0;
	vector<bool> visited(V,false);
	for(int v=0;v<V;v++){
		int u = minDistance(dist,visited);//return index/vertex of min distance node in current dist which are not visited
		visited[u] = true;//when we find nearest node we mark it visited so that next time we dont use it
		for(int i=0;i<V;i++){//update all distances
			if(graph[u][i]!=-1 && !visited[i] && dist[u]!=INT_MAX && (dist[u] + graph[u][i] < dist[i]))
				dist[i] = dist[u] + graph[u][i]; //assigning distances if there is a possible path and its lower than prev
		}
	}
	return dist;
}


int minDistance(vector<int> dist, std::vector<bool> visited){
	int min = INT_MAX;
	int minIndex = 0;
	for(int i=0;i<dist.size();i++){
		if(!visited[i] && dist[i]<=min){
			min = dist[i];
			minIndex = i;
		}
	}
	return minIndex;
}


