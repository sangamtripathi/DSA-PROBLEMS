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
    ListNode* merge(ListNode* lefthead, ListNode* righthead) {
        ListNode* dummyNode = new ListNode(-1);
        ListNode* temp = dummyNode;
        while (lefthead != nullptr && righthead != nullptr) {
            if (lefthead->val >= righthead->val) {
                temp->next = righthead;
                temp = righthead;
                righthead = righthead->next;
            } else {
                temp->next = lefthead;
                temp = lefthead;
                lefthead = lefthead->next;
            }
        }
        if (lefthead) {
            temp->next = lefthead;
        } else {
            temp->next = righthead;
        }
        return dummyNode->next;
    }
    ListNode* Middle(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head->next;

        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }
    ListNode* sortList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        ListNode* middle = Middle(head);
        ListNode* righthead = middle->next;
        middle->next = nullptr;
        ListNode* lefthead = head;

        lefthead = sortList(lefthead);
        righthead = sortList(righthead);

        return merge(lefthead, righthead);
    }
};