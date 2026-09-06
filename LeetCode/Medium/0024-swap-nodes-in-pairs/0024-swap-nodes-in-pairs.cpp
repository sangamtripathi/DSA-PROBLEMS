/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (!head || !head->next) {
            return head;
        }
        ListNode* temp = head;

        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        ListNode* prev = dummy;

        while (temp && temp->next) {
            prev->next = temp->next;

            ListNode* nextnode = temp->next->next;

            temp->next->next = temp;
            temp->next = nextnode;

            prev = temp;
            temp = nextnode;
        }
        ListNode* result = dummy->next;
        delete dummy;
        return result;
    }
};