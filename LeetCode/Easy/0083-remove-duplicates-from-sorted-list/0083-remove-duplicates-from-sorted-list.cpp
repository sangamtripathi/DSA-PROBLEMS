class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head || !head->next) {
            return head;
        }

        ListNode* curr = head;

        while (curr && curr->next) {
            if (curr->val == curr->next->val) {
                ListNode* duplicate = curr->next;
                curr->next = curr->next->next; 
                delete duplicate; 
            } else {
                curr = curr->next;
            }
        }

        return head;
    }
};