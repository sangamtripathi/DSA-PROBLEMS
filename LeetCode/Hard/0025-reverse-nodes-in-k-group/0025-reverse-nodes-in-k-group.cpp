class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head || k == 1) return head;

        // 1. Create a dummy node to handle edge cases gracefully (like the head changing)
        ListNode dummy(0);
        dummy.next = head;
        
        ListNode* prevGroupTail = &dummy;
        ListNode* curr = head;

        while (curr) {
            // 2. Find the k-th node
            ListNode* kthNode = curr;
            int count = 1;
            while (kthNode && count < k) {
                kthNode = kthNode->next;
                count++;
            }

            // If there are less than k nodes left, we are done
            if (!kthNode) break;

            // 3. Keep track of the next group's starting node
            ListNode* nextGroupHead = kthNode->next;
            
            // 4. Isolate the current k-group and reverse it
            kthNode->next = nullptr;
            prevGroupTail->next = reverse(curr);
            
            // 5. Reconnect the reversed group to the rest of the list
            // Note: After reversal, 'curr' is now the tail of this group
            curr->next = nextGroupHead;
            
            // 6. Move pointers forward for the next iteration
            prevGroupTail = curr;
            curr = nextGroupHead;
        }

        // dummy.next naturally points to the new head of the entire list
        return dummy.next;
    }

private:
    // Helper function returns the new head of the reversed list
    ListNode* reverse(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        while (curr) {
            ListNode* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }
        return prev;
    }
};