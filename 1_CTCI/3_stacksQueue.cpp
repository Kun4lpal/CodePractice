//<-------------------------------------------------------------------------------------------------------->
// 1) 
class FixedStack{
	int nStacks;
	int stkCapacity;
	vector<int> values;
	vector<int> sizes;

	FixedStack(int ns, int sc){
		this->nStacks = ns;
		this->stkCapacity = sc;
		values = vector<int>(ns*sc);
		sizes = vector<int>(ns);
	}

	void push(int n){}
	void pop(){}
	void top(){}
	bool isFull(){}
	bool isEmpty(){}
	int indexOfTop(){}
}
//<-------------------------------------------------------------------------------------------------------->
//  2) 
class MutliStack{
	class StackInfo{
		int start,end,size;
		StackInfo(int s,int c){this->start = s; this->c =size;}
	}
	//utility functions like isEmpty, is full, within capacity, first index, last index
	StackInfo si[];
	MutliStack(int sz, int cap, int nStacks){
		si = new StackInfo[nStacks];
		for(int i=0;i<nStacks;i++){si[i] = new StackInfo(sz,cap);}
	}
}
//<-------------------------------------------------------------------------------------------------------->
//3 
class StackMin(){
	stack<int> MinStack,stk;
	void push(int k){
		stk.push(k);
		if(k<MinStack.top()){stk.push(k);}
	}

	void pop(){
		int val = stk.top();
		stk.pop();
		if(val == MinStack.top){
			MinStack.pop();
		}
	}
}
//<-------------------------------------------------------------------------------------------------------->
// Stack of stacks
class stackofStacks(){
	vector<stack<int>*> ss;
	void push(){
		stack<int> *st = getLastStack();
		if(withinCapacity()){st->push(val);}
		else(ss.push_back(new Stack()));
	}
}
//<-------------------------------------------------------------------------------------------------------->
// queue using stack

// use 2 stacks push items from one to the other one.
// pop from the other stack which acts as a queue
//<-------------------------------------------------------------------------------------------------------->
// sort stack
void sort(stack<int> s){
	stack<int> temp;
	// ON2 time
	while(s.size()){
		int val = s.top();
		s.pop();
		while(val<temp.top()){
			int val2 = temp.top();
			s.push(val2); 
			temp.pop();
		}
		temp.push(val);
	}
	while(temp.size()){
		s.push(temp.pop());
	}
}
//<-------------------------------------------------------------------------------------------------------->
// Animal shelter
// each has a number assinged to them and we pop whichever was put in first