struct ListNode{
	int val;
	ListNode *next;
	ListNode(int x):val(x), next(nullptr) {}
};

    void helper(ListNode*left, ListNode*&right, int half, int len) {
        if(half==1) {
            if(len%2==0) {
                left->next = right;
                right = right->next;
                left->next->next = nullptr;
            }else {
                ListNode *new_right = right->next;
                right->next = left->next;
                left->next = right;
                right->next->next=nullptr;
                right = new_right;
            }
            return;
        }
				// Note that --half would return the decremented value but
				// half-- would return the value before decrement
        helper(left->next, right, --half, len);
        ListNode *next = left->next;
        left->next = right; 
        ListNode *new_right = right->next;
        right->next = next;
        right = new_right;
        
    }
    void reorderList(ListNode *head) {
        if(head==nullptr || head->next==nullptr) return;
        int len = 0;
        ListNode *curr = head;
        while(curr!=nullptr) { curr = curr->next; len++; }
        int half = (len+1)/2;
        ListNode *right=head;
        while(half>0) {right = right->next;half--;}
        ListNode *left = head;
        helper(left, right, len/2, len);
        return ;
    }
