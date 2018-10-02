
//1 remove value K from list
ListNode<int> * removeKFromList(ListNode<int> * l, int k) {
    if (l == nullptr) return nullptr;
    l->next = removeKFromList(l->next, k);
    if (l->value == k) return l->next;
    return l;
}


//2 check Palindrome
//Other solution is to iterate to half of the list and then compare with it's reverse
//or use a stack
ListNode<int> * p;

bool Rec(ListNode<int> * r) {
    if (r == nullptr) return true;
    bool t = Rec(r->next);
    if (t == false) return false;
    int cur;
    cur = p->value;
    p = p->next;
    return (cur == r->value);
}

bool isListPalindrome(ListNode<int> * l) {
    p = l;
    return Rec(l);
}


// 3 Add two huge numbers
//////////////////////////////////////////////////////////////////////////////////////////
ListNode<int>* reverse(ListNode<int>* l) {
    ListNode<int>* prev = nullptr;
    while (l) {
        ListNode<int>* next = l->next;
        l->next = prev;
        prev = l;
        l = next;
    }
    return prev;
}
// 7 6 5 4
// 3 2 1

ListNode<int>* addTwoHugeNumbers(ListNode<int>* a, ListNode<int>* b) {
    const int maxValue = 10'000;
    a = reverse(a);
    b = reverse(b);
    ListNode<int>* result;
    int carry = 0;
    while (a || b || carry) {
        int sum = carry;
        if (a) {
            sum += a->value;
            a = a->next;
        }
        if (b) {
            sum += b->value;
            b = b->next;
        }
        carry = sum / maxValue;
        sum %= maxValue;
        ListNode<int>* start = new ListNode<int>(sum);
        start->next = result;
        result = start;
    }
    return result;
}


//////////////////////////////////////////////////////////////////////////////////////////

//4 ReverseNodesInKGroups
ListNode<int> reverseNodesInKGroups(ListNode<int> l, int k) {        
    ListNode<int> p = l;
    ListNode<int> q = l;
    ListNode<int> *res = new ListNode<int>();
    ListNode<int> x = res;
    bool check = false;
    while(p!=null && q!=null){  //two pointers p and q, move p k steps reverse using q. 
        int t1 = k;
        while(t1!=0 && p!=null){            
            p = p.next;
            t1--;
        }        
        if(t1==0){       
            q = rev(q,null,k);// q is just a k length linked list in 'reversed form'
            res.next = q; // res is used here so that we can connect q with the prev values after reversal
            int t2 = k;
            while(t2!=0 && res!=null){
                res = res.next;
                t2--;
            }
            while(q.next!=null){
                q=q.next;
            }        
            q.next = p;// iterate q k steps forward and attach it to p
            q = q.next;
        }
    }
    return x!=null?x.next:null;
}

ListNode<int> rev(ListNode<int> l, ListNode<int> temp, int k){
    if(l==null || k==0)
        return temp;
    ListNode<int> nex = l.next;
    l.next = temp;
    return rev(nex,l,k-1);
}



/////////////////////////////////////////////////////////////////////////////////
// Rearrange such that last N elements are at the front 
ListNode<int> * rearrangeLastN(ListNode<int> * l, int n) {
    ListNode<int>* trailer = l;//
    ListNode<int>* ptr = l;
    for(int i = 0; i < n; i++){
        ptr = ptr->next; 
    }
    
    if(n == 0 || ptr == NULL)
        return l;
    
    while(ptr->next){
        ptr = ptr->next;
        trailer = trailer->next;// reach last nth node
    }
    ListNode<int>* result = trailer->next;// result is temp which points to kth node from last  
    trailer->next = NULL;// remove the last k elements from l=> trailer is pointing to the the n-k-1th element
    ptr->next = l;// ptr is the last element and we make it point to l now
    return result;
}