//1
// if no extra memory allowed we have to iterate n times
Node* removeDups(Node* head){
	map<int> m;
	Node* first = head;
	Node* prev = new Node();
	prev->next = head;
	while(head!=NULL){
		if(m.find(head->value)!=m.end()){
			prev->next = prev->next->next;	
		}
		m[head->value]++;
		prev= prev->next;
		head= head->next;
	}
	return first;
}
//<-------------------------------------------------------------------------------------------------------->
//2 
Node* kthToLast(Node* head){
	Node* slow = head;
	Node* fast = head;
	while(k && slow!=NULL){slow=slow->next;k--;}
	while(slow!=NULL){slow=slow->next;fast=fast->next;}
	return fast;
}
//<-------------------------------------------------------------------------------------------------------->
//3 Delete Middle node 
Node* del(Node* n){
	if(n==NULL || n->next == NULL){
		return false;
	}
	Node *next = n->next;
	n->value = next->value;
	n->next = next->next;
	return true;
}
Node* deleteMiddle(Node* head){	
	Node* slow = new Node();
	slow->next = head;
	Node* fast = head;
	while(fast!=NULL){slow=slow->next;fast=fast->next->next;}		
	slow->next = slow->next->next;
	return head;
}
//<-------------------------------------------------------------------------------------------------------->
//Parition values < k and > k
ListNode* partition(ListNode* head, int x) {
        ListNode* dummyLeft = new ListNode(-1);
        ListNode* dummyRight = new ListNode(-1);
        ListNode* leftCur = dummyLeft;
        ListNode* rightCur = dummyRight;
        while(head != nullptr){
            if(head->val < x){
                leftCur->next=head;
                leftCur=leftCur->next;
            }
            else{
                rightCur->next=head;
                rightCur=rightCur->next;
            }
            head=head->next;
        }
        leftCur->next=dummyRight->next;
        rightCur->next=nullptr;             //Very important line
        return dummyLeft->next;        
}
//<-------------------------------------------------------------------------------------------------------->
// add two large numbers
Node* sumLists(Node* one, Node* two){
	reverse(one);reverse(two);
	Node* result = NULL;
	Node* temp = result;
	int sum = 0, carry = 0;
	while(one!=NULL and two!=NULL){
		sum = one->value + two->value;
		curr = sum%10 + carry;
		result->next = new Node(sum + carry);
		carry = sum/10;		
	}
	return temp->next;
}
//<-------------------------------------------------------------------------------------------------------->
// Palindrome
bool checkPalindrome(Node* head){
	//iterate and count odds
	//iterate to middle and reverse then compare from start and mid nodes
	//or use a stack until you reach middle then start popping and compare with the rest
}
//<-------------------------------------------------------------------------------------------------------->
// intersection of 2 lists
bool checkIntersection(Node* head1, Node* head2){
	int l1 = findLenght(head1);
	int l2 = findLenght(head2);
	int diff = abs(l2-l1);
	while(head2!=NULL && diff){
		head2=head2->next;
		diff--;
	}
	while(head2 && head1){
		if(head1 == head2){
			return true;
		}
		head1 = head1->next;
		head2 = head2->next;
	}
	return false;
} 
//<-------------------------------------------------------------------------------------------------------->
//8 Loop detection:
// Rule 1: When slow just enters the loop, fast is k steps ahead and loopSize-k behind the 
// slow one if slow has taken k steps

slow and fast collide after k + loop-k steps. // now fast and slow are k step from start of the loop

// Rule 2: They collide after at loopSize-k b4 the start of the loop. This means that both
// collision point is k steps from start of loop and headnode is k steps from start of loop
bool findLoop(Node* head){
	Node* slow = head;
	Node* fast = head;
	while(fast && slow && fast!=slow){slow=slow->next;fast=fast->next->next;}		
	if(fast == NULL) return false
	//finding intersection		
	
	slow = head;
	while(fast && slow && fast!=slow){slow=slow->next;fast=fast->next;}		
	return slow;
}
