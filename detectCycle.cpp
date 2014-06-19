struct ListNode{
	int val;
	ListNode *next;
	ListNode(int x):val(x), next(nullptr){}
};


    ListNode *detectCycle(ListNode *head) {
        if(head==nullptr || head->next==nullptr) return nullptr;
        ListNode *slow = head;
        ListNode *fast = head;
     		//try to find the point they meet
		   	while(fast!=nullptr&&fast->next!=nullptr) {
            fast=fast->next->next;
            slow=slow->next;
            if(slow==fast) break;
        } 
				// if there's no cycle, the above while loop would exit with nullptr ending
        if(fast==nullptr||fast->next==nullptr) return nullptr;
				// one pointer starts from where they met
				// the other point starts from the head
				// they continue with the same speed, and they would meet at the starting point of the cycle.
        slow = head;
        while(slow!=fast){
            slow=slow->next;
            fast=fast->next;
        }
        return slow;
    }
