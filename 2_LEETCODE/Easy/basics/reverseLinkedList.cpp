


Node* reverse(Node* head){
	Node* prev = NULL, first = head, curr = head;
	while(first!=NULL){
		first = first->next;
		curr->next = prev;
		prev = curr;
		curr = first;
	}
	return prev;
}