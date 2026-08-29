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
    ListNode* findNode(ListNode* temp, int k) {
        k -= 1; // 0-indexed distance
        while (temp != nullptr && k > 0) {
            k--;
            temp = temp->next;
        }
        return temp;
    }

    // Standard linked list reversal
    void reverse(ListNode* head) {
        ListNode* current = head;
        ListNode* prev = nullptr;
        while (current != nullptr) {
            ListNode* next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;
        ListNode* kthNode = nullptr;
        ListNode* prevNode = nullptr;
        ListNode* NextNode = nullptr;
        while (temp) {
            kthNode = findNode(temp, k);
            if (!kthNode) {
                if (prevNode) {
                    prevNode->next = temp;
                }
                break;
            }

            NextNode = kthNode->next;
            kthNode->next = nullptr;
            reverse(temp);

            if (temp == head) {
                head = kthNode;
            } else {
                prevNode->next = kthNode;
            }

            prevNode = temp;
            temp = NextNode;

            
        }
        return head;
    }
};