// Things to note for this problem:
// 1) empty case length==0
// 2) remember to move head pointer one place later for length==1 sort
  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };
    ListNode *merge(ListNode *left, ListNode *right) {
        ListNode *dummy = new ListNode (INT_MIN);
        ListNode *curr = dummy;
        while(left!=nullptr&&right!=nullptr) {
            if(left->val<right->val) {
                curr->next=left;
                left = left->next;
            }else{
                curr->next = right;
                right = right->next;
            }
            curr=curr->next;
            curr->next =nullptr;
        }
        if(left!=nullptr) {
            curr->next = left;
        }
        if(right!=nullptr) {
            curr->next = right;
        }
        curr = dummy->next;
        delete dummy;
        return curr;
    }


    ListNode *mergeSort(ListNode *&head, int length) {
        if(length==0) return nullptr;
        if(length==1) {
            ListNode *newhead = head;
            head = head->next;
            newhead->next = nullptr;
            return newhead;
        }
        int left_length = length/2;
        int right_length = length - left_length;
        ListNode *left = mergeSort(head, left_length);
        ListNode *right = mergeSort(head, right_length);
        return merge(left, right);
    }
    ListNode *sortList(ListNode *head) {
        ListNode *cur = head;
        int length = 0;
        while(cur!=nullptr) { cur=cur->next; length++;}
        ListNode *result = mergeSort(head, length);
        return result;
    }


