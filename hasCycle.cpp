struct{
	int val;
	ListNode *next;
	ListNode(int x):val(x),next(nullptr){}
};

    bool hasCycle(ListNode *head) {
        if(head==nullptr || head->next==nullptr) return nullptr;
        
        ListNode *slow = head; 
        ListNode *fast = head;
        while(fast!=nullptr && fast->next!=nullptr) {
            slow = slow->next;
            fast=fast->next->next;
            if(slow==fast) return true;
        }
        return false;
    }
