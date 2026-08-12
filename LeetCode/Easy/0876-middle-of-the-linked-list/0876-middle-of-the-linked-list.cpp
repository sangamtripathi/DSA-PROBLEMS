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
    ListNode* middleNode(ListNode* head) {
        if (head->next == nullptr) {
            return head;
        }

        ListNode* temp = head;
        ListNode* ans = head;
        int cnt{};
        int ansn{1};

        while (temp) {
            cnt++;
            if (ansn != (cnt / 2) + 1 ) {
                ansn++;
                ans = ans->next;
            }
            temp = temp->next;
        }

        return ans;
    }
};