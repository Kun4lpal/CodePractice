ListNode* deleteDuplicates(ListNode* head) {
        if(head==NULL) return NULL;
        if(head->next == NULL) return head;
        ListNode* temp1 = head;
        ListNode* temp2 = head->next;
       while(temp2){
           if(temp1->val==temp2->val){
               temp1->next = temp2->next;
               temp2 = temp2->next;
           }else{
               temp2 = temp2->next;
               temp1= temp1->next;
           }
       }
       return head;
}