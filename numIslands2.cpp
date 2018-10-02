

map<long,Node*> map;

class Node{
	int data;
	int rank;
	Node* parent;
};

void makeSet(long data){
	Node* node = new Node();
	node->data = data;
	node->parent = node;
	node->rank = 0;
	map[data] = node;
}

void unionSet(long data1,long data2){
	Node* node1 = map[data1];
	Node* node2 = map[data2];

	Node paren1 = findSet(node1);
	Node paren2 = findSet(node2);

	if(paren1->data == paren2->data){return;}

	if(paren1->rank >= paren2->rank){
		paren1->rank = (paren1->rank==paren2->rank)?paren1->rank+1:paren1->rank;
		paren2->parent = paren1;
	}else{
		paren1->parent = paren2;
	}

}

long findSet(long d){
	return findSet(map[d])->data;
}

Node* findSet(Node *node){
	Node *parent = node->parent;
	if(parent == node){
		return parent;
	}
	node->parent = findSet(node->parent);
	return node->parent;
}



int main(){
	Disjoing set;

	set.makeSet(1);
	set.makeSet(2);
	set.makeSet(3);
	set.makeSet(4);
	set.makeSet(5);
	set.makeSet(6);
	set.makeSet(7);


	set.union(1,2);
	set.union(2,3);
	set.union(4,5);
	set.union(6,7);

	unordered_set<long> vals;
	vals.insert(set.findSet(1));
	vals.insert(set.findSet(2));
	vals.insert(set.findSet(3));
	vals.insert(set.findSet(4));
	vals.insert(set.findSet(5));
	vals.insert(set.findSet(6));
	vals.insert(set.findSet(7));	
	cout<<vals.size()<<endl;
	//this will give the total number of islands.
}