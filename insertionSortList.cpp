  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
 };

    ListNode *insertionSortList(ListNode *head) {
        if(head==nullptr || head->next==nullptr) return head;
        ListNode *newhead = head;
        head = head->next; newhead->next=nullptr;
        while(head!=nullptr) {
            ListNode *curr = newhead;
            ListNode *app = head; head = head->next; app->next = nullptr;
    				// reasons to loop out
						// 1) reaching the end of the list
						// 2) curr->next is bigger ==> curr->next needs to be changed to app
		        while(curr->next!=nullptr&&curr->next->val<app->val) {
                curr = curr->next;
            }
						// case 1: head
						// insert to the head and then swap value based on the comparison
            if(curr==newhead) {
                app->next = newhead;
                newhead = app;
                if(newhead->val>newhead->next->val) {swap(newhead->val, newhead->next->val);}
            }
						// case 2: tail
						// append to the tail and then swap value based on the comparison
						else if (curr->next==nullptr) {
                if(curr->val<app->val) {curr->next = app;}
                else {curr->next=app; swap(curr->val, app->val); }
            }
						// case 3: regular position
						// already found the position, just append as curr's next
            else {
                app->next = curr->next;
                curr->next = app;
            }
        }
        return newhead;
    }
