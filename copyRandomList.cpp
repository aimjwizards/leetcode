struct RandomListNode{
	int label;
	RandomListNode *next, *random;
	RandomListNode(int x): label(x), next(nullptr), random(nullptr) {}
};


    RandomListNode *copyRandomList(RandomListNode *head) {
        if (head==nullptr) return nullptr;
        unordered_map<RandomListNode *, RandomListNode *> table;
        RandomListNode *curr = head;
        RandomListNode *newhead = nullptr; 
        RandomListNode *newcurr = nullptr;
        while(curr!=nullptr) {
						// for the first node:
						// 1) update the newhead
						// 2) save the newcurr to link the next node
            if(curr==head) {
                newhead = new RandomListNode(curr->label);
                newcurr = newhead;
                table[curr] = newcurr;
            }
						// for the rest nodes:
						// 1) link to the prev node
						// 2) proceed to the new node
						else{
                newcurr->next = new RandomListNode(curr->label);
                newcurr = newcurr->next;
                table[curr] = newcurr;
            }
						// proceed to the next node in the old linked list
            curr = curr->next;
        }
        newcurr = newhead;
        curr = head;
				// directly copy according to the mapping
        while(curr!=nullptr){
            table[curr]->random=table[curr->random];
            curr=curr->next;
        }
        return newhead;
    }
