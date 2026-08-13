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
    ListNode* Reverse(ListNode* head) {
        ListNode* Newhead = head;
        ListNode* prev = nullptr;
        while (Newhead) {
            ListNode* next_node = Newhead->next;
            Newhead->next = prev;
            prev = Newhead;
            Newhead = next_node;
        }
        return prev;
    }
    bool isPalindrome(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return true;
        }
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast->next != nullptr && fast->next->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* NewHead = Reverse(slow->next);
        ListNode* first = head;
        ListNode* second = NewHead;

        while (second) {
            if (first->val != second->val) {
                slow->next = Reverse(NewHead);
                return false;
            }
            second = second->next;
            first = first->next;
        }
        slow->next = Reverse(NewHead);
        return true;
    }
};